
move_motorSteps:

;move.c,22 :: 		static int motorSteps(int mod) {
;move.c,25 :: 		if (mod > 0) {
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      FARG_move_motorSteps_mod+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L_move_motorSteps2
	MOVF       FARG_move_motorSteps_mod+0, 0
	SUBLW      0
L_move_motorSteps2:
	BTFSC      STATUS+0, 0
	GOTO       L_move_motorSteps0
;move.c,26 :: 		count = (count + 1) % mod;
	MOVF       move_motorSteps_count_L0+0, 0
	ADDLW      1
	MOVWF      R0+0
	MOVLW      0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      move_motorSteps_count_L0+1, 0
	MOVWF      R0+1
	MOVF       FARG_move_motorSteps_mod+0, 0
	MOVWF      R4+0
	MOVF       FARG_move_motorSteps_mod+1, 0
	MOVWF      R4+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      move_motorSteps_count_L0+0
	MOVF       R0+1, 0
	MOVWF      move_motorSteps_count_L0+1
;move.c,27 :: 		if (count == 0) {
	MOVLW      0
	XORWF      R0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L_move_motorSteps3
	MOVLW      0
	XORWF      R0+0, 0
L_move_motorSteps3:
	BTFSS      STATUS+0, 2
	GOTO       L_move_motorSteps1
;move.c,28 :: 		step = (step + 1) % STEPPER_PHASES_NB;
	MOVF       move_motorSteps_step_L0+0, 0
	ADDLW      1
	MOVWF      R0+0
	MOVLW      0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      move_motorSteps_step_L0+1, 0
	MOVWF      R0+1
	MOVLW      8
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      move_motorSteps_step_L0+0
	MOVF       R0+1, 0
	MOVWF      move_motorSteps_step_L0+1
;move.c,29 :: 		}
L_move_motorSteps1:
;move.c,30 :: 		}
L_move_motorSteps0:
;move.c,31 :: 		return step;
	MOVF       move_motorSteps_step_L0+0, 0
	MOVWF      R0+0
	MOVF       move_motorSteps_step_L0+1, 0
	MOVWF      R0+1
;move.c,32 :: 		}
	RETURN
; end of move_motorSteps

move_moveMotorRightForwards:

;move.c,34 :: 		static void moveMotorRightForwards(outputs *mem) {
;move.c,35 :: 		PORTC = stepperPhases[motorSteps(-1)];
	MOVLW      255
	MOVWF      FARG_move_motorSteps_mod+0
	MOVLW      255
	MOVWF      FARG_move_motorSteps_mod+1
	CALL       move_motorSteps+0
	MOVF       R0+0, 0
	MOVWF      R2+0
	MOVF       R0+1, 0
	MOVWF      R2+1
	RLF        R2+0, 1
	RLF        R2+1, 1
	BCF        R2+0, 0
	MOVF       R2+0, 0
	ADDLW      move_stepperPhases+0
	MOVWF      R0+0
	MOVLW      hi_addr(move_stepperPhases+0)
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      R2+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       R0+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoICP+0
	MOVWF      PORTC+0
;move.c,36 :: 		}
	RETURN
; end of move_moveMotorRightForwards

move_moveMotorRightBackwards:

;move.c,38 :: 		static void moveMotorRightBackwards(outputs *mem) {
;move.c,39 :: 		PORTC = stepperPhases[7 - motorSteps(-1)];
	MOVLW      255
	MOVWF      FARG_move_motorSteps_mod+0
	MOVLW      255
	MOVWF      FARG_move_motorSteps_mod+1
	CALL       move_motorSteps+0
	MOVF       R0+0, 0
	SUBLW      7
	MOVWF      R3+0
	MOVF       R0+1, 0
	BTFSS      STATUS+0, 0
	ADDLW      1
	CLRF       R3+1
	SUBWF      R3+1, 1
	MOVF       R3+0, 0
	MOVWF      R0+0
	MOVF       R3+1, 0
	MOVWF      R0+1
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	MOVLW      move_stepperPhases+0
	ADDWF      R0+0, 1
	MOVLW      hi_addr(move_stepperPhases+0)
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      R0+1, 1
	MOVF       R0+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       R0+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoICP+0
	MOVWF      PORTC+0
;move.c,40 :: 		}
	RETURN
; end of move_moveMotorRightBackwards

move_moveMotorRightStops:

;move.c,42 :: 		static void moveMotorRightStops(outputs *mem) {
;move.c,43 :: 		mem->motorRForw = 0;
	MOVLW      14
	ADDWF      FARG_move_moveMotorRightStops_mem+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;move.c,44 :: 		mem->motorRBackw = 0;
	MOVLW      16
	ADDWF      FARG_move_moveMotorRightStops_mem+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;move.c,45 :: 		}
	RETURN
; end of move_moveMotorRightStops

move_moveMotorLeftBackwards:

;move.c,47 :: 		static void moveMotorLeftBackwards(outputs *mem) {
;move.c,48 :: 		mem->motorLForw = 0;
	MOVLW      18
	ADDWF      FARG_move_moveMotorLeftBackwards_mem+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;move.c,49 :: 		mem->motorLBackw = 1;
	MOVLW      20
	ADDWF      FARG_move_moveMotorLeftBackwards_mem+0, 0
	MOVWF      FSR
	MOVLW      1
	MOVWF      INDF+0
	MOVLW      0
	INCF       FSR, 1
	MOVWF      INDF+0
;move.c,50 :: 		}
	RETURN
; end of move_moveMotorLeftBackwards

move_moveMotorLeftForwards:

