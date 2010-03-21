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
 * @updated     2010-03-20
 *
 * @web         http://swordofpain.tk/tracker/projects/videobot
 * @repository  http://github.com/swordofpain/videobot
 *
 */


#include "io.h"
#include "typedefs.h"
#include "buffer.h"
#include "rs232.h"

/**
 * void processIO(void)
 *
 * Perform all I/O related tasks
 */
void processIO(void) {
    /* Test programm: send back the buffer to the pc */
    unsigned int i;
    for (i = 0; TxBufferGetSize() > 0; i++) {
        if (i % 2 == 0)
            continue;

        TxBufferAppend(RxBufferPop());
    }
}

/**
 * void populateRxBuffer(void)
 *
 * Reads RS232 input buffer and adds data to our own buffer
 */
void populateRxBuffer(void) {
    while (RS232DataReady() && RxBufferLeftSpace() > 0) {
        RxBufferAppend(RS232Read());
    }
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
