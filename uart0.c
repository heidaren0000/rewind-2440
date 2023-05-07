#include "uart0.h"
#include "address.h"

static char __UART_0_UP = 0;

void uart0_init() {
    GPHCON =(2 << 4)|(2 << 6);
    ULCON0 &= ~((1 << 2)|(3));
    ULCON0 |= (3) | (1 << 2);

    // UCON0 = 0;
    // let's just leave alone fifo and interrupts
    // just enable transimmter and reciver
    // and set baud rate
    // 1. clock selection 
    UCON0 &= ~((3 << 10) | (3 << 2) | (3));
    UCON0 |= ((1<<2)|(1)); // enable transimmter and receiver

    UMCON0 &= ~(1<<4);
    UMCON0 |= (1<<4);
    
    __UART_0_UP = 1;
}

void putc(char c) {
    while(!(UTRSTAT0&(1<<1))) {
    }
    UTXH0L = c;
}

char getc() {
    while(!(UTRSTAT0&(1))) {
    }
    char c = URXH0L;
    return c;
}

void puts(char * s){
    while(s) {
        putc(s);
        s++;
    }
}