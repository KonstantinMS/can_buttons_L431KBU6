/*
 * button.h
 *
 *  Created on: Mar 6, 2023
 *      Author: AlexeyU, MorozovK
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

class button {
public:
	button(uint32_t IdShortPress, uint32_t IdLongPress);
	uint16_t TimeCounter = 0;
	bool IsPressed (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
	void CanTransmitStateButton(CAN_HandleTypeDef *hcan);





private:
	const uint16_t MinTimeForShortPress = 250;
	const uint16_t MaxTimeForShortPress = 4900;
	const uint16_t TimeForLongPress = 5000;


	CAN_TxHeaderTypeDef PressButton;


	uint8_t TxData[8] = {0,};
	uint32_t TxMailbox = 0;

	uint32_t IdLongPress = 0;
	uint32_t IdShortPress = 0;

	bool IsLongPress(uint16_t TimeCounter); //+
	bool IsShortPress(uint16_t TimeCounter); //+
	bool IsCanFreeForTransmit(CAN_HandleTypeDef *hcan); //+
	void InitCAN();





};

#endif /* INC_BUTTON_H_ */
