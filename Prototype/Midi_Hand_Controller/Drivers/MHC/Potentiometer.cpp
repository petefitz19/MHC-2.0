/*
 * Potentiometer.cpp
 *
 *  Created on: Nov 3, 2022
 *      Author: peterfitzpatrick
 */

#include "Potentiometer.hpp"

Potentiometer::Potentiometer(ADC_HandleTypeDef* hadc, uint32_t channel, GPIO_TypeDef* port, uint16_t pin)
{
    _hadc = hadc;
    _channel = channel;
    _port = port;
    _pin = pin;
}

int Potentiometer::Init(void)
{
    ADC_ChannelConfTypeDef sConfig = {0};

    /** Common config
     */
    _hadc->Instance = ADC1;
    _hadc->Init.ScanConvMode = ADC_SCAN_DISABLE;
    _hadc->Init.ContinuousConvMode = ENABLE;
    _hadc->Init.DiscontinuousConvMode = DISABLE;
    _hadc->Init.ExternalTrigConv = ADC_SOFTWARE_START;
    _hadc->Init.DataAlign = ADC_DATAALIGN_RIGHT;
    _hadc->Init.NbrOfConversion = 1;
    HAL_ADC_Init(_hadc);

    /** Configure Regular Channel
     */
    sConfig.Channel = _channel;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
    HAL_ADC_ConfigChannel(_hadc, &sConfig);

    return 0;
}

int Potentiometer::Read(uint16_t& val)
{
    ADC_ChannelConfTypeDef sConfigPrivate = {0};
    sConfigPrivate.Rank = ADC_REGULAR_RANK_1;
    sConfigPrivate.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
    sConfigPrivate.Channel = _channel;
    HAL_ADC_ConfigChannel(_hadc, &sConfigPrivate);
    HAL_ADC_Start(_hadc);
    HAL_ADC_PollForConversion(_hadc,1000);
    val = HAL_ADC_GetValue(_hadc) / 7;
    HAL_ADC_Stop(_hadc);

    return 0;
}
