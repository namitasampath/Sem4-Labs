    AREA    RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0X40001000
    DCD Reset_Handler
    ALIGN
    AREA ascend, code, readonly
    ENTRY
    EXPORT Reset_Handler
Reset_Handler
    MOV R4,#0
    MOV R1,#10
    LDR R0,=LIST
    LDR R2,=RESULT
up  LDR R3,[R0,R4]
    STR R3,[R2,R4]
    ADD R4,#04
    SUB R1,#01
    CMP R1,#01
    bhi up
    LDR R0,=result
    MOV R3,#10
    SUB R3,R3,#1
    MOV R9,R3
OUTER_LOOP
    MOV R5,R0
    MOV R4,R3
INNER_LOOP
    LDR R6,[R5],#4
    LDR R7,[R5]
    CMP R7,R6
    STRLS R6,[R5]
    STRLS R7,[R5,#-4]
    SUBS R4,R4, #1
    BNE INNER_LOOP
    SUB R3, #1
    SUBS R9, R9, #1
    BNE OUTER_LOOP
LIST dcd 0x10, 0x05, 0x33, 0x24, 0x56, 0x77, 0x21, 0x04, 0x87,0x01
    AREA data1, data, readwrite
result DCW 0,0,0,0,0,0,0,0,0,0
    END