;move.c,51 :: 		static void moveMotorLeftForwards(outputs *mem) {
;move.c,52 :: 		mem->motorLForw = 1;
	MOVLW      18
	ADDWF      FARG_move_moveMotorLeftForwards_mem+0, 0
	MOVWF      FSR
	MOVLW      1
	MOVWF      INDF+0
	MOVLW      0
	INCF       FSR, 1
	MOVWF      INDF+0
;move.c,53 :: 		mem->motorLBackw = 0;
	MOVLW      20
	ADDWF      FARG_move_moveMotorLeftForwards_mem+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;move.c,54 :: 		}
	RETURN
; end of move_moveMotorLeftForwards

move_moveMotorLeftStops:

;move.c,56 :: 		static void moveMotorLeftStops(outputs *mem) {
;move.c,57 :: 		mem->motorLForw = 0;
	MOVLW      18
	ADDWF      FARG_move_moveMotorLeftStops_mem+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;move.c,58 :: 		mem->motorLBackw = 0;
	MOVLW      20
	ADDWF      FARG_move_moveMotorLeftStops_mem+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;move.c,59 :: 		}
	RETURN
; end of move_moveMotorLeftStops

_moveForwards:

;move.c,61 :: 		void moveForwards(outputs *mem) {
;move.c,62 :: 		motorSteps(stepperBase);
	MOVF       _stepperBase+0, 0
	MOVWF      FARG_move_motorSteps_mod+0
	MOVF       _stepperBase+1, 0
	MOVWF      FARG_move_motorSteps_mod+1
	CALL       move_motorSteps+0
;move.c,63 :: 		moveMotorRightForwards(mem);
	MOVF       FARG_moveForwards_mem+0, 0
	MOVWF      FARG_move_moveMotorRightForwards_mem+0
	CALL       move_moveMotorRightForwards+0
;move.c,65 :: 		}
	RETURN
; end of _moveForwards

_moveBackwards:

;move.c,67 :: 		void moveBackwards(outputs *mem) {
;move.c,68 :: 		motorSteps(stepperBase);
	MOVF       _stepperBase+0, 0
	MOVWF      FARG_move_motorSteps_mod+0
	MOVF       _stepperBase+1, 0
	MOVWF      FARG_move_motorSteps_mod+1
	CALL       move_motorSteps+0
;move.c,69 :: 		moveMotorRightBackwards(mem);
	MOVF       FARG_moveBackwards_mem+0, 0
	MOVWF      FARG_move_moveMotorRightBackwards_mem+0
	CALL       move_moveMotorRightBackwards+0
;move.c,71 :: 		}
	RETURN
; end of _moveBackwards

_moveStops:

;move.c,73 :: 		void moveStops(outputs *mem) {
;move.c,74 :: 		motorSteps(stepperBase);
	MOVF       _stepperBase+0, 0
	MOVWF      FARG_move_motorSteps_mod+0
	MOVF       _stepperBase+1, 0
	MOVWF      FARG_move_motorSteps_mod+1
	CALL       move_motorSteps+0
;move.c,75 :: 		moveMotorRightStops(mem);
	MOVF       FARG_moveStops_mem+0, 0
	MOVWF      FARG_move_moveMotorRightStops_mem+0
	CALL       move_moveMotorRightStops+0
;move.c,76 :: 		moveMotorLeftStops(mem);
	MOVF       FARG_moveStops_mem+0, 0
	MOVWF      FARG_move_moveMotorLeftStops_mem+0
	CALL       move_moveMotorLeftStops+0
;move.c,77 :: 		}
	RETURN
; end of _moveStops

_moveTurnsRight:

;move.c,79 :: 		void moveTurnsRight(outputs *mem) {
;move.c,80 :: 		motorSteps(stepperBase);
	MOVF       _stepperBase+0, 0
	MOVWF      FARG_move_motorSteps_mod+0
	MOVF       _stepperBase+1, 0
	MOVWF      FARG_move_motorSteps_mod+1
	CALL       move_motorSteps+0
;move.c,81 :: 		moveMotorRightBackwards(mem);
	MOVF       FARG_moveTurnsRight_mem+0, 0
	MOVWF      FARG_move_moveMotorRightBackwards_mem+0
	CALL       move_moveMotorRightBackwards+0
;move.c,82 :: 		moveMotorLeftForwards(mem);
	MOVF       FARG_moveTurnsRight_mem+0, 0
	MOVWF      FARG_move_moveMotorLeftForwards_mem+0
	CALL       move_moveMotorLeftForwards+0
;move.c,83 :: 		}
	RETURN
; end of _moveTurnsRight

_moveTurnsLeft:

;move.c,85 :: 		void moveTurnsLeft(outputs *mem) {
;move.c,86 :: 		motorSteps(stepperBase);
	MOVF       _stepperBase+0, 0
	MOVWF      FARG_move_motorSteps_mod+0
	MOVF       _stepperBase+1, 0
	MOVWF      FARG_move_motorSteps_mod+1
	CALL       move_motorSteps+0
;move.c,87 :: 		moveMotorRightForwards(mem);
	MOVF       FARG_moveTurnsLeft_mem+0, 0
	MOVWF      FARG_move_moveMotorRightForwards_mem+0
	CALL       move_moveMotorRightForwards+0
;move.c,88 :: 		moveMotorLeftBackwards(mem);
	MOVF       FARG_moveTurnsLeft_mem+0, 0
	MOVWF      FARG_move_moveMotorLeftBackwards_mem+0
	CALL       move_moveMotorLeftBackwards+0
;move.c,89 :: 		}
	RETURN
; end of _moveTurnsLeft
