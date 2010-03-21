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
 * @file        /main.c
 * @description Setups the MCU as a RS232-controlled slave to turn on/off
 *              pins. All the logical stuff is performed directly on the
 *              computer, and the MCU is only used as an interface.
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


#include "typedefs.h"
#include "rs232.h"
#include "buffer.h"
#include "io.h"

static void performIterTasks(void);
void initializeSystem(void);

/**
 * void main(void)
 *
 * Main program entry point. Uses an endless loop
 * to perform cyclic operations.
 */
void main(void) {
    /* Setups the system, defines ports states and some other stuff */
    initializeSystem();

    /* Endless loop */
    do {
        performIterTasks();
        processIO();
    } while (true);
}


/**
 * void initializeSystem(void)
 *
 * Called at the initialization of main() to setup default
 * I/O config.
 */
void initializeSystem(void) {
    /* Setups port A as output and clean */
    TRISA           = 0x00;
    /* Turns analog inputs to digital inputs and turns off ADC */
    ADCON1          = 0x0F;
    /* Comparators as digital inputs */
    CMCON           = 0x07;
    /* Cleans */
    PORTA           = 0x00;


    /* Setups port B as output and cleans */
    TRISB           = 0x00;
    PORTB           = 0x00;

    /* Setups port C as output, be careful with RC6 and RC7 that handle
     * RS232 connections :
     *      RX  --->  RC7
     *      TX  --->  RC6
     */
    TRISC           = 0x80;
    PORTC           = 0x00;

    /* Setups port D as output and cleans */
    TRISD           = 0x00;
    PORTD           = 0x00;

    /* Setups port E as output and cleans */
    TRISE           = 0x00;
    PORTE           = 0x00;

    /* Initializes serial module */
    RS232Init();

    /* Cleans buffers */
    RxBufferClean();
    TxBufferClean();

    /* Wait for the USART module to stamilize */
    Delay_ms(100);
}


/**
 * static void performIterTasks(void)
 *
 * Contains some stuff to execute at each iteration of the main
 * endless loop.
 */
static void performIterTasks(void) {
    populateRxBuffer();
    emitTxBuffer();
}
