
_main:

;auto-mode.c,25 :: 		void main() {
;auto-mode.c,27 :: 		int i = 0;
	CLRF       main_i_L0+0
	CLRF       main_i_L0+1
;auto-mode.c,30 :: 		OPTION_REG = 0x87;
	MOVLW      135
	MOVWF      OPTION_REG+0
;auto-mode.c,32 :: 		INTCON = 0xA0;
	MOVLW      160
	MOVWF      INTCON+0
;auto-mode.c,35 :: 		TRISC = 0;
	CLRF       TRISC+0
;auto-mode.c,36 :: 		PORTC = 0;
	CLRF       PORTC+0
;auto-mode.c,38 :: 		TRISD = 0;
	CLRF       TRISD+0
;auto-mode.c,39 :: 		PORTD = 0;
	CLRF       PORTD+0
;auto-mode.c,42 :: 		TRISB = 0b11111111;
	MOVLW      255
	MOVWF      TRISB+0
;auto-mode.c,45 :: 		while (!bSTART);
L_main0:
	BTFSC      PORTB+0, 7
	GOTO       L_main1
	GOTO       L_main0
L_main1:
;auto-mode.c,48 :: 		while (1) {
L_main2:
;auto-mode.c,49 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;auto-mode.c,50 :: 		LED1 = i % 2;
	MOVLW      2
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       main_i_L0+0, 0
	MOVWF      R0+0
	MOVF       main_i_L0+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	BTFSC      R0+0, 0
	GOTO       L__main12
	BCF        PORTC+0, 0
	GOTO       L__main13
L__main12:
	BSF        PORTC+0, 0
L__main13:
;auto-mode.c,51 :: 		Delay_ms(delay);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main4:
	DECFSZ     R13+0, 1
	GOTO       L_main4
	DECFSZ     R12+0, 1
	GOTO       L_main4
	DECFSZ     R11+0, 1
	GOTO       L_main4
	NOP
	NOP
;auto-mode.c,52 :: 		LED2 = i % 2;
	MOVLW      2
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       main_i_L0+0, 0
	MOVWF      R0+0
	MOVF       main_i_L0+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	BTFSC      R0+0, 0
	GOTO       L__main14
	BCF        PORTC+0, 1
	GOTO       L__main15
L__main14:
	BSF        PORTC+0, 1
L__main15:
;auto-mode.c,53 :: 		Delay_ms(delay);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main5:
	DECFSZ     R13+0, 1
	GOTO       L_main5
	DECFSZ     R12+0, 1
	GOTO       L_main5
	DECFSZ     R11+0, 1
	GOTO       L_main5
	NOP
	NOP
;auto-mode.c,54 :: 		LED3 = i % 2;
	MOVLW      2
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       main_i_L0+0, 0
	MOVWF      R0+0
	MOVF       main_i_L0+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	BTFSC      R0+0, 0
	GOTO       L__main16
	BCF        PORTC+0, 2
	GOTO       L__main17
L__main16:
	BSF        PORTC+0, 2
L__main17:
;auto-mode.c,55 :: 		Delay_ms(delay);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main6:
	DECFSZ     R13+0, 1
	GOTO       L_main6
	DECFSZ     R12+0, 1
	GOTO       L_main6
	DECFSZ     R11+0, 1
	GOTO       L_main6
	NOP
	NOP
;auto-mode.c,56 :: 		LED4 = i % 2;
	MOVLW      2
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       main_i_L0+0, 0
	MOVWF      R0+0
	MOVF       main_i_L0+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	BTFSC      R0+0, 0
	GOTO       L__main18
	BCF        PORTC+0, 3
	GOTO       L__main19
L__main18:
	BSF        PORTC+0, 3
L__main19:
;auto-mode.c,57 :: 		Delay_ms(delay);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main7:
	DECFSZ     R13+0, 1
	GOTO       L_main7
	DECFSZ     R12+0, 1
	GOTO       L_main7
	DECFSZ     R11+0, 1
	GOTO       L_main7
	NOP
	NOP
;auto-mode.c,58 :: 		LED5 = i % 2;
	MOVLW      2
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       main_i_L0+0, 0
	MOVWF      R0+0
	MOVF       main_i_L0+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	BTFSC      R0+0, 0
	GOTO       L__main20
	BCF        PORTC+0, 4
	GOTO       L__main21
L__main20:
	BSF        PORTC+0, 4
L__main21:
;auto-mode.c,59 :: 		Delay_ms(delay);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main8:
	DECFSZ     R13+0, 1
	GOTO       L_main8
	DECFSZ     R12+0, 1
	GOTO       L_main8
	DECFSZ     R11+0, 1
	GOTO       L_main8
	NOP
	NOP
;auto-mode.c,60 :: 		LED6 = i % 2;
	MOVLW      2
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       main_i_L0+0, 0
	MOVWF      R0+0
	MOVF       main_i_L0+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	BTFSC      R0+0, 0
	GOTO       L__main22
	BCF        PORTC+0, 5
	GOTO       L__main23
L__main22:
	BSF        PORTC+0, 5
L__main23:
;auto-mode.c,61 :: 		Delay_ms(delay);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main9:
	DECFSZ     R13+0, 1
	GOTO       L_main9
	DECFSZ     R12+0, 1
	GOTO       L_main9
	DECFSZ     R11+0, 1
	GOTO       L_main9
	NOP
	NOP
;auto-mode.c,62 :: 		LED7 = i % 2;
	MOVLW      2
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       main_i_L0+0, 0
	MOVWF      R0+0
	MOVF       main_i_L0+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	BTFSC      R0+0, 0
	GOTO       L__main24
	BCF        PORTC+0, 6
	GOTO       L__main25
L__main24:
	BSF        PORTC+0, 6
L__main25:
;auto-mode.c,63 :: 		Delay_ms(delay);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main10:
	DECFSZ     R13+0, 1
	GOTO       L_main10
	DECFSZ     R12+0, 1
	GOTO       L_main10
	DECFSZ     R11+0, 1
	GOTO       L_main10
	NOP
	NOP
;auto-mode.c,64 :: 		LED8 = i % 2;
	MOVLW      2
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       main_i_L0+0, 0
	MOVWF      R0+0
	MOVF       main_i_L0+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	BTFSC      R0+0, 0
	GOTO       L__main26
	BCF        PORTC+0, 7
	GOTO       L__main27
L__main26:
	BSF        PORTC+0, 7
L__main27:
;auto-mode.c,65 :: 		Delay_ms(delay);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main11:
	DECFSZ     R13+0, 1
	GOTO       L_main11
	DECFSZ     R12+0, 1
	GOTO       L_main11
	DECFSZ     R11+0, 1
	GOTO       L_main11
	NOP
	NOP
;auto-mode.c,66 :: 		}
	GOTO       L_main2
;auto-mode.c,67 :: 		}
	GOTO       $+0
; end of _main
