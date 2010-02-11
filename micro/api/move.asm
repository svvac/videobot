
move_moveMotorRightForwards:

;move.c,20 :: 		static void moveMotorRightForwards(outputs *mem) {
;move.c,21 :: 		mem->motorRForw = 1;
	MOVLW      14
	ADDWF      FARG_move_moveMotorRightForwards_mem+0, 0
	MOVWF      FSR
	MOVLW      1
	MOVWF      INDF+0
	MOVLW      0
	INCF       FSR, 1
	MOVWF      INDF+0
;move.c,22 :: 		mem->motorRBackw = 0;
	MOVLW      16
	ADDWF      FARG_move_moveMotorRightForwards_mem+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;move.c,23 :: 		}
	RETURN
; end of move_moveMotorRightForwards

move_moveMotorRightBackwards:

;move.c,25 :: 		static void moveMotorRightBackwards(outputs *mem) {
;move.c,26 :: 		mem->motorRForw = 0;
	MOVLW      14
	ADDWF      FARG_move_moveMotorRightBackwards_mem+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;move.c,27 :: 		mem->motorRBackw = 1;
	MOVLW      16
	ADDWF      FARG_move_moveMotorRightBackwards_mem+0, 0
	MOVWF      FSR
	MOVLW      1
	MOVWF      INDF+0
	MOVLW      0
	INCF       FSR, 1
	MOVWF      INDF+0
;move.c,28 :: 		}
	RETURN
; end of move_moveMotorRightBackwards

move_moveMotorRightStops:

;move.c,30 :: 		static void moveMotorRightStops(outputs *mem) {
;move.c,31 :: 		mem->motorRForw = 0;
	MOVLW      14
	ADDWF      FARG_move_moveMotorRightStops_mem+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;move.c,32 :: 		mem->motorRBackw = 0;
	MOVLW      16
	ADDWF      FARG_move_moveMotorRightStops_mem+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;move.c,33 :: 		}
	RETURN
; end of move_moveMotorRightStops

move_moveMotorLeftBackwards:

;move.c,35 :: 		static void moveMotorLeftBackwards(outputs *mem) {
;move.c,36 :: 		mem->motorLForw = 0;
	MOVLW      18
	ADDWF      FARG_move_moveMotorLeftBackwards_mem+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;move.c,37 :: 		mem->motorLBackw = 1;
	MOVLW      20
	ADDWF      FARG_move_moveMotorLeftBackwards_mem+0, 0
	MOVWF      FSR
	MOVLW      1
	MOVWF      INDF+0
	MOVLW      0
	INCF       FSR, 1
	MOVWF      INDF+0
;move.c,38 :: 		}
	RETURN
; end of move_moveMotorLeftBackwards

move_moveMotorLeftForwards:

;move.c,39 :: 		static void moveMotorLeftForwards(outputs *mem) {
;move.c,40 :: 		mem->motorLForw = 1;
	MOVLW      18
	ADDWF      FARG_move_moveMotorLeftForwards_mem+0, 0
	MOVWF      FSR
	MOVLW      1
	MOVWF      INDF+0
	MOVLW      0
	INCF       FSR, 1
	MOVWF      INDF+0
;move.c,41 :: 		mem->motorLBackw = 0;
	MOVLW      20
	ADDWF      FARG_move_moveMotorLeftForwards_mem+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;move.c,42 :: 		}
	RETURN
; end of move_moveMotorLeftForwards

move_moveMotorLeftStops:

;move.c,44 :: 		static void moveMotorLeftStops(outputs *mem) {
;move.c,45 :: 		mem->motorLForw = 0;
	MOVLW      18
	ADDWF      FARG_move_moveMotorLeftStops_mem+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;move.c,46 :: 		mem->motorLBackw = 0;
	MOVLW      20
	ADDWF      FARG_move_moveMotorLeftStops_mem+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;move.c,47 :: 		}
	RETURN
; end of move_moveMotorLeftStops

_moveForwards:

;move.c,49 :: 		void moveForwards(outputs *mem) {
;move.c,50 :: 		moveMotorRightForwards(mem);
	MOVF       FARG_moveForwards_mem+0, 0
	MOVWF      FARG_move_moveMotorRightForwards_mem+0
	CALL       move_moveMotorRightForwards+0
;move.c,51 :: 		moveMotorLeftForwards(mem);
	MOVF       FARG_moveForwards_mem+0, 0
	MOVWF      FARG_move_moveMotorLeftForwards_mem+0
	CALL       move_moveMotorLeftForwards+0
;move.c,52 :: 		}
	RETURN
; end of _moveForwards

_moveBackwards:

;move.c,54 :: 		void moveBackwards(outputs *mem) {
;move.c,55 :: 		moveMotorRightBackwards(mem);
	MOVF       FARG_moveBackwards_mem+0, 0
	MOVWF      FARG_move_moveMotorRightBackwards_mem+0
	CALL       move_moveMotorRightBackwards+0
;move.c,56 :: 		moveMotorLeftBackwards(mem);
	MOVF       FARG_moveBackwards_mem+0, 0
	MOVWF      FARG_move_moveMotorLeftBackwards_mem+0
	CALL       move_moveMotorLeftBackwards+0
;move.c,57 :: 		}
	RETURN
; end of _moveBackwards

_moveStops:

;move.c,59 :: 		void moveStops(outputs *mem) {
;move.c,60 :: 		moveMotorRightStops(mem);
	MOVF       FARG_moveStops_mem+0, 0
	MOVWF      FARG_move_moveMotorRightStops_mem+0
	CALL       move_moveMotorRightStops+0
;move.c,61 :: 		moveMotorLeftStops(mem);
	MOVF       FARG_moveStops_mem+0, 0
	MOVWF      FARG_move_moveMotorLeftStops_mem+0
	CALL       move_moveMotorLeftStops+0
;move.c,62 :: 		}
	RETURN
; end of _moveStops

_moveTurnsRight:

;move.c,64 :: 		void moveTurnsRight(outputs *mem) {
;move.c,65 :: 		moveMotorRightBackwards(mem);
	MOVF       FARG_moveTurnsRight_mem+0, 0
	MOVWF      FARG_move_moveMotorRightBackwards_mem+0
	CALL       move_moveMotorRightBackwards+0
;move.c,66 :: 		moveMotorLeftForwards(mem);
	MOVF       FARG_moveTurnsRight_mem+0, 0
	MOVWF      FARG_move_moveMotorLeftForwards_mem+0
	CALL       move_moveMotorLeftForwards+0
;move.c,67 :: 		}
	RETURN
; end of _moveTurnsRight

_moveTurnsLeft:

;move.c,69 :: 		void moveTurnsLeft(outputs *mem) {
;move.c,70 :: 		moveMotorRightForwards(mem);
	MOVF       FARG_moveTurnsLeft_mem+0, 0
	MOVWF      FARG_move_moveMotorRightForwards_mem+0
	CALL       move_moveMotorRightForwards+0
;move.c,71 :: 		moveMotorLeftBackwards(mem);
	MOVF       FARG_moveTurnsLeft_mem+0, 0
	MOVWF      FARG_move_moveMotorLeftBackwards_mem+0
	CALL       move_moveMotorLeftBackwards+0
;move.c,72 :: 		}
	RETURN
; end of _moveTurnsLeft
