#include "beacon.h"

void transmit_beacon(void){
  print("*** BEACON *** \r\n");
  print("HERON Mk. II - University of Toronto Aerospace Team");
  print("Beacon number: ");
  print("%d", beacon_count);

  beacon_count++;

}

void init_beacon(uint8_t period){
  Command beacon = transmit_beacon;
  init_timer(1, beacon);
  }
