
_moveMotorRightForwards:

;move.h,18 :: 		void moveMotorRightForwards(void) {
;move.h,19 :: 		oRMOTORF = 1;
	BSF        PORTC+0, 0
;move.h,20 :: 		oRMOTORB = 0;
	BCF        PORTC+0, 1
;move.h,21 :: 		}
	RETURN
; end of _moveMotorRightForwards

_moveMotorRightBackwards:

;move.h,23 :: 		void moveMotorRightBackwards(void) {
;move.h,24 :: 		oRMOTORF = 0;
	BCF        PORTC+0, 0
;move.h,25 :: 		oRMOTORB = 1;
	BSF        PORTC+0, 1
;move.h,26 :: 		}
	RETURN
; end of _moveMotorRightBackwards

_moveMotorRightStops:

;move.h,28 :: 		void moveMotorRightStops(void) {
;move.h,29 :: 		oRMOTORF = 0;
	BCF        PORTC+0, 0
;move.h,30 :: 		oRMOTORB = 0;
	BCF        PORTC+0, 1
;move.h,31 :: 		}
	RETURN
; end of _moveMotorRightStops

_moveMotorLeftBackwards:

;move.h,33 :: 		void moveMotorLeftBackwards(void) {
;move.h,34 :: 		oLMOTORF = 0;
	BCF        PORTC+0, 2
;move.h,35 :: 		oLMOTORB = 1;
	BSF        PORTC+0, 3
;move.h,36 :: 		}
	RETURN
; end of _moveMotorLeftBackwards

_moveMotorLeftForwards:

;move.h,37 :: 		void moveMotorLeftForwards(void) {
;move.h,38 :: 		oLMOTORF = 1;
	BSF        PORTC+0, 2
;move.h,39 :: 		oLMOTORB = 0;
	BCF        PORTC+0, 3
;move.h,40 :: 		}
	RETURN
; end of _moveMotorLeftForwards

_moveMotorLeftStops:

;move.h,42 :: 		void moveMotorLeftStops(void) {
;move.h,43 :: 		oLMOTORF = 0;
	BCF        PORTC+0, 2
;move.h,44 :: 		oLMOTORB = 0;
	BCF        PORTC+0, 3
;move.h,45 :: 		}
	RETURN
; end of _moveMotorLeftStops

_moveForwards:

;move.h,47 :: 		void moveForwards(void) {
;move.h,48 :: 		moveMotorRightForwards();
	CALL       _moveMotorRightForwards+0
;move.h,49 :: 		moveMotorLeftForwards();
	CALL       _moveMotorLeftForwards+0
;move.h,50 :: 		}
	RETURN
; end of _moveForwards

_moveBackwards:

;move.h,52 :: 		void moveBackwards(void) {
;move.h,53 :: 		moveMotorRightBackwards();
	CALL       _moveMotorRightBackwards+0
;move.h,54 :: 		moveMotorLeftBackwards();
	CALL       _moveMotorLeftBackwards+0
;move.h,55 :: 		}
	RETURN
; end of _moveBackwards

_moveStops:

;move.h,57 :: 		void moveStops(void) {
;move.h,58 :: 		moveMotorRightStops();
	CALL       _moveMotorRightStops+0
;move.h,59 :: 		moveMotorLeftStops();
	CALL       _moveMotorLeftStops+0
;move.h,60 :: 		}
	RETURN
; end of _moveStops

_moveTurnsRight:

;move.h,62 :: 		void moveTurnsRight(void) {
;move.h,63 :: 		moveMotorRightBackwards();
	CALL       _moveMotorRightBackwards+0
;move.h,64 :: 		moveMotorLeftForwards();
	CALL       _moveMotorLeftForwards+0
;move.h,65 :: 		}
	RETURN
; end of _moveTurnsRight

_moveTurnsLeft:

;move.h,67 :: 		void moveTurnsLeft(void) {
;move.h,68 :: 		moveMotorRightForwards();
	CALL       _moveMotorRightForwards+0
;move.h,69 :: 		moveMotorLeftBackwards();
	CALL       _moveMotorLeftBackwards+0
;move.h,70 :: 		}
	RETURN
; end of _moveTurnsLeft

_obstacleDistanceIsFaraway:

