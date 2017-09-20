#ifndef _can_handler_h
#define _can_handler_h

#include <avr/io.h>
#include <can/can.h>

#define MSG_LEN_MSK    0x0F
#define N_MSG_MSK      0xF0

void can_handler (uint16_t identifier, uint8_t* pt_data, uint8_t size);

#endif
