#line 1 "C:/users/swordofpain/My Documents/Work/projects/videobot/micro/auto-mode/auto-mode.c"
#line 27 "C:/users/swordofpain/My Documents/Work/projects/videobot/micro/auto-mode/auto-mode.c"
void main() {
TRISC=0b11111111;
TRISB=0b00000000;
PORTB=0b00000000;
while(1) {
PORTC.F0=1;
}
}
[DEVICE]
Name=P16F877A
Clock=8000000
[FILES]
Count=1
File0=auto-mode.c
[BINARIES]
Count=0
[IMAGES]
Count=0
[OPENED_FILES]
Count=4
File0=auto-mode.c
File1=..\..\..\..\..\tmp\Gestion Des Cycles et Modes\GDCM\GDCM.c
File2=..\..\..\..\..\tmp\Gestion Des Cycles et Modes\GDCM\INCLUDES\DVP.h
File3=..\..\..\..\..\tmp\Gestion Des Cycles et Modes\GDCM\INCLUDES\GDCM.h
[OTHER_FILES]
Count=0
[SEARCH_PATH]
Count=3
Path0=C:\Program Files\Mikroelektronika\mikroC PRO for PIC\defs\
Path1=C:\Program Files\Mikroelektronika\mikroC PRO for PIC\Uses\P16\
Path2=C:\users\swordofpain\My Documents\Work\projects\videobot\micro\auto-mode\
[HEADER_PATH]
Count=0
[HEADERS]
Count=0
[PLDS]
Count=0
[Useses]
Count=0
[MEMORY_MODEL]
Value=0
[BUILD_TYPE]
Value=0
[ACTIVE_TAB]
Value=NewUnit
[USE_EEPROM]
Value=0
[EEPROM_DEFINITION]
Value=
