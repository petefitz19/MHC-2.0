#ifndef ROTARY_ENCODER_H_
#define ROTARY_ENCODER_H_

#include "stm32f1xx_hal.h"

class RotaryEncoder {
  uint8_t _counter, _sw_state, _a_state, _a_last_state;
  uint16_t _pin_a, _pin_b, _pin_sw;
  GPIO_TypeDef* _port_a;
  GPIO_TypeDef* _port_b;
  GPIO_TypeDef* _port_sw;
 public:
  RotaryEncoder(GPIO_TypeDef* port_a, uint16_t pin_a, 
                GPIO_TypeDef* port_b, uint16_t pin_b, 
                GPIO_TypeDef* port_sw, uint16_t pin_sw);
  
  int Init();
  int Read();
  uint8_t GetCount();
  uint8_t GetSwitchState();
};

#endif  // ROTARY_ENCODER_H_