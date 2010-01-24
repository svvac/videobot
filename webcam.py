#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys
from PyQt4 import QtCore, QtGui
from PyQt4.QtCore import Qt
# Import Camera OpenCV wrapper to easily manage video captures with OpenCV
# This is the home-made module Camera.py
import Camera


class Empty :
    """ Convenience class to handle various objects """
    def __init__(self):
        pass

class MainWindow(QtGui.QMainWindow):
    """ Displays video frames, controls, and other various things """

    def __init__(self):
        """ Initializes window """
        
        # Call parent constructor
        QtGui.QMainWindow.__init__(self)
        
        # Define widget containers
        self.gui = Empty()
        
        # Contains Qt's signals
        self.signals = Empty()
        
        # FPS configuration (unimplemented)
        self.fps = 10
        
        # Easy access to custom Qt's slots
        self.slots = {
            'camChangeHue': QtCore.SLOT('camChangeHue(int)'),
            'camChangeContrast': QtCore.SLOT('camChangeContrast(int)'),
            'camChangeSaturation': QtCore.SLOT('camChangeSaturation(int)'),
            'camChangeBrightness': QtCore.SLOT('camChangeBrightness(int)')
        }
        
        # Set window options
        self.setWindowTitle('VideoBot')
        
        # Builds widgets, bindings and some other init stuff
        self.init()
    
    def init(self):
        # Create widgets
        self.buildGui()
        # Setup logic
        self.buildBindings()
        # Initialize camera
        self.initCam()
    
    def buildGui(self):
        """ Calls GUI's builders (separated to improve code readability) """
        # Defines main namespace
        self.gui.main = Empty()
        
        # Defines the main layout
        self.gui.main.layout = QtGui.QVBoxLayout()
        
        # Create tabs
        self.buildGuiVideo()
        self.buildGuiTabs()
        
        # Includes main layout in a basic widget and add it to MainWindow
        # as the “CentralWidget”
        self.gui.main.container = QtGui.QWidget()
        self.gui.main.container.setLayout(self.gui.main.layout)
        self.setCentralWidget(self.gui.main.container)
    
    def buildGuiVideo(self):
        """ Setup video-related GUI stuff """
        
        # Defines video namespace
        self.gui.video = Empty()
        
        # Creates QLabel where we'll place frames
        self.gui.video.frame = QtGui.QLabel()
        
        # Add the label to the main layout
        self.gui.main.layout.addWidget(self.gui.video.frame)
    
    def buildGuiTabs(self):
        """ Setup bottom tabs """
        
        # Creates tabs namespace
        self.gui.tabs = Empty()
        # Creates the QTab widget
        self.gui.tabs.tabs = QtGui.QTabWidget()
        
        # Populates tabs
        self.buildGuiTabControls()
        self.buildGuiTabImg()
        
        # Add tabs to the main layout
        self.gui.main.layout.addWidget(self.gui.tabs.tabs)
    
    def buildGuiTabImg(self):
        """ Creates image settings controls """
        
        # Creates the tabs.img namespace
        self.gui.tabs.img = Empty()
        
        # Creates the Grid layout and the future blank widget container
        self.gui.tabs.img.layout = QtGui.QGridLayout()
        self.gui.tabs.img.container = QtGui.QWidget()
        
        # Creates hue namespace
        self.gui.tabs.img.hue = Empty()
        # Creates hue slider
        self.gui.tabs.img.hue.slider = QtGui.QSlider(Qt.Horizontal)
        self.gui.tabs.img.hue.slider.setRange(0, 100)
        # Creates hue spinbox
        self.gui.tabs.img.hue.spin = QtGui.QSpinBox()
        self.gui.tabs.img.hue.spin.setRange(0, 100)
        self.gui.tabs.img.hue.spin.setSuffix('%')
        # Add them to the layout
        self.gui.tabs.img.layout.addWidget(QtGui.QLabel('Hue'), 1, 0)
        self.gui.tabs.img.layout.addWidget(self.gui.tabs.img.hue.slider, 1, 1)
        self.gui.tabs.img.layout.addWidget(self.gui.tabs.img.hue.spin, 1, 2)
        
        # Creates contrast namespace
        self.gui.tabs.img.contrast = Empty()
        # Creates contrast slider
        self.gui.tabs.img.contrast.slider = QtGui.QSlider(Qt.Horizontal)
        self.gui.tabs.img.contrast.slider.setMaximum(100)
        # Creates contrast spinbox
        self.gui.tabs.img.contrast.spin = QtGui.QSpinBox()
        self.gui.tabs.img.contrast.spin.setRange(0, 100)
        self.gui.tabs.img.contrast.spin.setSuffix('%')
        # Add them to the layout
        self.gui.tabs.img.layout.addWidget(QtGui.QLabel('Contrast'), 2, 0)
        self.gui.tabs.img.layout.addWidget(self.gui.tabs.img.contrast.slider, 2, 1)
        self.gui.tabs.img.layout.addWidget(self.gui.tabs.img.contrast.spin, 2, 2)
        
        # Creates satutration namespace
        self.gui.tabs.img.saturation = Empty()
        # Creates saturation slider
        self.gui.tabs.img.saturation.slider = QtGui.QSlider(Qt.Horizontal)
        self.gui.tabs.img.saturation.slider.setMaximum(100)
        # Creates saturation spinbox
        self.gui.tabs.img.saturation.spin = QtGui.QSpinBox()
        self.gui.tabs.img.saturation.spin.setRange(0, 100)
        self.gui.tabs.img.saturation.spin.setSuffix('%')
        # Add them to the layout
        self.gui.tabs.img.layout.addWidget(QtGui.QLabel('Saturation'), 3, 0)
        self.gui.tabs.img.layout.addWidget(self.gui.tabs.img.saturation.slider, 3, 1)
        self.gui.tabs.img.layout.addWidget(self.gui.tabs.img.saturation.spin, 3, 2)
        
        # Creates brightness namespace
        self.gui.tabs.img.brightness = Empty()
        # Creates brightness slider
        self.gui.tabs.img.brightness.slider = QtGui.QSlider(Qt.Horizontal)
        self.gui.tabs.img.brightness.slider.setMaximum(100)
        # Creates brightness spinbox
        self.gui.tabs.img.brightness.spin = QtGui.QSpinBox()
        self.gui.tabs.img.brightness.spin.setRange(0, 100)
        self.gui.tabs.img.brightness.spin.setSuffix('%')
        # Add them to the layout
        self.gui.tabs.img.layout.addWidget(QtGui.QLabel('Brightness'), 4, 0)
        self.gui.tabs.img.layout.addWidget(self.gui.tabs.img.brightness.slider, 4, 1)
        self.gui.tabs.img.layout.addWidget(self.gui.tabs.img.brightness.spin, 4, 2)
        
        
        # Add layout to the blank widget container and add it to the tabs layout
        self.gui.tabs.img.container.setLayout(self.gui.tabs.img.layout)
        self.gui.tabs.tabs.addTab(self.gui.tabs.img.container, 'Video settings')
    
    def buildGuiTabControls(self):
        """ Creates the contols tab """
        
        # Creates the tabs.controls namespace
        self.gui.tabs.controls = Empty()
        
        # Creates a layout and a blank widget
        self.gui.tabs.controls.layout = QtGui.QFormLayout()
        self.gui.tabs.controls.container = QtGui.QWidget()
        
        # Add some widgets here...
        
        # Set layout to the container, and add it to the tabs layout
        self.gui.tabs.controls.container.setLayout(self.gui.tabs.controls.layout)
        self.gui.tabs.tabs.addTab(self.gui.tabs.controls.container, 'Controls')
    
    def buildBindings(self):
        """ Connects Qt's signals and slots """
        
        # Setting up hue stuff. Moving slider or changing its value updates
        # cam's settings. Also connects spinbox to the slider to easily
        # configure it.
        self.connect(self.gui.tabs.img.hue.slider,
                        QtCore.SIGNAL('sliderMoved(int)'),
                        self.slots['camChangeHue'])
        self.connect(self.gui.tabs.img.hue.slider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.slots['camChangeHue'])
        self.connect(self.gui.tabs.img.hue.slider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.gui.tabs.img.hue.spin,
                        QtCore.SLOT('setValue(int)'))
        self.connect(self.gui.tabs.img.hue.spin,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.gui.tabs.img.hue.slider,
                        QtCore.SLOT('setValue(int)'))
        
        # Setting up contrast stuff. Moving slider or changing its value updates
        # cam's settings. Also connects spinbox to the slider to easily
        # configure it.
        self.connect(self.gui.tabs.img.contrast.slider,
                        QtCore.SIGNAL('sliderMoved(int)'),
                        self.slots['camChangeContrast'])
        self.connect(self.gui.tabs.img.contrast.slider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.slots['camChangeContrast'])
        self.connect(self.gui.tabs.img.contrast.slider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.gui.tabs.img.contrast.spin,
                        QtCore.SLOT('setValue(int)'))
        self.connect(self.gui.tabs.img.contrast.spin,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.gui.tabs.img.contrast.slider,
                        QtCore.SLOT('setValue(int)'))
        
        # Setting up brightness stuff. Moving slider or changing its value
        # updates cam's settings. Also connects spinbox to the slider to easily
        # configure it.
        self.connect(self.gui.tabs.img.brightness.slider,
                        QtCore.SIGNAL('sliderMoved(int)'),
                        self.slots['camChangeBrightness'])
        self.connect(self.gui.tabs.img.brightness.slider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.slots['camChangeBrightness'])
        self.connect(self.gui.tabs.img.brightness.slider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.gui.tabs.img.brightness.spin,
                        QtCore.SLOT('setValue(int)'))
        self.connect(self.gui.tabs.img.brightness.spin,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.gui.tabs.img.brightness.slider,
                        QtCore.SLOT('setValue(int)'))
        
        # Setting up saturation stuff. Moving slider or changing its value
        # updates cam's settings. Also connects spinbox to the slider to easily
        # configure it.
        self.connect(self.gui.tabs.img.saturation.slider,
                        QtCore.SIGNAL('sliderMoved(int)'),
                        self.slots['camChangeSaturation'])
        self.connect(self.gui.tabs.img.saturation.slider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.slots['camChangeSaturation'])
        self.connect(self.gui.tabs.img.saturation.slider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.gui.tabs.img.saturation.spin,
                        QtCore.SLOT('setValue(int)'))
        self.connect(self.gui.tabs.img.saturation.spin,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.gui.tabs.img.saturation.slider,
                        QtCore.SLOT('setValue(int)'))
        
        # Setting up the timer to periodically retrieve a cam's frame and
        # display it.
        # Interval between two requests is defined by self.fps (see
        # self.__init__)
        self.gui.video.timer = QtCore.QTimer(self)
        self.connect(self.gui.video.timer, QtCore.SIGNAL('timeout()'), self.shot)
        self.gui.video.timer.start(1000 / self.fps)
    
    def initCam(self):
        """ Initializes camera """
        
        # Open camera with Cam OpenCV wrapper
        self.cam = Camera.Cam(-1)
        
        # Immediately grab and display a frame
        self.shot()
        
        # Retrieve cam's HSBC (not the bank) parameters and set them to the
        # matching controls (see self.buildguiTabImg()).
        # Because sliders does only work with integers, we convert decimals
        # values (defined between 0 and 1) to percent. The reverse conversion
        # is done in slots self.camChange*() 
        self.gui.tabs.img.hue.slider.setValue(self.cam.hue() * 100)
        self.gui.tabs.img.contrast.slider.setValue(self.cam.contrast() * 100)
        self.gui.tabs.img.saturation.slider.setValue(self.cam.saturation() * 100)
        self.gui.tabs.img.brightness.slider.setValue(self.cam.brightness() * 100)
    
    
    def shot(self):
        """ Grabs a frame from camera and display it"""
        
        # Because I haven't found any efficient OpenCV → PyQt converter, and
        # because properly “translating” IPLImages to QPixmaps pixel by pixel
        # heavily unefficient, we simply write frames to a temporary JPEG file
        # and re-open it with Qt.
        
        # Grabs a frame and save it in the temp JPEG file
        self.cam.save('.frame.tmp.jpg')
        # Opens the temp image, convert it into a QPixmap, and display it in the
        # label created on self.builGuiVideo()
        self.gui.video.frame.setPixmap(QtGui.QPixmap.fromImage(QtGui.QImage('.frame.tmp.jpg')))
    
    @QtCore.pyqtSlot()
    def saveFrame(self):
        """ Allows user to save a frame as a image (This is also a PyQt slot) """
        # Needs to be completed
        
        # Ask the user for the destination file
        dest = QtGui.QFileDialog.getSaveFileName(self, "Save frame as...", '', 'Images (*.png *.gif *.jpg *.jpeg)')
        # Grab and save a frame in the given file
        self.cam.save(str(dest))
    
    @QtCore.pyqtSlot(int)
    def camChangeHue(self, value):
        """ Sets cam's hue value in percent (This is also a PyQt slot) """
        # Because QSliders does not work with decimal values, we use percent
        # instead. So we need to get a float between 0 and 1 then we set the
        # value
        self.cam.setHue(value / 100.0)
    
    @QtCore.pyqtSlot(int)
    def camChangeContrast(self, value):
        """ Sets cam's contrast value in percent (This is also a PyQt slot) """
        # Because QSliders does not work with decimal values, we use percent
        # instead. So we need to get a float between 0 and 1 then we set the
        # value
        self.cam.setContrast(value / 100.0)
    
    @QtCore.pyqtSlot(int)
    def camChangeSaturation(self, value):
        """ Sets cam's saturation value in percent (This is also a PyQt slot) """
        # Because QSliders does not work with decimal values, we use percent
        # instead. So we need to get a float between 0 and 1 then we set the
        # value
        self.cam.setSaturation(value / 100.0)
    
    @QtCore.pyqtSlot(int)
    def camChangeBrightness(self, value):
        """ Sets cam's brightness value in percent (This is also a PyQt slot) """
        # Because QSliders does not work with decimal values, we use percent
        # instead. So we need to get a float between 0 and 1 then we set the
        # value
        self.cam.setBrightness(value / 100.0)
        
    



if  __name__ == '__main__' :
    # Initialize application
    app = QtGui.QApplication(sys.argv)
    app.setApplicationName("camview")
    
    # Instanciate the main window and display it
    main = MainWindow()
    main.show()
    
    # Runs application
    sys.exit(app.exec_())

