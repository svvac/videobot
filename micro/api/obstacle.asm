
_obstacleDistanceIsFaraway:

;obstacle.c,20 :: 		int obstacleDistanceIsFaraway(inputs mem) {
;obstacle.c,24 :: 		return (!mem.distCritical && !mem.distAcceptable);
	MOVF       FARG_obstacleDistanceIsFaraway_mem+6, 0
	IORWF      FARG_obstacleDistanceIsFaraway_mem+7, 0
	BTFSS      STATUS+0, 2
	GOTO       L_obstacleDistanceIsFaraway2
	MOVF       FARG_obstacleDistanceIsFaraway_mem+8, 0
	IORWF      FARG_obstacleDistanceIsFaraway_mem+9, 0
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
;obstacle.c,30 :: 		}
	RETURN
; end of _obstacleDistanceIsFaraway

_obstacleDistanceIsOk:

;obstacle.c,32 :: 		int obstacleDistanceIsOk(inputs mem) {
;obstacle.c,36 :: 		return (!mem.distCritical && mem.distAcceptable);
	MOVF       FARG_obstacleDistanceIsOk_mem+6, 0
	IORWF      FARG_obstacleDistanceIsOk_mem+7, 0
	BTFSS      STATUS+0, 2
	GOTO       L_obstacleDistanceIsOk5
	MOVF       FARG_obstacleDistanceIsOk_mem+8, 0
	IORWF      FARG_obstacleDistanceIsOk_mem+9, 0
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
;obstacle.c,42 :: 		}
	RETURN
; end of _obstacleDistanceIsOk

_obstacleDistanceIsCritical:

;obstacle.c,44 :: 		int obstacleDistanceIsCritical(inputs mem) {
;obstacle.c,48 :: 		return (mem.distCritical);
	MOVF       FARG_obstacleDistanceIsCritical_mem+6, 0
	MOVWF      R0+0
	MOVF       FARG_obstacleDistanceIsCritical_mem+7, 0
	MOVWF      R0+1
;obstacle.c,54 :: 		}
	RETURN
; end of _obstacleDistanceIsCritical

_obstacleGetDistance:

;obstacle.c,56 :: 		int obstacleGetDistance(inputs mem) {
;obstacle.c,58 :: 		return -1;
	MOVLW      255
	MOVWF      R0+0
	MOVLW      255
	MOVWF      R0+1
;obstacle.c,59 :: 		}
	RETURN
; end of _obstacleGetDistance
