#line 1 "C:/Documents and Settings/swordofpain/Mes documents/Work/auto-mode/auto-mode.c"
#line 1 "c:/documents and settings/swordofpain/mes documents/work/auto-mode/inc/physical.h"
#line 20 "C:/Documents and Settings/swordofpain/Mes documents/Work/auto-mode/auto-mode.c"
void main() {
 OPTION_REG = 0x87;
 INTCON = 0xA0;

 TRISA = 0;
 PORTA = 0;
 TRISB = 0b111111;
 TRISD = 0;
 PORTD = 0;

 while (1) {
  PORTD.F0  =  PORTD.F1  =  PORTD.F2  = 1;
 }
}
[ACTIVE_TAB]
Value=auto-mode.c
[DEVICE]
Name=P16F877A
Clock=8000000
[MEMORY_MODEL]
Value=0
[BUILD_TYPE]
Value=0
[USE_EEPROM]
Value=0
[EEPROM_DEFINITION]
Value=
[FILES]
Count=0
[BINARIES]
Count=0
[IMAGES]
Count=0
[OPENED_FILES]
Count=1
File0=auto-mode.c
[OTHER_FILES]
Count=0
[SEARCH_PATH]
Count=3
Path0=C:\Program Files\Mikroelektronika\mikroC PRO for PIC\defs\
Path1=C:\Program Files\Mikroelektronika\mikroC PRO for PIC\Uses\P16\
Path2=C:\Documents and Settings\swordofpain\Mes documents\Work\auto-mode\
[HEADER_PATH]
Count=0
[HEADERS]
Count=0
[PLDS]
Count=0
[Useses]
Count=0
