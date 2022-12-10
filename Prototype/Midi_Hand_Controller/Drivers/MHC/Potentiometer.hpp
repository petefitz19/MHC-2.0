#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_

#include "stm32f1xx_hal.h"

class Potentiometer {
  ADC_HandleTypeDef* _hadc;
  uint32_t _channel;
  GPIO_TypeDef* _port;
  uint16_t _pin;
 public:
  Potentiometer(ADC_HandleTypeDef* hadc, uint32_t channel, GPIO_TypeDef* port, uint16_t pin);
  
  int Init();
  int Read(uint16_t& val);
};

#endif  // POTENTIOMETER_H_
