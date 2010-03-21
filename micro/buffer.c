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
 * @file        /buffer.c
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

#include "buffer.h"
#include "constants.h"

unsigned char RxBuffer[RxBUF_SIZE];
unsigned char TxBuffer[TxBUF_SIZE];

/**
 * static void bufferAppend(unsigned char d,
 *                          unsigned char* buf,
 *                          unsigned int size)
 *
 * Append the char `d` at the end of the buffer `buf` of size `size`
 */
static void bufferAppend(unsigned char d, unsigned char* buf, unsigned int size) {
    unsigned int left;

    left = bufferGetSize(buf, size);

    if (left < size)
        buf[left] = d;
}

/**
 * static unsigned char bufferPop(unsigned char* buf,
 *                                unsigned int size)
 *
 * Return the char on the top of the buffer `buf` of size `size`, then
 * delete it.
 */
static unsigned char bufferPop(unsigned char* buf, unsigned int size) {
    unsigned char f;
    unsigned int i;
    unsigned short flag = false;

    f = buf[0];

    for (i = 0; i < size; i++) {
        if (!flag && buf[i] == 0x00)
            flag = true;

        if (!flag)
            buf[i] = buf[i + 1];
        else
            buf[i] = 0x00;
    }

    return f;
}

/**
 * static unsigned char bufferGetNext(unsigned char* buf,
 *                                    unsigned int size)
 *
 * Return the next char in the buffer
 */
static unsigned char bufferGetNext(unsigned char* buf, unsigned int size) {
    return buf[0];
}

/**
 * static void bufferClean(unsigned char* buf,
 *                         unsigned int size)
 *
 * Cleans the buffer (replace all values with ASCII null)
 */
static void bufferClean(unsigned char* buf, unsigned int size) {
    unsigned int i;
    for (i = 0; i < size; i++) {
        buf[i] = 0x00;
    }
}

/**
 * static void bufferCleanTo(unsigned char delim,
 *                           unsigned char* buf,
 *                           unsigned int size)
 *
 * Cleans the buffer `buf` until it encounters the `delim` char. If `delim`
 * is not in the buffer, the function completely cleans it.
 */
static void bufferCleanTo(unsigned char delim, unsigned char* buf, unsigned int size) {
    char* ptr;
    unsigned int i;

    ptr = strchr(buf, delim);
    *ptr++;

    for (i = 0; *ptr && i < size; i++)
        buf[i] = *ptr++;

    while (i < size) {
        buf[i] = 0x00;
        i++;
    }
}

/**
 * static unsigned int bufferGetSize(unsigned char* buf,
 *                                   unsigned int size)
 *
 * Returns the position of the first ASCII null char in the buffer `buf`
 */
static unsigned int bufferGetSize(unsigned char* buf, unsigned int size) {
    return strlen(buf);
}



void RxBufferAppend(unsigned char d) {
    bufferAppend(d, &RxBuffer, RxBUF_SIZE);
}

unsigned char RxBufferPop(void) {
    return bufferPop(&RxBuffer, RxBUF_SIZE);
}

unsigned char RxBufferGetNext(void) {
    return bufferGetNext(&RxBuffer, RxBUF_SIZE);
}

void RxBufferClean(void) {
    bufferClean(&RxBuffer, RxBUF_SIZE);
}

void RxBufferCleanTo(unsigned char delim) {
    bufferCleanTo(delim, &RxBuffer, RxBUF_SIZE);
}

unsigned int RxBufferGetSize(void) {
    return bufferGetSize(&RxBuffer, RxBUF_SIZE);
}

unsigned int RxBufferLeftSpace(void) {
    return RxBUF_SIZE - RxBufferGetSize();
}


void TxBufferAppend(unsigned char d) {
    bufferAppend(d, &TxBuffer, TxBUF_SIZE);
}

unsigned char TxBufferPop(void) {
    return bufferPop(&TxBuffer, TxBUF_SIZE);
}

unsigned char TxBufferGetNext(void) {
    return bufferGetNext(&TxBuffer, TxBUF_SIZE);
}

void TxBufferClean(void) {
    bufferClean(&TxBuffer, TxBUF_SIZE);
}

void TxBufferCleanTo(unsigned char delim) {
    bufferCleanTo(delim, &TxBuffer, TxBUF_SIZE);
}

unsigned int TxBufferGetSize(void) {
    return bufferGetSize(&TxBuffer, TxBUF_SIZE);
}

unsigned int TxBufferLeftSpace(void) {
    return TxBUF_SIZE - TxBufferGetSize();
}
