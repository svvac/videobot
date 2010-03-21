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


///**
// * void parseCPacket(void)
// *
// * Parse "C" (stands for "Configure") packets.
// *
// * Packet prototype :
// *      C:<A>:<B>:<C>:<D>:<E>:<AD><LF>
// *
// *  - <A>: Port A's TRIS
// *  - <B>: Port B's TRIS
// *  - <C>: Port C's TRIS
// *  - <D>: Port D's TRIS
// *  - <E>: Port E's TRIS
// *  - <AD>: Number of A/D pins to enable
// *  - <V>: State (1, H: High ; 0, L: Low)
// */
//void parseCPacket(void) {
//    char PA, PB, PC, PD, PE, PAD;
//    //unsigned int v1;
//    //volatile unsigned char* ptr;
//
//    /* Port A */
//    PA = extractHex();
//    if (PA < 0 || PA > 255) {
//        EOutOfRange();
//        return;
//    }
//    if (!manageSeparator())
//        return;
//
//    /* Port B */
//    PB = extractHex();
//    if (PB < 0 || PB > 255) {
//        EOutOfRange();
//        return;
//    }
//
//    if (!manageSeparator())
//        return;
//
//    /* Port C */
//    PC = extractHex();
//    if (PC < 0 || PC > 255) {
//        EOutOfRange();
//        return;
//    }
//
//    if (!manageSeparator())
//        return;
//
//    /* Port D */
//    PD = extractHex();
//    if (PD < 0 || PD > 255) {
//        EOutOfRange();
//        return;
//    }
//
//    if (!manageSeparator())
//        return;
//
//    /* Port E */
//    PE = extractHex();
//    if (PE < 0 || PE > 15) {
//        EOutOfRange();
//        return;
//    }
//
//    if (!manageSeparator())
//        return;
//
//    /* Analog */
//    /* Port A */
//    PAD = extractHex();
//    if (PAD < 0 || PAD > 13) {
//        EOutOfRange();
//        return;
//    }
//
//    if (!checkPacketSeparator()) {
//        EPacketTooLong();
//        return;
//    }
//
//    TRISA = PA;
//    TRISB = PB;
//    TRISC = PC;
//    TRISD = PD;
//    TRISE = PE;
//
//    if (PAD == 0) {
//        ADCON1          = 0x0f;
//        ADON_bit        = 0;
//    } else {
//        ADCON0          = 0x00;
//        ADCON1          = 0x0f - PAD;
//
//        /* Set up ADCON2 options
//		 * A/D Result right justified
//		 * Acq time = 20 Tad (?)
//		 * Tad = Fosc/64
//		 */
//		ADCON2          = 0b10111110;
//        ADON_bit        = 1;
//    }
//}


/**
 * void parseSBPacket(void)
 *
 * Parse "SB" (stands for "Set Bit") packets.
 *
 * Packet prototype :
 *      SB:<P>:<B>:<V><LF>
 *
 *  - <P>: Port identifier
 *  - <B>: Bit id
 *  - <V>: State (1, H: High ; 0, L: Low)
 */
void parseSBPacket(void) {
    char c1;
    int v1, mask;
    volatile unsigned char* ptr;

    c1 = toupper(RxBufferPop());

    if (!manageSeparator())
        return;

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

    if (!manageSeparator())
        return;

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


/**
 * void parseSBPacket(void)
 *
 * Parse "GB" (stands for "Get Bit") packets.
 *
 * Packet prototype :
 *      GB:<P>:<B><LF>
 *
 *  - <P>: Port identifier
 *  - <B>: Bit id
 *
 * Slave's answer :
 *      A:<P>:<B>:<S><LF>
 *
 *  - <P>: Port identifier
 *  - <B>: Bit id
 *  - <S>: Bit state (H: High, L: Low)
 */
void parseGBPacket(void) {
    char c1;
    int v1, mask;
    volatile unsigned char* ptr;
    char answer[] = "A:X:N:S";

    c1 = toupper(RxBufferPop());

    if (!manageSeparator())
        return;

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

    answer[2] = c1;

    //c1 = RxBufferPop();
    //v1 = c1 - 0x30;
    v1 = extractNumber(1);

    if (v1 < 0 || v1 > 7) {
        EOutOfRange();
        return;
    }

    answer[4] = v1 + 0x30;

    mask = 0x01 << v1;

    if (!checkPacketSeparator()) {
        EPacketTooLong();
        return;
    }

    if ((*ptr & mask) > 0)
        answer[6] = 'H';
    else
        answer[6] = 'L';

    sendPacket(answer);
    sendConstPacket(IO_SUCCESS);
}


/**
 * void parseRAPacket(void)
 *
 * Parse "RA" (stands for "Read Analog") packets.
 *
 * Packet prototype :
 *      RA:<N><LF>
 *
 *  - <N>: Analog pin number
 *
 * Slave's answer :
 *      A:AD:<N>:<V><LF>
 *
 *  - <N>: Analog pin number
 *  - <V>: Value
 */
void parseRAPacket(void) {
    unsigned int v1;
    char answer[] = "A:AD:X:NN";
    const char digits[] = "0123456789abcdef";

    v1 = extractNumber(1);
    if (!checkPacketSeparator()) {
        EPacketTooLong();
        return;
    }

    answer[5] = v1 + 0x30;
    v1 = ADC_Read(v1);

    answer[7] = digits[(v1 & 0xf0) >> 4];
    answer[8] = digits[v1 & 0x0f];

    sendPacket(answer);
    sendConstPacket(IO_SUCCESS);
}
