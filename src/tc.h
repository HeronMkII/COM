#ifndef TC_H
#define TC_H

#include <avr/io.h>
#include <uart/uart.h>
#include <uart/log.h>
#include <can/can.h>

void init_tc(void);
void execute_tc(uint8_t c);


#define TC_REQUEST_HK  1
#define TC_START_EXP   2
#define TC_HANDSHAKE   3


#endif
