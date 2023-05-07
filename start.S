.global _start
_start:
    @ turn off watch dog
    ldr r0, =0x53000000
    mov r1, #0
    str r1, [r0]
    @ set clock
    ldr r0, =0x4C000014     @ clock divider control reigster
    ldr r1, =(2<<1)|1
    str r1, [r0]
    mrc p15,0,r0,c1,c0,0    @ MMU_SetAsyncBusMode
    orr r0,r0, #0xc0000000     @ #R1_nF:OR:R1_iA
    mcr p15,0,r0,c1,c0,0
    ldr r0, =0x4C000004     @ MPLL control register
    ldr r1, =(0x7f << 12)|(2 << 4)|1
    str r1, [r0]
    @ init uart
    ldr r0, =0x56000070 @ gpio h control register
    ldr r1, =(2 << 4)|(2 << 6)
    str r1, [r0]
    ldr r0, =0x50000000
    ldr r1, =3
    @ init sdram

    @ init stack pointer, auto adjust norflash and nand flash
    mov r5, #0
    ldr r0, [r5]
    add r1, r0, #1
    str r1, [r5]
    ldr r2, [r5]
    cmp r2, r1
    ldr sp, =0x40000000+4096
    moveq sp, #4096
    streq r0, [r5]


    @ branch main
    bl main

here:   b   here
