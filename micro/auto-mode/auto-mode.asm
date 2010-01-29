
_main:

;auto-mode.c,20 :: 		void main() {
;auto-mode.c,21 :: 		OPTION_REG = 0x87;
	MOVLW      135
	MOVWF      OPTION_REG+0
;auto-mode.c,22 :: 		INTCON = 0xA0;
	MOVLW      160
	MOVWF      INTCON+0
;auto-mode.c,24 :: 		TRISA = 0;
	CLRF       TRISA+0
;auto-mode.c,25 :: 		PORTA = 0;
	CLRF       PORTA+0
;auto-mode.c,26 :: 		TRISB = 0b111111;
	MOVLW      63
	MOVWF      TRISB+0
;auto-mode.c,27 :: 		TRISD = 0;
	CLRF       TRISD+0
;auto-mode.c,28 :: 		PORTD = 0;
	CLRF       PORTD+0
;auto-mode.c,30 :: 		while (1) {
L_main0:
;auto-mode.c,31 :: 		LED1 = LED2 = LED3 = 1;
	BSF        PORTD+0, 2
	BTFSC      PORTD+0, 2
	GOTO       L__main2
	BCF        PORTD+0, 1
	GOTO       L__main3
L__main2:
	BSF        PORTD+0, 1
L__main3:
	BTFSC      PORTD+0, 1
	GOTO       L__main4
	BCF        PORTD+0, 0
	GOTO       L__main5
L__main4:
	BSF        PORTD+0, 0
L__main5:
;auto-mode.c,32 :: 		}
	GOTO       L_main0
;auto-mode.c,33 :: 		}
	GOTO       $+0
; end of _main
