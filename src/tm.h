#ifndef TRNASMISSION_H
#define TRANSMISSION_H

#include <avr/io.h>
#include <uart/uart.h>
#include <uart/log.h>
#include <can/can.h>


uint8_t pack_and_send(uint8_t * data, uint8_t data_length);
void init_tm(void);

#endif
