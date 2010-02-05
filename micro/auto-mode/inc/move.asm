
move_moveMotorRightForwards:

;move.c,21 :: 		static void moveMotorRightForwards(outputs mem) {
;move.c,22 :: 		mem.motorRForw = 1;
	MOVLW      1
	MOVWF      FARG_move_moveMotorRightForwards_mem+14
	MOVLW      0
	MOVWF      FARG_move_moveMotorRightForwards_mem+15
;move.c,23 :: 		mem.motorRBackw = 0;
	CLRF       FARG_move_moveMotorRightForwards_mem+16
	CLRF       FARG_move_moveMotorRightForwards_mem+17
;move.c,24 :: 		}
	RETURN
; end of move_moveMotorRightForwards

move_moveMotorRightBackwards:

;move.c,26 :: 		static void moveMotorRightBackwards(outputs mem) {
;move.c,27 :: 		mem.motorRForw = 0;
	CLRF       FARG_move_moveMotorRightBackwards_mem+14
	CLRF       FARG_move_moveMotorRightBackwards_mem+15
;move.c,28 :: 		mem.motorRBackw = 1;
	MOVLW      1
	MOVWF      FARG_move_moveMotorRightBackwards_mem+16
	MOVLW      0
	MOVWF      FARG_move_moveMotorRightBackwards_mem+17
;move.c,29 :: 		}
	RETURN
; end of move_moveMotorRightBackwards

move_moveMotorRightStops:

;move.c,31 :: 		static void moveMotorRightStops(outputs mem) {
;move.c,32 :: 		mem.motorRForw = 0;
	CLRF       FARG_move_moveMotorRightStops_mem+14
	CLRF       FARG_move_moveMotorRightStops_mem+15
;move.c,33 :: 		mem.motorRBackw = 0;
	CLRF       FARG_move_moveMotorRightStops_mem+16
	CLRF       FARG_move_moveMotorRightStops_mem+17
;move.c,34 :: 		}
	RETURN
; end of move_moveMotorRightStops

move_moveMotorLeftBackwards:

;move.c,36 :: 		static void moveMotorLeftBackwards(outputs mem) {
;move.c,37 :: 		mem.motorLForw = 0;
	CLRF       FARG_move_moveMotorLeftBackwards_mem+18
	CLRF       FARG_move_moveMotorLeftBackwards_mem+19
;move.c,38 :: 		mem.motorLBackw = 1;
	MOVLW      1
	MOVWF      FARG_move_moveMotorLeftBackwards_mem+20
	MOVLW      0
	MOVWF      FARG_move_moveMotorLeftBackwards_mem+21
;move.c,39 :: 		}
	RETURN
; end of move_moveMotorLeftBackwards

move_moveMotorLeftForwards:

;move.c,40 :: 		static void moveMotorLeftForwards(outputs mem) {
;move.c,41 :: 		mem.motorLForw = 1;
	MOVLW      1
	MOVWF      FARG_move_moveMotorLeftForwards_mem+18
	MOVLW      0
	MOVWF      FARG_move_moveMotorLeftForwards_mem+19
;move.c,42 :: 		mem.motorLBackw = 0;
	CLRF       FARG_move_moveMotorLeftForwards_mem+20
	CLRF       FARG_move_moveMotorLeftForwards_mem+21
;move.c,43 :: 		}
	RETURN
; end of move_moveMotorLeftForwards

move_moveMotorLeftStops:

;move.c,45 :: 		static void moveMotorLeftStops(outputs mem) {
;move.c,46 :: 		mem.motorLForw = 0;
	CLRF       FARG_move_moveMotorLeftStops_mem+18
	CLRF       FARG_move_moveMotorLeftStops_mem+19
;move.c,47 :: 		mem.motorLBackw = 0;
	CLRF       FARG_move_moveMotorLeftStops_mem+20
	CLRF       FARG_move_moveMotorLeftStops_mem+21
;move.c,48 :: 		}
	RETURN
; end of move_moveMotorLeftStops

_moveForwards:

;move.c,50 :: 		void moveForwards(outputs mem) {
;move.c,51 :: 		moveMotorRightForwards(mem);
	MOVLW      22
	MOVWF      R3+0
	MOVLW      FARG_move_moveMotorRightForwards_mem+0
	MOVWF      R2+0
	MOVLW      FARG_moveForwards_mem+0
	MOVWF      R1+0
L_moveForwards0:
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
	GOTO       L_moveForwards0
	CALL       move_moveMotorRightForwards+0
;move.c,52 :: 		moveMotorLeftForwards(mem);
	MOVLW      22
	MOVWF      R3+0
	MOVLW      FARG_move_moveMotorLeftForwards_mem+0
	MOVWF      R2+0
	MOVLW      FARG_moveForwards_mem+0
	MOVWF      R1+0
L_moveForwards1:
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
	GOTO       L_moveForwards1
	CALL       move_moveMotorLeftForwards+0
;move.c,53 :: 		}
	RETURN
