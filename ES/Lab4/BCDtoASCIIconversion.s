;;Packed BCD to ASCII conversion

    AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x40001000 ; stack pointer value when stack is empty
    DCD Reset_Handler ; reset vector
    ALIGN
    AREA mycode, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler
Reset_Handler
    MOV R0,#0x29
    AND R1,R0,#0x0F ;mask upper four bits
    ORR R1,R1,#0x30 ;combine with 30 to get ASCII
    MOV R2,R0,LSR #04 ;shift right 4 bits to get unpacked BCD
    ORR R2,R2,#0x30 ;combine with 30 to get ASCII
STOP
    B STOP
END
