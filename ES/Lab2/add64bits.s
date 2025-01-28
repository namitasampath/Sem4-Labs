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
    LDR r0, =number1
    LDR r1, =number2
    LDR r2, =result

    LDR r3,[r0],#4
    LDR r4,[r1],#4
    ADDS r5, r3,r4
    STR r5,[r2],#4

    LDR r3,[r0],#4
    LDR r4,[r1],#4
    ADDS r5, r3,r4
    STR r5,[r2],#4
STOP
    B STOP

number1 DCD 0x11223344, 0x55667788
number2 DCD 0x00112233, 0x44556677
    AREA mydata, DATA, READWRITE
result DCD 0,0
    END