; end of _moveForwards

_moveBackwards:

;move.c,55 :: 		void moveBackwards(outputs mem) {
;move.c,56 :: 		moveMotorRightBackwards(mem);
	MOVLW      22
	MOVWF      R3+0
	MOVLW      FARG_move_moveMotorRightBackwards_mem+0
	MOVWF      R2+0
	MOVLW      FARG_moveBackwards_mem+0
	MOVWF      R1+0
L_moveBackwards2:
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
	GOTO       L_moveBackwards2
	CALL       move_moveMotorRightBackwards+0
;move.c,57 :: 		moveMotorLeftBackwards(mem);
	MOVLW      22
	MOVWF      R3+0
	MOVLW      FARG_move_moveMotorLeftBackwards_mem+0
	MOVWF      R2+0
	MOVLW      FARG_moveBackwards_mem+0
	MOVWF      R1+0
L_moveBackwards3:
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
	GOTO       L_moveBackwards3
	CALL       move_moveMotorLeftBackwards+0
;move.c,58 :: 		}
	RETURN
; end of _moveBackwards

_moveStops:

;move.c,60 :: 		void moveStops(outputs mem) {
;move.c,61 :: 		moveMotorRightStops(mem);
	MOVLW      22
	MOVWF      R3+0
	MOVLW      FARG_move_moveMotorRightStops_mem+0
	MOVWF      R2+0
	MOVLW      FARG_moveStops_mem+0
	MOVWF      R1+0
L_moveStops4:
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
	GOTO       L_moveStops4
	CALL       move_moveMotorRightStops+0
;move.c,62 :: 		moveMotorLeftStops(mem);
	MOVLW      22
	MOVWF      R3+0
	MOVLW      FARG_move_moveMotorLeftStops_mem+0
	MOVWF      R2+0
	MOVLW      FARG_moveStops_mem+0
	MOVWF      R1+0
L_moveStops5:
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
	GOTO       L_moveStops5
	CALL       move_moveMotorLeftStops+0
;move.c,63 :: 		}
	RETURN
; end of _moveStops

_moveTurnsRight:

;move.c,65 :: 		void moveTurnsRight(outputs mem) {
;move.c,66 :: 		moveMotorRightBackwards(mem);
	MOVLW      22
	MOVWF      R3+0
	MOVLW      FARG_move_moveMotorRightBackwards_mem+0
	MOVWF      R2+0
	MOVLW      FARG_moveTurnsRight_mem+0
	MOVWF      R1+0
L_moveTurnsRight6:
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
	GOTO       L_moveTurnsRight6
	CALL       move_moveMotorRightBackwards+0
;move.c,67 :: 		moveMotorLeftForwards(mem);
	MOVLW      22
	MOVWF      R3+0
	MOVLW      FARG_move_moveMotorLeftForwards_mem+0
	MOVWF      R2+0
	MOVLW      FARG_moveTurnsRight_mem+0
	MOVWF      R1+0
L_moveTurnsRight7:
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
	GOTO       L_moveTurnsRight7
	CALL       move_moveMotorLeftForwards+0
;move.c,68 :: 		}
	RETURN
; end of _moveTurnsRight

_moveTurnsLeft:

;move.c,70 :: 		void moveTurnsLeft(outputs mem) {
;move.c,71 :: 		moveMotorRightForwards(mem);
	MOVLW      22
	MOVWF      R3+0
	MOVLW      FARG_move_moveMotorRightForwards_mem+0
	MOVWF      R2+0
	MOVLW      FARG_moveTurnsLeft_mem+0
	MOVWF      R1+0
L_moveTurnsLeft8:
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
	GOTO       L_moveTurnsLeft8
	CALL       move_moveMotorRightForwards+0
;move.c,72 :: 		moveMotorLeftBackwards(mem);
	MOVLW      22
	MOVWF      R3+0
	MOVLW      FARG_move_moveMotorLeftBackwards_mem+0
	MOVWF      R2+0
	MOVLW      FARG_moveTurnsLeft_mem+0
	MOVWF      R1+0
L_moveTurnsLeft9:
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
	GOTO       L_moveTurnsLeft9
	CALL       move_moveMotorLeftBackwards+0
;move.c,73 :: 		}
	RETURN
; end of _moveTurnsLeft
