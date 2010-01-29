/*
 * videobot - automatic mode
 * description:  Maps board's ports
 *               (in heavy developpement)
 * file: physical.h
 *
 * config:
 *   controller:      PIC16F877A (EasyPic 4)
 *   clock:           HS, 08.0000 MHz
 *   compiler:        mikroC PRO 2009 (3.2)
 * author: Simon "SwordOfPain" Wachter
 *
 * This file is a part of the videobot project.
 * Web: http://swordofpain.hd.free.fr/tracker/projects/videobot
 * GitHub repo: http://github.com/swordofpain/videobot
 */

#define LED1 PORTD.F0
#define LED2 PORTD.F1
#define LED3 PORTD.F2
