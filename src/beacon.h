#ifndef BEACON_H
#define BEACON_H

#include <uart/uart.h>
#include <uart/log.h>
#include <timer/timer.h>

void transmit_beacon(void);
void init_beacon(uint8_t period);

uint32_t beacon_count;

#endif
