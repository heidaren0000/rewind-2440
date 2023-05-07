/**
*        #####    ##   #####  ###### #    # 
*        #    #  #  #  #    # #      ##   # 
*        #    # #    # #    # #####  # #  # 
*        #    # ###### #####  #      #  # # 
*        #    # #    # #   #  #      #   ## 
*        #####  #    # #    # ###### #    # 
*/


#ifndef _ADDR_
#define _ADDR_

#define __REG(x) (*((volatile unsigned int *)x))
#define __REG_BYTE(x) (*((volatile unsigned char *)x))

/*****************************************************/
/*          GPIOH   Registers                       */

// config port mode
#define GPHCON   __REG(0x56000070)      // Configures the pins of port H
#define GPHDAT   __REG(0x56000074)      // The data register for port H
#define GPHUP    __REG(0x56000070)      // pull-up disable register for port H

/*****************************************************/
/*          UART0   Registers                       */

// set data format
#define ULCON0   __REG(0x50000000)      // UART LINE CONTROL REGISTER.
// select which clock to use. interrupt mode. break signal(stop bit?)
#define UCON0    __REG(0x50000004)      // UART CONTROL REGISTER.
// fifo reset mode. trigger level

#define UMCON0   __REG(0x5000000C)      // UART MODEM CONTROL REGISTER. flow control

// status
#define UTRSTAT0 __REG(0x50000010)      // UART TX/RX STATUS REGISTER.
#define UERSTAT0 __REG(0x50000014)      // UART ERROR STATUS REGISTER
#define UFSTAT0  __REG(0x50000018)      // UART FIFO STATUS REGISTER
#define UMSTAT0  __REG(0x5000001C)      // UART MODEM STATUS REGISTER

// get data
#define UTXH0L   __REG_BYTE(0x50000020)      // UART TRANSMIT BUFFER REGISTER (HOLDING REGISTER & FIFO REGISTER) little endian mode
#define URXH0L   __REG_BYTE(0x50000024)      // UART RECEIVE BUFFER REGISTER (HOLDING REGISTER & FIFO REGISTER) little endian

// set baud rate
#define UBRDIV0  __REG(0x50000028)      // UART BAUD RATE DIVISOR REGISTER

#endif