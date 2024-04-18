/*
 * button.cpp
 *
 *  Created on: Mar 6, 2023
 *      Author: AlexeyU, MorozovK
 */

#include <button.h>

extern  TIM_HandleTypeDef htim1;

button::button(uint32_t IdShortPress, uint32_t IdLongPress, uint32_t IdDoublePress)
{
	InitCAN();
	this->IdShortPress = IdShortPress;
	this->IdLongPress = IdLongPress;
	this->IdDoublePress = IdDoublePress;
}

//private

void button :: InitCAN()
{
	PressButton.StdId = 0;
	PressButton.ExtId = 1;
	PressButton.RTR = CAN_RTR_DATA;
	PressButton.IDE = CAN_ID_EXT;
	PressButton.DLC = 0;
	PressButton.TransmitGlobalTime = DISABLE;
}

bool button :: IsShortPress(uint16_t TimeCounter)
{
	if(TimeCounter>= MinTimeForShortPress && TimeCounter<=MaxTimeForShortPress)
		return true;
	else
		return false;
}

bool button:: IsLongPress(uint16_t TimeCounter)
{
	if(TimeCounter>= TimeForLongPress)
		return true;
	else
		return false;
}

bool button:: IsDoubleShortPress(uint16_t TimeCounter)
{
	if(TimeCounter>= TimeForDoublePress)
		return true;
	else
		return false;
}

bool button :: IsCanFreeForTransmit(CAN_HandleTypeDef *hcan)
{
	if(HAL_CAN_GetTxMailboxesFreeLevel(hcan)!=0)
		return true;
	else
		return false;
}

//public
bool button :: IsPressed (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	if(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)== GPIO_PIN_RESET)
		return true;
	else
		return false;
}

void button :: CanTransmitStateButton(CAN_HandleTypeDef *hcan)
{
	if(IsShortPress(TimeCounter))
	{
		TimeCounter = 0;
		if(IsCanFreeForTransmit(hcan))
		{
			PressButton.ExtId = IdShortPress;
			HAL_CAN_AddTxMessage(hcan, &PressButton, TxData, &TxMailbox);
		}
	}
	
	else if (IsLongPress(TimeCounter))
	{
		TimeCounter = 0;
		if(IsCanFreeForTransmit(hcan))
		{
			PressButton.ExtId = IdLongPress;
			HAL_CAN_AddTxMessage(hcan, &PressButton, TxData, &TxMailbox);
		}
	}
	else {
		TimeCounter = 0;
	}
}