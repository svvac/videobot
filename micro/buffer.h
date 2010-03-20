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
 * @file        /buffer.h
 * @description Provides custom buffer management
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

#ifndef DEF_BUFFER
#define DEF_BUFFER

/* Constants */
#define RxBUF_SIZE 64
#define TxBUF_SIZE 64

#define PACKET_SEPARATOR 0x0a

unsigned char RxBuffer[RxBUF_SIZE];
unsigned char TxBuffer[TxBUF_SIZE];


/* Methods */

static void bufferAppend(unsigned char, unsigned char*, unsigned int);

static unsigned char bufferPop(unsigned char*, unsigned int);

static unsigned char bufferGetNext(unsigned char*, unsigned int);

static void bufferClean(unsigned char*, unsigned int);

static void bufferCleanTo(unsigned char, unsigned char*, unsigned int);

static unsigned int bufferGetSize(unsigned char*, unsigned int);

/* Accessors */

void RxBufferAppend(unsigned char);

unsigned char RxBufferPop(void);

unsigned char RxBufferGetNext(void);

void RxBufferClean(void);

void RxBufferCleanTo(unsigned char);

unsigned int RxBufferGetSize(void);

unsigned int RxBufferLeftSpace(void);


void TxBufferAppend(unsigned char);

unsigned char TxBufferPop(void);

unsigned char TxBufferGetNext(void);

void TxBufferClean(void);

void TxBufferCleanTo(unsigned char);

unsigned int TxBufferGetSize(void);

unsigned int TxBufferLeftSpace(void);

#endif
