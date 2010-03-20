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
#include "typedefs.h"

static void bufferAppend(unsigned char d, unsigned char* buf, unsigned int size) {
    unsigned int left;

    left = bufferGetSize(buf, size);

    if (left < size) {
        buf[left] = d;
    } else {
        bufferCleanTo(PACKET_SEPARATOR, buf, size);
    }
}

static unsigned char bufferPop(unsigned char* buf, unsigned int size) {
    unsigned char f;
    unsigned int i;

    f = buf[0];

    for (i = 0; i < size; i++) {
        buf[i] = buf[i + 1];
    }

    return f;
}

static unsigned char bufferGetNext(unsigned char* buf, unsigned int size) {
    return buf[1];
}

static void bufferClean(unsigned char* buf, unsigned int size) {
    unsigned int i;
    for (i = 0; i < size; i++) {
        buf[i] = 0x00;
    }
}

static void bufferCleanTo(unsigned char delim, unsigned char* buf, unsigned int size) {
    unsigned int i, j;
    short found = false;
    for (i = 0; i < size; i++) {
        if (!found && buf[i] != delim)
            continue;
        else if (!found && buf[i] == delim) {
            found = true;
            continue;
        }

        buf[j] = buf[i];
        j++;
    }

    if (found == false)
        bufferClean(buf, size);
}

static unsigned int bufferGetSize(unsigned char* buf, unsigned int size) {
    unsigned int i;

    for (i = 0; i < size && buf[i] != 0x00; i++)
        continue;

    return i;
}
