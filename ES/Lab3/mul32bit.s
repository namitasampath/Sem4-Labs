/*
Write an assembly program to multiply two 32 bit numbers.
*/
    
    AREA    RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0X40001000
    DCD Reset_Handler
    ALIGN
    AREA mycode, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler
Reset_Handler
    LDR R0, =VALUE1
    LDR R1,[R0]
    LDR R0,=VALUE2
    LDR R2,[R0]
    UMULL R3,R4,R2,R1
    LDR R2,=RESULT
    STR R4,[R2]
    ADD R2,#4
    STR R3,[R2]
STOP
    B STOP
VALUE1 DCD 0X54000000
VALUE2 DCD 0X10000002
    AREA    data, DATA, READWRITE
RESULT DCD 0
    END
