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
 * @file        /io.c
 * @description Performs I/O related tasks
 * @author      Simon "swordofpain" Wachter
 *
 * @licence     GNU GPL v3 (see /LICENCE)
 * @package     videobot
 * @subpackage  mcu-slave
 *
 * @created     2010-03-20
 * @updated     2010-03-21
 *
 * @web         http://swordofpain.tk/tracker/projects/videobot
 * @repository  http://github.com/swordofpain/videobot
 *
 */


#include "io.h"
#include "constants.h"
#include "buffer.h"
#include "rs232.h"
#include "processor.h"



/**
 * void processIO(void)
 *
 * Perform all I/O related tasks
 */
void processIO(void) {
    unsigned long cmd;
    unsigned char c1, c2;

    switch (RxBuffergetSize()) {
        /* The buffer is empty, so we won't do anything */
        case 0:
            return;
            break;
        /* The buffer contains only one byte. We raise an BadQuery
         * error; a command is at least composed by the command
         * identifier, followed by the packet separator.
         */
        case 1:
            cmd = false;
            EBadQuery();
            break;
        /* Elseway */
        case 2:
        default:
            c1 = toupper(RxBufferPop());

            if (checkSeparator()) {
                cmd = c1;
            } else {
                c2 = RxBufferPop();

                if (checkSeparator())
                    cmd = c1 * 256 + c2;
                else {
                    cmd = false;
                    EBadQuery();
                }
            }
    }

    if (cmd) {
        switch (cmd) {
            case 'V':
                parseVPacket();
                break;
            default:
                EWrongCommand();
        }
    }
    RxBufferCleanTo(IO_PACKET_SEPARATOR);
}

/**
 * void populateRxBuffer(void)
 *
 * Reads RS232 input buffer and adds data to our own buffer.
 * The execution of the rest of the code is blocked until we
 * recieve the packet separator (I haven't found an other way
 * to prevent bytes vanishing caused by the limited size of the
 * hardware buffer).
 */
void populateRxBuffer(void) {
    char bf;

    do {
        if (RS232DataReady()) {
            bf = RS232Read();
            RxBufferAppend(bf);
        }
    } while (bf != IO_PACKET_SEPARATOR && RxBufferleftSpace() > 0);
}

/**
 * void emitTxBuffer(void)
 *
 * Flush transmit buffer to RS232 link
 */
void emitTxBuffer(void) {
    while (TxBufferGetSize() > 0) {
        RS232Write(TxBufferPop());
    }
}

/**
 * unsigned short checkSeparator(void)
 *
 * Check if the next byte in the Rx buffer is a separator
 * (packet separator or arg separator).
 */
unsigned short checkSeparator(void) {
    char bf;
    bf = RxBufferGetNext();

    if (bf == IO_PACKET_SEPARATOR || bf == IO_ARG_SEPARATOR)
        return true;
    else
        return false;
}

/**
 * void sendPacket(char*)
 *
 * Send a normalized packet
 */
void sendPacket(char* b) {
    while (*b && TxBufferLeftSpace() > 0)
        TxBufferAppend(*b++);

    TxBufferAppend('\n');
}

/**
 * void sendConstPacket(const char*)
 *
 * Send a normalized packet
 */
void sendConstPacket(const char* b) {
    while (*b && TxBufferLeftSpace() > 0)
        TxBufferAppend(*b++);

    TxBufferAppend('\n');
}


/**
 * void sendError(char*)
 *
 * Send an error packet
 */
void sendError(char* b) {
    TxBufferAppend('!');
    TxBufferAppend('E');
    TxBufferAppend(' ');
    sendPacket(b);
}

/**
 * void sendConstError(const char*)
 *
 * Send an error packet
 */
void sendConstError(const char* b) {
    TxBufferAppend('!');
    TxBufferAppend('E');
    TxBufferAppend(' ');
    sendConstPacket(b);
}

/**
 * void sendComment(char*)
 *
 * Send a comment packet
 */
void sendComment(char* b) {
    TxBufferAppend('#');
    TxBufferAppend(' ');
    sendPacket(b);
}

/**
 * void sendConstComment(const char*)
 *
 * Send a comment packet
 */
void sendConstComment(const char* b) {
    TxBufferAppend('#');
    TxBufferAppend(' ');
    sendConstPacket(b);
}

/**
 * void EBadQuery(void)
 *
 * Sends the "BAD QUERY" error message
 */
void EBadQuery(void) {
    sendConstError("01 BAD QUERY");
}

/**
 * void EWrongCommand(void)
 *
 * Sends the "WRONG COMMAND IDETIFIER" error message
 */
void EWrongCommand(void) {
    sendConstError("02 WRONG COMMAND IDENTIFIER");
}
