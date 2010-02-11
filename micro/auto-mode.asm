
_main:

;auto-mode.c,33 :: 		void main() {
;auto-mode.c,36 :: 		outputs oMem = {0};
	CLRF       main_oMem_L0+0
	CLRF       main_oMem_L0+1
	CLRF       main_oMem_L0+2
	CLRF       main_oMem_L0+3
	CLRF       main_oMem_L0+4
	CLRF       main_oMem_L0+5
	CLRF       main_oMem_L0+6
	CLRF       main_oMem_L0+7
	CLRF       main_oMem_L0+8
	CLRF       main_oMem_L0+9
	CLRF       main_oMem_L0+10
	CLRF       main_oMem_L0+11
	CLRF       main_oMem_L0+12
	CLRF       main_oMem_L0+13
	CLRF       main_oMem_L0+14
	CLRF       main_oMem_L0+15
	CLRF       main_oMem_L0+16
	CLRF       main_oMem_L0+17
	CLRF       main_oMem_L0+18
	CLRF       main_oMem_L0+19
	CLRF       main_oMem_L0+20
	CLRF       main_oMem_L0+21
;auto-mode.c,39 :: 		INTCON = 0;
	CLRF       INTCON+0
;auto-mode.c,41 :: 		TRISC = 0;
	CLRF       TRISC+0
;auto-mode.c,42 :: 		PORTC = 0;
	CLRF       PORTC+0
;auto-mode.c,43 :: 		TRISD = 0;
	CLRF       TRISD+0
;auto-mode.c,44 :: 		PORTD = 0;
	CLRF       PORTD+0
;auto-mode.c,46 :: 		TRISB = 0xff;
	MOVLW      255
	MOVWF      TRISB+0
;auto-mode.c,49 :: 		syncOutputs(&oMem);
	MOVLW      main_oMem_L0+0
	MOVWF      FARG_syncOutputs+0
	CALL       _syncOutputs+0
;auto-mode.c,51 :: 		freezeInputs(&iMem);
	MOVLW      main_iMem_L0+0
	MOVWF      FARG_freezeInputs+0
	CALL       _freezeInputs+0
;auto-mode.c,54 :: 		oMem.delReady = 1;
	MOVLW      1
	MOVWF      main_oMem_L0+0
	MOVLW      0
	MOVWF      main_oMem_L0+1
;auto-mode.c,56 :: 		oMem.delWaiting = 1;
	MOVLW      1
	MOVWF      main_oMem_L0+4
	MOVLW      0
	MOVWF      main_oMem_L0+5
;auto-mode.c,58 :: 		if (DBGMODE)    oMem.delDebug = 1;
	MOVLW      1
	MOVWF      main_oMem_L0+8
	MOVLW      0
	MOVWF      main_oMem_L0+9
;auto-mode.c,61 :: 		moveStops(&oMem);
	MOVLW      main_oMem_L0+0
	MOVWF      FARG_moveStops+0
	CALL       _moveStops+0
;auto-mode.c,64 :: 		syncOutputs(&oMem);
	MOVLW      main_oMem_L0+0
	MOVWF      FARG_syncOutputs+0
	CALL       _syncOutputs+0
;auto-mode.c,68 :: 		while (!iMem.startButton)     freezeInputs(&iMem);
L_main1:
	MOVF       main_iMem_L0+0, 0
	IORWF      main_iMem_L0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L_main2
	MOVLW      main_iMem_L0+0
	MOVWF      FARG_freezeInputs+0
	CALL       _freezeInputs+0
	GOTO       L_main1
L_main2:
;auto-mode.c,72 :: 		oMem.delReady = 0;
	CLRF       main_oMem_L0+0
	CLRF       main_oMem_L0+1
;auto-mode.c,73 :: 		oMem.delWaiting = 0;
	CLRF       main_oMem_L0+4
	CLRF       main_oMem_L0+5
;auto-mode.c,75 :: 		oMem.delRun = 1;
	MOVLW      1
	MOVWF      main_oMem_L0+2
	MOVLW      0
	MOVWF      main_oMem_L0+3
;auto-mode.c,77 :: 		syncOutputs(&oMem);
	MOVLW      main_oMem_L0+0
	MOVWF      FARG_syncOutputs+0
	CALL       _syncOutputs+0
;auto-mode.c,80 :: 		do {
L_main3:
;auto-mode.c,82 :: 		freezeInputs(&iMem);
	MOVLW      main_iMem_L0+0
	MOVWF      FARG_freezeInputs+0
	CALL       _freezeInputs+0
;auto-mode.c,84 :: 		syncOutputs(&oMem);
	MOVLW      main_oMem_L0+0
	MOVWF      FARG_syncOutputs+0
	CALL       _syncOutputs+0
;auto-mode.c,88 :: 		if (obstacleDistanceIsFaraway(iMem)) {
	MOVLW      10
	MOVWF      R3+0
	MOVLW      FARG_obstacleDistanceIsFaraway+0
	MOVWF      R2+0
	MOVLW      main_iMem_L0+0
	MOVWF      R1+0
L_main6:
	MOVF       R1+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
	INCF       R2+0, 1
	INCF       R1+0, 1
	DECF       R3+0, 1
	BTFSS      STATUS+0, 2
	GOTO       L_main6
	CALL       _obstacleDistanceIsFaraway+0
	MOVF       R0+0, 0
	IORWF      R0+1, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main7
;auto-mode.c,89 :: 		moveForwards(&oMem);
	MOVLW      main_oMem_L0+0
	MOVWF      FARG_moveForwards+0
	CALL       _moveForwards+0
;auto-mode.c,91 :: 		} else if (obstacleDistanceIsOk(iMem)) {
	GOTO       L_main8
L_main7:
	MOVLW      10
	MOVWF      R3+0
	MOVLW      FARG_obstacleDistanceIsOk+0
	MOVWF      R2+0
	MOVLW      main_iMem_L0+0
	MOVWF      R1+0
L_main9:
	MOVF       R1+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
	INCF       R2+0, 1
	INCF       R1+0, 1
	DECF       R3+0, 1
	BTFSS      STATUS+0, 2
	GOTO       L_main9
	CALL       _obstacleDistanceIsOk+0
	MOVF       R0+0, 0
	IORWF      R0+1, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main10
;auto-mode.c,92 :: 		moveTurnsLeft(&oMem);
	MOVLW      main_oMem_L0+0
	MOVWF      FARG_moveTurnsLeft+0
	CALL       _moveTurnsLeft+0
;auto-mode.c,94 :: 		} else {
	GOTO       L_main11
L_main10:
;auto-mode.c,95 :: 		moveStops(&oMem);
	MOVLW      main_oMem_L0+0
	MOVWF      FARG_moveStops+0
	CALL       _moveStops+0
;auto-mode.c,96 :: 		break;
	GOTO       L_main4
;auto-mode.c,97 :: 		}
L_main11:
L_main8:
;auto-mode.c,98 :: 		} while (1);
	GOTO       L_main3
L_main4:
;auto-mode.c,103 :: 		oMem.delRun = 0;
	CLRF       main_oMem_L0+2
	CLRF       main_oMem_L0+3
;auto-mode.c,104 :: 		oMem.delError = 1;
	MOVLW      1
	MOVWF      main_oMem_L0+6
	MOVLW      0
	MOVWF      main_oMem_L0+7
;auto-mode.c,106 :: 		moveStops(&oMem);
	MOVLW      main_oMem_L0+0
	MOVWF      FARG_moveStops+0
	CALL       _moveStops+0
;auto-mode.c,108 :: 		syncOutputs(&oMem);
	MOVLW      main_oMem_L0+0
	MOVWF      FARG_syncOutputs+0
	CALL       _syncOutputs+0
;auto-mode.c,109 :: 		}
	GOTO       $+0
; end of _main
