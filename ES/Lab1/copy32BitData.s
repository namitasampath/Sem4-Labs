/*
Write an ARM assembly language program to copy 32 bit data from code memory to data memory.
Source- SRC= 0X00000008 at location pointed by R0
Destination - DST = 0X00000008 at location pointed by R1 after execution
*/

    AREA    RESET, DATA, READONLY
    EXPORT _Vectors
__Vectors
    DCD 0X10001000
    DCD Reset_Handler
    ALIGN
    AREA mycode, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler
Reset_Handler
    LDR R0,=SRC
    LDR R1,=DST
    LDR R3,[R0]
    STR R3,[R1]
STOP
    B STOP;
SRC
    DCD 8
    AREA mydata, DATA, READWRITE
DST
    DCD 0
END
