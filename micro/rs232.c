/**
 *                   _                _             _
 *            _     ( )              ( )           ( )_
 *     _   _ (_)   _| |   __     _   | |_      _   | ,_)
 *    ( ) ( )| | /'_` | /'__`\ /'_`\ | '_`\  /'_`\ | |
 *    | \_/ || |( (_| |(  ___/( (_) )| |_) )( (_) )| |_
 *    `\___/'(_)`\__,_)`\____)`\___/'(_,__/'`\___/'`\__)
 *
 *                    videobot project
 *
 * Copyright (C) 2010 -- Simon "swordofpain" Wachter
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @file        /rs232.c
 * @description Defines some accessors to USART methods.
 * @author      Simon "swordofpain" Wachter
 *
 * @licence     GNU GPL v3 (see /LICENCE)
 * @package     videobot
 * @subpackage  mcu-slave
 *
 * @created     2010-03-20
 * @updated     2010-03-20
 *
 * @web         http://swordofpain.tk/tracker/projects/videobot
 * @repository  http://github.com/swordofpain/videobot
 *
 */


#include "rs232.h"
#include "typedefs.h"

unsigned short RS232Initialized = false;

#ifdef RS232_USART
void RS232Init(void) { USART_Init(2400); RS232Initialized = true; }

unsigned short RS232DataReady(void) { return USART_Data_Ready(); }

unsigned char RS232Read() { return USART_Read(); }

void RS232Write(unsigned char b) { USART_Write(b); }
#else
void RS232Init(void) { UART1_Init(2400); }

unsigned short RS232DataReady(void) { return UART1_Data_Ready(); RS232Initialized = true; }

unsigned char RS232Read() { return UART1_Read(); }

void RS232Write(unsigned char b) { UART1_Write(b); }
#endif