;obstacle.h,33 :: 		int obstacleDistanceIsFaraway(int mem[5]) {
;obstacle.h,37 :: 		return (!mem[iDistCritOffset] && !mem[iDistOkOffset]);
	MOVLW      6
	ADDWF      FARG_obstacleDistanceIsFaraway_mem+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	INCF       FSR, 1
	MOVF       INDF+0, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	IORWF      R0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L_obstacleDistanceIsFaraway2
	MOVLW      8
	ADDWF      FARG_obstacleDistanceIsFaraway_mem+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	INCF       FSR, 1
	MOVF       INDF+0, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	IORWF      R0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L_obstacleDistanceIsFaraway2
	MOVLW      1
	MOVWF      R0+0
	GOTO       L_obstacleDistanceIsFaraway1
L_obstacleDistanceIsFaraway2:
	CLRF       R0+0
L_obstacleDistanceIsFaraway1:
	MOVLW      0
	MOVWF      R0+1
;obstacle.h,43 :: 		}
	RETURN
; end of _obstacleDistanceIsFaraway

_obstacleDistanceIsOk:

;obstacle.h,50 :: 		int obstacleDistanceIsOk(int mem[5]) {
;obstacle.h,54 :: 		return (!mem[iDistCritOffset] && mem[iDistOkOffset]);
	MOVLW      6
	ADDWF      FARG_obstacleDistanceIsOk_mem+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	INCF       FSR, 1
	MOVF       INDF+0, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	IORWF      R0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L_obstacleDistanceIsOk5
	MOVLW      8
	ADDWF      FARG_obstacleDistanceIsOk_mem+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	INCF       FSR, 1
	MOVF       INDF+0, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	IORWF      R0+1, 0
	BTFSC      STATUS+0, 2
	GOTO       L_obstacleDistanceIsOk5
	MOVLW      1
	MOVWF      R0+0
	GOTO       L_obstacleDistanceIsOk4
L_obstacleDistanceIsOk5:
	CLRF       R0+0
L_obstacleDistanceIsOk4:
	MOVLW      0
	MOVWF      R0+1
;obstacle.h,60 :: 		}
	RETURN
; end of _obstacleDistanceIsOk

_obstacleDistanceIsCritical:

;obstacle.h,67 :: 		int obstacleDistanceIsCritical(int mem[5]) {
;obstacle.h,71 :: 		return (mem[iDistCritOffset]);
	MOVLW      6
	ADDWF      FARG_obstacleDistanceIsCritical_mem+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	INCF       FSR, 1
	MOVF       INDF+0, 0
	MOVWF      R0+1
;obstacle.h,77 :: 		}
	RETURN
; end of _obstacleDistanceIsCritical

_obstacleGetDistance:

;obstacle.h,84 :: 		int obstacleGetDistance(int mem[5]) {
;obstacle.h,90 :: 		if (obstacleDistanceIsFaraway(mem))     return ObstacleFarawayMetric;
	MOVF       FARG_obstacleGetDistance_mem+0, 0
	MOVWF      FARG_obstacleDistanceIsFaraway_mem+0
	CALL       _obstacleDistanceIsFaraway+0
	MOVF       R0+0, 0
	IORWF      R0+1, 0
	BTFSC      STATUS+0, 2
	GOTO       L_obstacleGetDistance8
	MOVLW      100
	MOVWF      R0+0
	MOVLW      0
	MOVWF      R0+1
	RETURN
L_obstacleGetDistance8:
;obstacle.h,91 :: 		else if (obstacleDistanceIsOk(mem))     return ObstacleOkMetric;
	MOVF       FARG_obstacleGetDistance_mem+0, 0
	MOVWF      FARG_obstacleDistanceIsOk_mem+0
	CALL       _obstacleDistanceIsOk+0
	MOVF       R0+0, 0
	IORWF      R0+1, 0
	BTFSC      STATUS+0, 2
	GOTO       L_obstacleGetDistance10
	MOVLW      40
	MOVWF      R0+0
	MOVLW      0
	MOVWF      R0+1
	RETURN
L_obstacleGetDistance10:
;obstacle.h,92 :: 		else                                    return ObstacleCriticalMetric;
	MOVLW      20
	MOVWF      R0+0
	MOVLW      0
	MOVWF      R0+1
;obstacle.h,97 :: 		}
	RETURN
; end of _obstacleGetDistance

_main:

