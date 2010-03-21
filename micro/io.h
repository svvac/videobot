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
 * @file        /io.h
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

#ifndef DEF_IO
#define DEF_IO

/* Use LF (0x0a, aka \n) as packet separator */
#define IO_PACKET_SEPARATOR     0x0a

/* Use : as arg separator */
#define IO_ARG_SEPARATOR        0x3a

/* States */
#define IO_OK                   "*RECEIVED"
#define IO_SUCCESS              "*SUCCESS"
#define IO_FAILED               "*FAILED"
#define IO_DONE                 "*DONE"

void processIO(void);

void populateRxBuffer(void);

void emitTxBuffer(void);

unsigned short checkSeparator(void);

unsigned short checkArgSeparator(void);

unsigned short checkPacketSeparator(void);

void sendPacket(char*);

void sendError(char*);

void sendComment(char*);

void sendConstPacket(const char*);

void sendConstError(const char*);

void sendConstComment(const char*);

long extractNumber(unsigned int);

void EBadQuery(void);

void EWrongCommand(void);

void EPacketTooLong(void);

void EPacketTooShort(void);

void EValueError(void);

void EOutOfRange(void);

#endif
