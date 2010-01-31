/*
 * videobot - automatic mode
 * description:  Maps board's ports
 *               (in heavy developpement)
 * file: inc/io.h
 *
 * config:
 *   controller:      PIC16F877A (EasyPic 4)
 *   clock:           HS, 08.0000 MHz
 *   compiler:        mikroC PRO 2009 (3.2)
 * author: Simon "SwordOfPain" Wachter
 *
 * This file is a part of the videobot project.
 * Web: http://swordofpain.hd.free.fr/tracker/projects/videobot
 * GitHub repo: http://github.com/swordofpain/videobot
 */

// Bounds press buttons
#define bSTART      PORTB.F7            // Start engine

// Status LEDs
#define dREADY      PORTD.F0            // Shows MCU is ready
#define dRUN        PORTD.F1            // Program is running
#define dWAITING    PORTD.F2            // Waiting for something
#define dERROR      PORTD.F3            // Something goes wrong
#define dDEBUG      PORTD.F4            // Debug mode

// Orders
#define oRMOTORF    PORTC.F0            // Right hand side motor forwards
#define oRMOTORB    PORTC.F1            // Right hand side motor backwards
#define oLMOTORF    PORTC.F2            // Left hand side motor forwards
#define oLMOTORB    PORTC.F3            // Left hand side motor backwards
#define oCAMUP      PORTC.F4            // Camera motor upwards
#define oCAMDWN     PORTC.F5            // Camera motor downwards

// Inputs
#define iCAMTOP     PORTB.F0            // Camera at top position
#define iCAMBTM     PORTB.F1            // Camera at bottom position

// Debug distance information
// For tests, we need to be able to send DIST_OPTIMAL, DIST_FARAWAY and
// DIST_OK signals to the program when the distance captor isn't present
#define iDISTCRIT   PORTB.F2            // Debug: distance to obstacle is critical
#define iDISTOK     PORTB.F3            // Debug: distance to object is correct