;auto-mode.c,36 :: 		void main() {
;auto-mode.c,40 :: 		INTCON = 0;
	CLRF       INTCON+0
;auto-mode.c,43 :: 		TRISC = 0;
	CLRF       TRISC+0
;auto-mode.c,44 :: 		PORTC = 0;
	CLRF       PORTC+0
;auto-mode.c,45 :: 		TRISD = 0;
	CLRF       TRISD+0
;auto-mode.c,46 :: 		PORTD = 0;
	CLRF       PORTD+0
;auto-mode.c,49 :: 		TRISB = 0xff;
	MOVLW      255
	MOVWF      TRISB+0
;auto-mode.c,52 :: 		dREADY = 1;
	BSF        PORTD+0, 0
;auto-mode.c,54 :: 		dWAITING = 1;
	BSF        PORTD+0, 2
;auto-mode.c,57 :: 		if (DBGMODE)    dDEBUG = 1;
	BSF        PORTD+0, 4
;auto-mode.c,60 :: 		moveStops();
	CALL       _moveStops+0
;auto-mode.c,63 :: 		while (!bSTART);
L_main13:
	BTFSC      PORTB+0, 7
	GOTO       L_main14
	GOTO       L_main13
L_main14:
;auto-mode.c,65 :: 		dREADY = 0;
	BCF        PORTD+0, 0
;auto-mode.c,66 :: 		dWAITING = 0;
	BCF        PORTD+0, 2
;auto-mode.c,68 :: 		dRUN = 1;
	BSF        PORTD+0, 1
;auto-mode.c,71 :: 		while (1) {
L_main15:
;auto-mode.c,74 :: 		mem[0] = bSTART;
	MOVLW      0
	BTFSC      PORTB+0, 7
	MOVLW      1
	MOVWF      main_mem_L1+0
	CLRF       main_mem_L1+1
;auto-mode.c,75 :: 		mem[1] = iCAMTOP;
	MOVLW      0
	BTFSC      PORTB+0, 0
	MOVLW      1
	MOVWF      main_mem_L1+2
	CLRF       main_mem_L1+3
;auto-mode.c,76 :: 		mem[2] = iCAMBTM;
	MOVLW      0
	BTFSC      PORTB+0, 1
	MOVLW      1
	MOVWF      main_mem_L1+4
	CLRF       main_mem_L1+5
;auto-mode.c,77 :: 		mem[3] = iDISTCRIT;
	MOVLW      0
	BTFSC      PORTB+0, 2
	MOVLW      1
	MOVWF      main_mem_L1+6
	CLRF       main_mem_L1+7
;auto-mode.c,78 :: 		mem[4] = iDISTOK;
	MOVLW      0
	BTFSC      PORTB+0, 3
	MOVLW      1
	MOVWF      main_mem_L1+8
	CLRF       main_mem_L1+9
;auto-mode.c,82 :: 		if (obstacleDistanceIsFaraway(mem)) {
	MOVLW      main_mem_L1+0
	MOVWF      FARG_obstacleDistanceIsFaraway_mem+0
	CALL       _obstacleDistanceIsFaraway+0
	MOVF       R0+0, 0
	IORWF      R0+1, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main17
;auto-mode.c,83 :: 		moveForwards();
	CALL       _moveForwards+0
;auto-mode.c,85 :: 		} else if (obstacleDistanceIsOk(mem)) {
	GOTO       L_main18
L_main17:
	MOVLW      main_mem_L1+0
	MOVWF      FARG_obstacleDistanceIsOk_mem+0
	CALL       _obstacleDistanceIsOk+0
	MOVF       R0+0, 0
	IORWF      R0+1, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main19
;auto-mode.c,86 :: 		moveTurnsLeft();
	CALL       _moveTurnsLeft+0
;auto-mode.c,88 :: 		} else {
	GOTO       L_main20
L_main19:
;auto-mode.c,89 :: 		moveStops();
	CALL       _moveStops+0
;auto-mode.c,90 :: 		break;
	GOTO       L_main16
;auto-mode.c,91 :: 		}
L_main20:
L_main18:
;auto-mode.c,92 :: 		}
	GOTO       L_main15
L_main16:
;auto-mode.c,97 :: 		dRUN = 0;
	BCF        PORTD+0, 1
;auto-mode.c,98 :: 		dERROR = 1;
	BSF        PORTD+0, 3
;auto-mode.c,100 :: 		moveStops();
	CALL       _moveStops+0
;auto-mode.c,101 :: 		}
	GOTO       $+0
; end of _main
