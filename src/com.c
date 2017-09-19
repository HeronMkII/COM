#include <avr/io.h>
#include <uart/uart.h>
#include <uart/log.h>

#include "trans.h"

int main(void) {
    init_uart();
    init_cc1120();

    uint8_t data[] = "Hello world!";

    while (1) {
        uint8_t status = get_status();
        print_status(status);
        send(data, 0xAA, 12);
    }
}
