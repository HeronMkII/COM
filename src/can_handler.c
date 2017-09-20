
#include "can_handler.h"


void can_handler (uint16_t identifier, uint8_t* pt_data, uint8_t size){

  // Bit masks defined in can.h to get sender_id, receiver_id, and msg_id
  uint16_t sender_id = identifier & TX_MASK;
  uint16_t receiver_id = identifier & RX_MASK;
  uint16_t msg_id = identifier & MSG_MASK;


  // Handle TM

  if (receiver_id == COM_RX && msg_id == TM){


  }

}
