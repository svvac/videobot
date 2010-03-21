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
 * @file        /processor.c
 * @description Parse packets and execute proper actions
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


#include "processor.h"
#include "constants.h"
#include "io.h"
#include "buffer.h"


/**
 * void parseVPacket(void)
 *
 * Parse "V" (stands for "Version") packets. Send the MCU firmware
 * version number.
 */
void parseVPacket(void) {
    if (RxBufferGetSize() > 0) {
        EPacketTooLong();
        return;
    }

    sendConstPacket(VERSION);
    sendConstPacket(IO_SUCCESS);
}


/**
 * void parseSBPacket(void)
 *
 * Parse "SB" (stands for "Set Byte") packets.
 *
 * Packet prototype :
 *      SB:P:B:V<LF>
 *
 *  - P: Port identifier
 *  - B: Bit id
 *  - V: State (1, H: High ; 0, L: Low)
 */
void parseSBPacket(void) {
    char c1;
    int v1, mask;
    volatile unsigned char* ptr;

    c1 = toupper(RxBufferPop());

    if (!checkArgSeparator()) {
        EValueError();
        return;
    } else if (checkPacketSeparator()) {
        EPacketTooShort();
        return;
    }
    RxBufferPop();

    switch (c1) {
        case 'A':
            ptr = &PORTA;
            break;
        case 'B':
            ptr = &PORTB;
            break;
        case 'C':
            ptr = &PORTC;
            break;
        case 'D':
            ptr = &PORTD;
            break;
        case 'E':
            ptr = &PORTE;
            break;
        default:
            EValueError();
            sendConstComment("No such port.");
            return;
            break;

    }

    //c1 = RxBufferPop();
    //v1 = c1 - 0x30;
    v1 = extractNumber(1);

    if (v1 < 0 || v1 > 7) {
        EOutOfRange();
        return;
    }

    mask = 0x01 << v1;

    if (!checkArgSeparator()) {
        EValueError();
        return;
    } else if (checkPacketSeparator()) {
        EPacketTooShort();
        return;
    }
    RxBufferPop();

    c1 = toupper(RxBufferPop());

    if (!checkPacketSeparator()) {
        EPacketTooLong();
        return;
    }

    switch (c1) {
        case '1':
        case 'H':
            *ptr |= mask;
            break;
        case '0':
        case 'L':
            *ptr &= ~mask;
            break;
        default:
            EValueError();
            sendConstComment("Not a valid state.");
            return;
            break;
    }

    sendConstPacket(IO_SUCCESS);
}
