;;1. Write a program to multiply two 32 bit numbers using repetitive addition

AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x10001000
    DCD Reset_Handler
    ALIGN
    AREA mycode, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler
Reset_Handler
    LDR R1, =VALUE1
    LDR R5, [R1]
    LDR R2, =VALUE2
    LDR R6, [R2]
    MOV R3, #0
    MOV R7, #0
    LDR R4, =RESULT
    LDR R8, =CARRY
LOOP ADDS R3, R3, R5
    ADC R7, R7, #0
    SUBS R6, R6, #1
    BNE LOOP
    STR R3, [R4]
    STR R7, [R8]
STOP
    B STOP
VALUE1 DCD 0X78000000
VALUE2 DCD 0X00000004
    AREA data, DATA, READWRITE
RESULT DCD 0
CARRY DCD 0
END
