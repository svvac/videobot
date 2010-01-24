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
        self.e = Empty()
        
        # Contains Qt's signals
        self.signals = Empty()
        
        # FPS configuration (unimplemented)
        self.fps = 10
        
        # Easy access to custom Qt's slots
        self.slots = {
            'camChangeHue': QtCore.SLOT('camChangeHue(int)'),
            'camChangeContrast': QtCore.SLOT('camChangeContrast(int)'),
            'camChangeSaturation': QtCore.SLOT('camChangeSaturation(int)'),
            'camChangeBrightness': QtCore.SLOT('camChangeBrightness(int)'),
            'camChangeFps': QtCore.SLOT('camChangeFps(int)')
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
        
        # Defines the main layout
        self.e.lMain = QtGui.QVBoxLayout()
        
        # Create tabs
        self.buildGuiVideo()
        self.buildGuiTabs()
        
        # Includes main layout in a basic widget and add it to MainWindow
        # as the “CentralWidget”
        self.e.wMainContainer = QtGui.QWidget()
        self.e.wMainContainer.setLayout(self.e.lMain)
        self.setCentralWidget(self.e.wMainContainer)
    
    def buildGuiVideo(self):
        """ Setup video-related GUI stuff """
        
        # Creates QLabel where we'll place frames
        self.e.labelFrame = QtGui.QLabel()
        #self.e.labelFrame.setScaledContents(True)   # Useless
        
        # Add the label to the main layout
        self.e.lMain.addWidget(self.e.labelFrame)
    
    def buildGuiTabs(self):
        """ Setup bottom tabs """
        
        # Creates the QTab widget
        self.e.wTabs = QtGui.QTabWidget()
        
        # Populates tabs
        self.buildGuiTabControls()
        self.buildGuiTabImg()
        
        # Add tabs to the main layout
        self.e.lMain.addWidget(self.e.wTabs)
    
    def buildGuiTabImg(self):
        """ Creates image settings controls """
        
        # Creates the Grid layout and the future blank widget container
        self.e.lTabImg = QtGui.QGridLayout()
        self.e.wTabImgContainer = QtGui.QWidget()
        
        # Creates hue slider
        self.e.fHueSlider = QtGui.QSlider(Qt.Horizontal)
        self.e.fHueSlider.setMaximum(100)
        # Creates hue spinbox
        self.e.fHueSpin = QtGui.QSpinBox()
        self.e.fHueSpin.setRange(0, 100)
        self.e.fHueSpin.setSuffix('%')
        # Add them to the layout
        self.e.lTabImg.addWidget(QtGui.QLabel('Hue'), 1, 0)
        self.e.lTabImg.addWidget(self.e.fHueSlider, 1, 1)
        self.e.lTabImg.addWidget(self.e.fHueSpin, 1, 2)
        
        # Creates contrast slider
        self.e.fContrastSlider = QtGui.QSlider(Qt.Horizontal)
        self.e.fContrastSlider.setMaximum(100)
        # Creates contrast spinbox
        self.e.fContrastSpin = QtGui.QSpinBox()
        self.e.fContrastSpin.setRange(0, 100)
        self.e.fContrastSpin.setSuffix('%')
        # Add them to the layout
        self.e.lTabImg.addWidget(QtGui.QLabel('Contrast'), 2, 0)
        self.e.lTabImg.addWidget(self.e.fContrastSlider, 2, 1)
        self.e.lTabImg.addWidget(self.e.fContrastSpin, 2, 2)
        
        # Creates saturation slider
        self.e.fSaturationSlider = QtGui.QSlider(Qt.Horizontal)
        self.e.fSaturationSlider.setMaximum(100)
        # Creates saturation spinbox
        self.e.fSaturationSpin = QtGui.QSpinBox()
        self.e.fSaturationSpin.setRange(0, 100)
        self.e.fSaturationSpin.setSuffix('%')
        # Add them to the layout
        self.e.lTabImg.addWidget(QtGui.QLabel('Saturation'), 3, 0)
        self.e.lTabImg.addWidget(self.e.fSaturationSlider, 3, 1)
        self.e.lTabImg.addWidget(self.e.fSaturationSpin, 3, 2)
        
        # Creates brightness slider
        self.e.fBrightnessSlider = QtGui.QSlider(Qt.Horizontal)
        self.e.fBrightnessSlider.setMaximum(100)
        # Creates brightness spinbox
        self.e.fBrightnessSpin = QtGui.QSpinBox()
        self.e.fBrightnessSpin.setRange(0, 100)
        self.e.fBrightnessSpin.setSuffix('%')
        # Add them to the layout
        self.e.lTabImg.addWidget(QtGui.QLabel('Brightness'), 4, 0)
        self.e.lTabImg.addWidget(self.e.fBrightnessSlider, 4, 1)
        self.e.lTabImg.addWidget(self.e.fBrightnessSpin, 4, 2)
        
        
        # Add layout to the blank widget container and add it to the tabs layout
        self.e.wTabImgContainer.setLayout(self.e.lTabImg)
        self.e.wTabs.addTab(self.e.wTabImgContainer, 'Video settings')
    
    def buildGuiTabControls(self):
        """ Creates the contols tab """
        
        # Creates a layout and a blank widget
        self.e.lTabControls = QtGui.QFormLayout()
        self.e.wTabControlsContainer = QtGui.QWidget()
        
        # Add some widgets here...
        
        # Set layout to the container, and add it to the tabs layout
        self.e.wTabControlsContainer.setLayout(self.e.lTabControls)
        self.e.wTabs.addTab(self.e.wTabControlsContainer, 'Controls')
    
    def buildBindings(self):
        """ Connects Qt's signals and slots """
        
        # Setting up hue stuff. Moving slider or changing its value updates
        # cam's settings. Also connects spinbox to the slider to easily
        # configure it.
        self.connect(self.e.fHueSlider,
                        QtCore.SIGNAL('sliderMoved(int)'),
                        self.slots['camChangeHue'])
        self.connect(self.e.fHueSlider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.slots['camChangeHue'])
        self.connect(self.e.fHueSlider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.e.fHueSpin,
                        QtCore.SLOT('setValue(int)'))
        self.connect(self.e.fHueSpin,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.e.fHueSlider,
                        QtCore.SLOT('setValue(int)'))
        
        # Setting up contrast stuff. Moving slider or changing its value updates
        # cam's settings. Also connects spinbox to the slider to easily
        # configure it.
        self.connect(self.e.fContrastSlider,
                        QtCore.SIGNAL('sliderMoved(int)'),
                        self.slots['camChangeContrast'])
        self.connect(self.e.fContrastSlider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.slots['camChangeContrast'])
        self.connect(self.e.fContrastSlider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.e.fContrastSpin,
                        QtCore.SLOT('setValue(int)'))
        self.connect(self.e.fContrastSpin,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.e.fContrastSlider,
                        QtCore.SLOT('setValue(int)'))
        
        # Setting up brightness stuff. Moving slider or changing its value
        # updates cam's settings. Also connects spinbox to the slider to easily
        # configure it.
        self.connect(self.e.fBrightnessSlider,
                        QtCore.SIGNAL('sliderMoved(int)'),
                        self.slots['camChangeBrightness'])
        self.connect(self.e.fBrightnessSlider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.slots['camChangeBrightness'])
        self.connect(self.e.fBrightnessSlider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.e.fBrightnessSpin,
                        QtCore.SLOT('setValue(int)'))
        self.connect(self.e.fBrightnessSpin,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.e.fBrightnessSlider,
                        QtCore.SLOT('setValue(int)'))
        
        # Setting up saturation stuff. Moving slider or changing its value
        # updates cam's settings. Also connects spinbox to the slider to easily
        # configure it.
        self.connect(self.e.fSaturationSlider,
                        QtCore.SIGNAL('sliderMoved(int)'),
                        self.slots['camChangeSaturation'])
        self.connect(self.e.fSaturationSlider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.slots['camChangeSaturation'])
        self.connect(self.e.fSaturationSlider,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.e.fSaturationSpin,
                        QtCore.SLOT('setValue(int)'))
        self.connect(self.e.fSaturationSpin,
                        QtCore.SIGNAL('valueChanged(int)'),
                        self.e.fSaturationSlider,
                        QtCore.SLOT('setValue(int)'))
        
        # Setting up the timer to periodically retrieve a cam's frame and
        # display it.
        # Interval between two requests is defined by self.fps (see
        # self.__init__)
        self.e.grabTimer = QtCore.QTimer(self)
        self.connect(self.e.grabTimer, QtCore.SIGNAL('timeout()'), self.shot)
        self.e.grabTimer.start(1000 / self.fps)
    
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
        self.e.fHueSlider.setValue(self.cam.hue() * 100)
        self.e.fContrastSlider.setValue(self.cam.contrast() * 100)
        self.e.fSaturationSlider.setValue(self.cam.saturation() * 100)
        self.e.fBrightnessSlider.setValue(self.cam.brightness() * 100)
    
    
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
        self.e.labelFrame.setPixmap(QtGui.QPixmap.fromImage(QtGui.QImage('.frame.tmp.jpg')))
    
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

