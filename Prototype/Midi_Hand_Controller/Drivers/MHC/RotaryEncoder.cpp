/*
 * RotaryEncoder.cpp
 *
 *  Created on: Nov 2, 2022
 *      Author: peterfitzpatrick
 */

#include "RotaryEncoder.hpp"

RotaryEncoder::RotaryEncoder(GPIO_TypeDef* port_a, uint16_t pin_a,
                             GPIO_TypeDef* port_b, uint16_t pin_b,
                             GPIO_TypeDef* port_sw, uint16_t pin_sw)
{
    _port_a = port_a;
    _pin_a = pin_a;
    _port_b = port_b;
    _pin_b = pin_b;
    _port_sw = port_sw;
    _pin_sw = pin_sw;
    _counter = 0;
}

int RotaryEncoder::Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* Initialize Input A */
    GPIO_InitStruct.Pin = _pin_a;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(_port_a, &GPIO_InitStruct);

    /* Initialize Input B */
    GPIO_InitStruct.Pin = _pin_b;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(_port_b, &GPIO_InitStruct);

    /* Initialize Switch */
    GPIO_InitStruct.Pin = _pin_sw;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(_port_sw, &GPIO_InitStruct);

	_a_last_state = HAL_GPIO_ReadPin(_port_a, _pin_a);
    return 0;
}

int RotaryEncoder::Read(void)
{
    _sw_state = HAL_GPIO_ReadPin(_port_sw, _pin_sw);
    _a_state = HAL_GPIO_ReadPin(_port_a, _pin_a); // Change to a

    if(_a_state != _a_last_state)
    {
        if(HAL_GPIO_ReadPin(_port_b, _pin_b) != _a_state)
        {
            _counter++;
        }
        else
        {
            _counter--;
        }
        _a_last_state = _a_state;
    }

    return 0;
}

uint8_t RotaryEncoder::GetCount(void)
{
    return _counter;
}

uint8_t RotaryEncoder::GetSwitchState(void)
{
    return _sw_state;
}
