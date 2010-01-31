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

#define bSTART      PORTB.F7

#define LED1        PORTC.F0
#define LED2        PORTC.F1
#define LED3        PORTC.F2
#define LED4        PORTC.F3
#define LED5        PORTC.F4
#define LED6        PORTC.F5
#define LED7        PORTC.F6
#define LED8        PORTC.F7
