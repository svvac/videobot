
_freezeInputs:

;freeze.c,19 :: 		void freezeInputs(inputs *mem) {
;freeze.c,20 :: 		mem->startButton        = PORTB.F7;
	MOVF       FARG_freezeInputs_mem+0, 0
	MOVWF      FSR
	MOVLW      0
	BTFSC      PORTB+0, 7
	MOVLW      1
	MOVWF      INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;freeze.c,21 :: 		mem->camCeil            = PORTB.F0;
	MOVLW      2
	ADDWF      FARG_freezeInputs_mem+0, 0
	MOVWF      FSR
	MOVLW      0
	BTFSC      PORTB+0, 0
	MOVLW      1
	MOVWF      INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;freeze.c,22 :: 		mem->camFloor           = PORTB.F1;
	MOVLW      4
	ADDWF      FARG_freezeInputs_mem+0, 0
	MOVWF      FSR
	MOVLW      0
	BTFSC      PORTB+0, 1
	MOVLW      1
	MOVWF      INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;freeze.c,23 :: 		mem->distCritical       = PORTB.F2;
	MOVLW      6
	ADDWF      FARG_freezeInputs_mem+0, 0
	MOVWF      FSR
	MOVLW      0
	BTFSC      PORTB+0, 2
	MOVLW      1
	MOVWF      INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;freeze.c,24 :: 		mem->distAcceptable     = PORTB.F3;
	MOVLW      8
	ADDWF      FARG_freezeInputs_mem+0, 0
	MOVWF      FSR
	MOVLW      0
	BTFSC      PORTB+0, 3
	MOVLW      1
	MOVWF      INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;freeze.c,25 :: 		}
	RETURN
; end of _freezeInputs

_syncOutputs:

;freeze.c,27 :: 		void syncOutputs(outputs* mem) {
;freeze.c,28 :: 		PORTD.F0                = mem->delReady;
	MOVF       FARG_syncOutputs_mem+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	BTFSC      R0+0, 0
	GOTO       L__syncOutputs0
	BCF        PORTD+0, 0
	GOTO       L__syncOutputs1
L__syncOutputs0:
	BSF        PORTD+0, 0
L__syncOutputs1:
;freeze.c,29 :: 		PORTD.F1                = mem->delRun;
	MOVLW      2
	ADDWF      FARG_syncOutputs_mem+0, 0
	MOVWF      FSR
	BTFSC      INDF+0, 0
	GOTO       L__syncOutputs2
	BCF        PORTD+0, 1
	GOTO       L__syncOutputs3
L__syncOutputs2:
	BSF        PORTD+0, 1
L__syncOutputs3:
;freeze.c,30 :: 		PORTD.F2                = mem->delWaiting;
	MOVLW      4
	ADDWF      FARG_syncOutputs_mem+0, 0
	MOVWF      FSR
	BTFSC      INDF+0, 0
	GOTO       L__syncOutputs4
	BCF        PORTD+0, 2
	GOTO       L__syncOutputs5
L__syncOutputs4:
	BSF        PORTD+0, 2
L__syncOutputs5:
;freeze.c,31 :: 		PORTD.F3                = mem->delError;
	MOVLW      6
	ADDWF      FARG_syncOutputs_mem+0, 0
	MOVWF      FSR
	BTFSC      INDF+0, 0
	GOTO       L__syncOutputs6
	BCF        PORTD+0, 3
	GOTO       L__syncOutputs7
L__syncOutputs6:
	BSF        PORTD+0, 3
L__syncOutputs7:
;freeze.c,32 :: 		PORTD.F4                = mem->delDebug;
	MOVLW      8
	ADDWF      FARG_syncOutputs_mem+0, 0
	MOVWF      FSR
	BTFSC      INDF+0, 0
	GOTO       L__syncOutputs8
	BCF        PORTD+0, 4
	GOTO       L__syncOutputs9
L__syncOutputs8:
	BSF        PORTD+0, 4
L__syncOutputs9:
;freeze.c,34 :: 		PORTC.F4                = mem->cameraUpw;
	MOVLW      10
	ADDWF      FARG_syncOutputs_mem+0, 0
	MOVWF      FSR
	BTFSC      INDF+0, 0
	GOTO       L__syncOutputs10
	BCF        PORTC+0, 4
	GOTO       L__syncOutputs11
L__syncOutputs10:
	BSF        PORTC+0, 4
L__syncOutputs11:
;freeze.c,35 :: 		PORTC.F5                = mem->cameraDownw;
	MOVLW      12
	ADDWF      FARG_syncOutputs_mem+0, 0
	MOVWF      FSR
	BTFSC      INDF+0, 0
	GOTO       L__syncOutputs12
	BCF        PORTC+0, 5
	GOTO       L__syncOutputs13
L__syncOutputs12:
	BSF        PORTC+0, 5
L__syncOutputs13:
;freeze.c,37 :: 		PORTC.F0                = mem->motorRForw;
	MOVLW      14
	ADDWF      FARG_syncOutputs_mem+0, 0
	MOVWF      FSR
	BTFSC      INDF+0, 0
	GOTO       L__syncOutputs14
	BCF        PORTC+0, 0
	GOTO       L__syncOutputs15
L__syncOutputs14:
	BSF        PORTC+0, 0
L__syncOutputs15:
;freeze.c,38 :: 		PORTC.F1                = mem->motorRBackw;
	MOVLW      16
	ADDWF      FARG_syncOutputs_mem+0, 0
	MOVWF      FSR
	BTFSC      INDF+0, 0
	GOTO       L__syncOutputs16
	BCF        PORTC+0, 1
	GOTO       L__syncOutputs17
L__syncOutputs16:
	BSF        PORTC+0, 1
L__syncOutputs17:
;freeze.c,39 :: 		PORTC.F2                = mem->motorLForw;
	MOVLW      18
	ADDWF      FARG_syncOutputs_mem+0, 0
	MOVWF      FSR
	BTFSC      INDF+0, 0
	GOTO       L__syncOutputs18
	BCF        PORTC+0, 2
	GOTO       L__syncOutputs19
L__syncOutputs18:
	BSF        PORTC+0, 2
L__syncOutputs19:
;freeze.c,40 :: 		PORTC.F3                = mem->motorLBackw;
	MOVLW      20
	ADDWF      FARG_syncOutputs_mem+0, 0
	MOVWF      FSR
	BTFSC      INDF+0, 0
	GOTO       L__syncOutputs20
	BCF        PORTC+0, 3
	GOTO       L__syncOutputs21
L__syncOutputs20:
	BSF        PORTC+0, 3
L__syncOutputs21:
;freeze.c,41 :: 		}
	RETURN
; end of _syncOutputs
