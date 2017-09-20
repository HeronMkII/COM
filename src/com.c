#include <avr/io.h>
#include <uart/uart.h>
#include <uart/log.h>
#include <can/can.h>

#include "trans.h"
#include "beacon.h"
#include "tc.h"
#include "tm.h"

int main(void) {
    init_uart();
//    init_can(0);
    // init_cc1120();

    init_beacon(1);
    init_tm();
    init_tc();

    uint8_t data[] = "Hello world!";

    while (1) {
        uint8_t status = get_status();
        print_status(status);
        send(data, 0xAA, 12);
    }
}
