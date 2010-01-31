#line 1 "S:/videobot/micro/auto-mode/auto-mode.c"
#line 1 "s:/videobot/micro/auto-mode/inc/io.h"
#line 25 "S:/videobot/micro/auto-mode/auto-mode.c"
void main() {
 const int delay = 500;
 int i = 0;


 OPTION_REG = 0x87;

 INTCON = 0xA0;


 TRISC = 0;
 PORTC = 0;

 TRISD = 0;
 PORTD = 0;


 TRISB = 0b11111111;


 while (! PORTB.F7 );


 while (1) {
 i++;
  PORTC.F0  = i % 2;
 Delay_ms(delay);
  PORTC.F1  = i % 2;
 Delay_ms(delay);
  PORTC.F2  = i % 2;
 Delay_ms(delay);
  PORTC.F3  = i % 2;
 Delay_ms(delay);
  PORTC.F4  = i % 2;
 Delay_ms(delay);
  PORTC.F5  = i % 2;
 Delay_ms(delay);
  PORTC.F6  = i % 2;
 Delay_ms(delay);
  PORTC.F7  = i % 2;
 Delay_ms(delay);
 }
}
