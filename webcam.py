#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys
from PyQt4 import QtCore, QtGui
from PyQt4.QtCore import Qt
from PyQt4.phonon import Phonon
import Camera


class Empty :
    def __init__(self):
        return

class MainWindow(QtGui.QMainWindow):

    def __init__(self):
        # Call parent constructor
        QtGui.QMainWindow.__init__(self)
        
        # Define containers
        self.e = Empty()
        self.signals = Empty()
        
        self.fps = 10
        
        self.slots = {
            'camChangeHue': QtCore.SLOT('camChangeHue(int)'),
            'camChangeContrast': QtCore.SLOT('camChangeContrast(int)'),
            'camChangeSaturation': QtCore.SLOT('camChangeSaturation(int)'),
            'camChangeBrightness': QtCore.SLOT('camChangeBrightness(int)'),
            'camChangeFps': QtCore.SLOT('camChangeFps(int)')
        }
        
        # Set window options
        self.setWindowTitle("OpenCV webcam")
        self.resize(300, 180)
        
        self.init()
    
    def init(self):
        # Create widgets
        self.buildGui()
        # Setup logic
        self.buildBindings()
        # Initialize camera
        self.initCam()
    
    def buildGui(self):
        self.e.lMain = QtGui.QVBoxLayout()
        self.buildGuiVideo()
        self.buildGuiTabs()
        
        self.e.wMainContainer = QtGui.QWidget()
        self.e.wMainContainer.setLayout(self.e.lMain)
        self.setCentralWidget(self.e.wMainContainer)
    
    def buildGuiVideo(self):
        self.e.labelFrame = QtGui.QLabel()
        self.e.labelFrame.setScaledContents(True)
        
        self.e.lMain.addWidget(self.e.labelFrame)
    
    def buildGuiTabs(self):
        self.e.wTabs = QtGui.QTabWidget()
        self.buildGuiTabControls()
        self.buildGuiTabImg()
        self.e.lMain.addWidget(self.e.wTabs)
    
    def buildGuiTabImg(self):
        self.e.lTabImg = QtGui.QGridLayout()
        self.e.wTabImgContainer = QtGui.QWidget()
        
        #self.e.fFpsSlider = QtGui.QSlider(Qt.Horizontal)
        #self.e.fFpsSlider.setMaximum(1000)
        #self.e.fFpsSlider.setMinimum(1)
        #self.e.fFpsSlider.setValue(10)
        #self.e.lTabImg.addWidget(QtGui.QLabel('FPS'), 0, 0)
        #self.e.lTabImg.addWidget(self.e.fFpsSlider, 0, 1)
        
        self.e.fHueSlider = QtGui.QSlider(Qt.Horizontal)
        self.e.fHueSlider.setMaximum(100)
        self.e.fHueSpin = QtGui.QSpinBox()
        self.e.fHueSpin.setRange(0, 100)
        self.e.fHueSpin.setSuffix('%')
        self.e.lTabImg.addWidget(QtGui.QLabel('Hue'), 1, 0)
        self.e.lTabImg.addWidget(self.e.fHueSlider, 1, 1)
        self.e.lTabImg.addWidget(self.e.fHueSpin, 1, 2)
        
        self.e.fContrastSlider = QtGui.QSlider(Qt.Horizontal)
        self.e.fContrastSlider.setMaximum(100)
        self.e.fContrastSpin = QtGui.QSpinBox()
        self.e.fContrastSpin.setRange(0, 100)
        self.e.fContrastSpin.setSuffix('%')
        self.e.lTabImg.addWidget(QtGui.QLabel('Contrast'), 2, 0)
        self.e.lTabImg.addWidget(self.e.fContrastSlider, 2, 1)
        self.e.lTabImg.addWidget(self.e.fContrastSpin, 2, 2)
        
        self.e.fSaturationSlider = QtGui.QSlider(Qt.Horizontal)
        self.e.fSaturationSlider.setMaximum(100)
        self.e.fSaturationSpin = QtGui.QSpinBox()
        self.e.fSaturationSpin.setRange(0, 100)
        self.e.fSaturationSpin.setSuffix('%')
        self.e.lTabImg.addWidget(QtGui.QLabel('Saturation'), 3, 0)
        self.e.lTabImg.addWidget(self.e.fSaturationSlider, 3, 1)
        self.e.lTabImg.addWidget(self.e.fSaturationSpin, 3, 2)
        
        self.e.fBrightnessSlider = QtGui.QSlider(Qt.Horizontal)
        self.e.fBrightnessSlider.setMaximum(100)
        self.e.fBrightnessSpin = QtGui.QSpinBox()
        self.e.fBrightnessSpin.setRange(0, 100)
        self.e.fBrightnessSpin.setSuffix('%')
        self.e.lTabImg.addWidget(QtGui.QLabel('Brightness'), 4, 0)
        self.e.lTabImg.addWidget(self.e.fBrightnessSlider, 4, 1)
        self.e.lTabImg.addWidget(self.e.fBrightnessSpin, 4, 2)
        
        
        
        
        self.e.wTabImgContainer.setLayout(self.e.lTabImg)
        self.e.wTabs.addTab(self.e.wTabImgContainer, 'Video settings')
    
    def buildGuiTabControls(self):
        self.e.lTabControls = QtGui.QFormLayout()
        self.e.wTabControlsContainer = QtGui.QWidget()
        
        self.e.wTabControlsContainer.setLayout(self.e.lTabControls)
        self.e.wTabs.addTab(self.e.wTabControlsContainer, 'Controls')
    
    def buildBindings(self):
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
        
        #self.connect(self.e.fFpsSlider,
        #                QtCore.SIGNAL('valueChanged(int)'),
        #                self.slots['camChangeFps'])
        
        self.e.grabTimer = QtCore.QTimer(self)
        self.connect(self.e.grabTimer, QtCore.SIGNAL('timeout()'), self.shot)
        self.e.grabTimer.start(1000 / self.fps)
    
    def initCam(self):
        self.cam = Camera.Cam(-1)
        
        self.shot()
        
        self.e.fHueSlider.setValue(self.cam.hue() * 100)
        self.e.fContrastSlider.setValue(self.cam.contrast() * 100)
        self.e.fSaturationSlider.setValue(self.cam.saturation() * 100)
        self.e.fBrightnessSlider.setValue(self.cam.brightness() * 100)
    
    
    def shot(self):
        self.cam.save('.frame.tmp.jpg')
        self.e.labelFrame.setPixmap(QtGui.QPixmap.fromImage(QtGui.QImage('.frame.tmp.jpg')))
    
    def saveFrame(self):
        dest = QtGui.QFileDialog.getSaveFileName(self, "Save frame as...", '', 'Images (*.png *.gif *.jpg *.jpeg)')
        self.cam.save(str(dest))
    
    @QtCore.pyqtSlot(int)
    def camChangeHue(self, value):
        self.cam.setHue(value / 100.0)
    
    @QtCore.pyqtSlot(int)
    def camChangeContrast(self, value):
        self.cam.setContrast(value / 100.0)
    
    @QtCore.pyqtSlot(int)
    def camChangeSaturation(self, value):
        self.cam.setSaturation(value / 100.0)
    
    @QtCore.pyqtSlot(int)
    def camChangeBrightness(self, value):
        self.cam.setBrightness(value / 100.0)
    
    @QtCore.pyqtSlot(int)
    def camChangeFps(self, value):
        self.fps = value
        self.e.grabTimer.stop()
        self.e.grabTimer.setInterval(1000 / value)
        self.e.grabTimer.start()
        
    



if  __name__ == '__main__' :
    app = QtGui.QApplication(sys.argv)
    app.setApplicationName("camview")

    main = MainWindow()
    main.show()
    sys.exit(app.exec_())

