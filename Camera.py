#!/usr/bin/env python
#-*- coding:utf-8 -*-

import cv

HUE                 = cv.CV_CAP_PROP_HUE
SATURATION          = cv.CV_CAP_PROP_SATURATION
BRIGHTNESS          = cv.CV_CAP_PROP_BRIGHTNESS
CONTRAST            = cv.CV_CAP_PROP_CONTRAST

class Cam:
    def __init__(self, device = -1):
        self.device = cv.CaptureFromCAM(device)
    
    def getFrame(self):
        cv.GrabFrame(self.device)
        return cv.QueryFrame(self.device)
    
    def getProperty(self, name):
        return cv.GetCaptureProperty(self.device, name)
    
    def setProperty(self, name, value):
        cv.SetCaptureProperty(self.device, name, value)
        return self.getProperty(name)
    
    def save(self, filename):
        return cv.SaveImage(filename, self.getFrame())
    
    
    
    def hue(self):
        return self.getProperty(HUE)
    
    def saturation(self):
        return self.getProperty(SATURATION)
    
    def brightness(self):
        return self.getProperty(BRIGHTNESS)
    
    def contrast(self):
        return self.getProperty(CONTRAST)
    
    
    def setHue(self, value):
        return self.setProperty(HUE, float(value))
    
    def setSaturation(self, value):
        return self.setProperty(SATURATION, float(value))
    
    def setBrightness(self, value):
        return self.setProperty(BRIGHTNESS, float(value))
    
    def setContrast(self, value):
        return self.setProperty(CONTRAST, float(value))

