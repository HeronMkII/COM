#include "tc.h"

void init_tc(){
  register_callback(execute_tc);
}


void execute_tc(uint8_t c){

  print("Acknowledge Command %d \r\n", c);

  uint8_t data[8];
  uint8_t size;
  uint16_t id = COM_TX | OBC_RX | TC;

  switch (c) {
    case TC_HANDSHAKE:
      print("Handshake successful \r\n");

    default :
      data[0] = c;
      size = 1;
  }

  can_send_message(data, size, id);


}
