#ifndef INC_IK_H_
#define INC_IK_H_

#include "main.h"

extern volatile uint8_t ir_recv_state;
extern volatile uint32_t ir_code;
extern volatile uint8_t ir_bit_count;

void test_ik();
void DisplayButton(uint32_t code);

#endif /* INC_IK_H_ */
