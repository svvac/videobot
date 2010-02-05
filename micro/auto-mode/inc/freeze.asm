
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
;freeze.c,41 :: 		}
	RETURN
; end of _syncOutputs
