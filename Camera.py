#!/usr/bin/env python
#-*- coding:utf-8 -*-

# Imports OpenCV functions
import cv

# Defining some constants
HUE                 = cv.CV_CAP_PROP_HUE
SATURATION          = cv.CV_CAP_PROP_SATURATION
BRIGHTNESS          = cv.CV_CAP_PROP_BRIGHTNESS
CONTRAST            = cv.CV_CAP_PROP_CONTRAST
WIDTH               = cv.CV_CAP_FRAME_WIDTH
HEIGHT              = cv.CV_CAP_FRAME_HEIGHT

class Cam:
    """ OpenCV wrapper to easily manage cameras with an OO class. Say good bye to ugly cv.functions ! """
    
    def __init__(self, device = -1):
        """ Open a CVCapture camera device """
        
        # Opens the camera identified the device id $device$ 
        self.device = cv.CaptureFromCAM(device)
    
    def getFrame(self):
        """ Retrieve and returns a frame """
        # Try to clear frame cache (seems to be useless)
        cv.GrabFrame(self.device)
        # Returns a frame from thecamera
        return cv.QueryFrame(self.device)
    
    def getProperty(self, name):
        """ Returns the device's property $name$ """
        return cv.GetCaptureProperty(self.device, name)
    
    def setProperty(self, name, value):
        """ Sets the device's property $name$ at $value$ """
        # Sets the property (notices that no value check is done)
        cv.SetCaptureProperty(self.device, name, value)
        # Returns the actual value (i.e. after definition) of the property. This
        # can be useful to check if the modification is effective
        return self.getProperty(name)
    
    def save(self, filename):
        """ Retrieve a frame and save it in the file $filename$ """
        return cv.SaveImage(filename, self.getFrame())
    
    
    # Here comes some useful accessors
    
    def hue(self):
        """ Returns the image hue of the device """
        return self.getProperty(HUE)
    
    def saturation(self):
        """ Returns the image saturation of the device """
        return self.getProperty(SATURATION)
    
    def brightness(self):
        """ Returns the image brightness of the device """
        return self.getProperty(BRIGHTNESS)
    
    def contrast(self):
        """ Returns the image contrast of the device """
        return self.getProperty(CONTRAST)
    
    def width(self):
        """ Returns the frame width for the device """
        return self.getProperty(WIDTH)
    
    def height(self):
        """ Returns the frame height for the device """
        return self.getProperty(HEIGHT)
    
    
    def setHue(self, value):
        """ Sets the image hue of the device """
        return self.setProperty(HUE, float(value))
    
    def setSaturation(self, value):
        """ Sets the image saturation of the device """
        return self.setProperty(SATURATION, float(value))
    
    def setBrightness(self, value):
        """ Sets the image brightness of the device """
        return self.setProperty(BRIGHTNESS, float(value))
    
    def setContrast(self, value):
        """ Sets the image contrast of the device """
        return self.setProperty(CONTRAST, float(value))
    
    def setWidth(self, value):
        """ Sets the frame width for the device """
        return self.setProperty(WIDTH, float(value))
    
    def setHeight(self, value):
        """ Sets the frame height for the device """
        return self.setProperty(HEIGHT, float(value))

