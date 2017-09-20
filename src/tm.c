#include "tm.h"



uint8_t pack_and_send(uint8_t * data, uint8_t data_length){

  print("Begin Transmission from HERON Mk II: \r\n");
  print("Transmission ID: \r\n");
  print("Timestamp: \r\n");

  for (uint8_t i = 0; i < data_length; i++){
    print("Byte %d", i);
    print("%d", data[i]);
  }
  print("End Tranmission from HERON Mk II. \r\n");

  return 1;

}

void init_tm(){
  st_cmd_t tm_mob;
  uint8_t data[2];
  init_rx_mob(&tm_mob, data, 8, OBC_TX | COM_RX | TM);
  init_rx_interrupts(tm_mob);
}
