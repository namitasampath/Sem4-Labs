    AREA RESET, DATA, READONLY 
    EXPORT __Vectors 
__Vectors 
    DCD 0x40001000  
    DCD Reset_Handler  
    ALIGN 
    AREA mycode, CODE, READONLY 
    ENTRY 
    EXPORT Reset_Handler 
Reset_Handler 
    LDR R0, =VALUE1 
    LDR R1, [R0] 
    LDR R2, =VALUE2 
    LDR R3, [R2] 
    LDR R4, =RESULT 
LOOP 
    CMP R1, R3 
    BEQ DONE 
    BGT GREATER 
    SUBS R1, R3, R1 
    B LOOP 
GREATER 
    SUBS R3, R1, R3 
    B LOOP 
DONE  
    STR R1, [R4]
STOP 
    B STOP 
VALUE1 DCD 0x0000000C 
VALUE2 DCD 0x00000006 
    AREA data, DATA, READWRITE 
RESULT DCD 0 
END 
