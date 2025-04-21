;Find the sum of n natural numbers using MLA instruction

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
    MOV R0,#VALUEN 
    MOV R1, #0 
    MOV R3, #1 
    LDR R4, =RESULT 
LOOP MLA R1, R1, R3, R0 
        SUBS R0, R0, #1 
        BNE LOOP 
    STR R1, [R4] 
STOP 
    B STOP 
    VALUEN EQU 10 
    AREA data, DATA, READWRITE 
RESULT DCD 0 
END 
