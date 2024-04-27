/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#define IdShortPressButton1 0x03000004
#define IdShortPressButton2 0x03001004
#define IdShortPressButton3 0x03002004
#define IdShortPressButton4 0x03003004


#define IdLongPressButton1 0x03004004
#define IdLongPressButton2 0x03005004
#define IdLongPressButton3 0x03006004
#define IdLongPressButton4 0x03007004

#define IdDoublePressButton1 0x0300A004
#define IdDoublePressButton2 0x0300B004
#define IdDoublePressButton3 0x0300C004
#define IdDoublePressButton4 0x0300D004

#define AnswerIdCurrentState 0x03008004   // Сообщение о текущем состоянии
#define AnswerDataCurrentState 0x2        // Версия прошивки
#define RequestCurrentStateMU 0x03000100  //Запрос о текущем состоянии МУ
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Button_2_Pin GPIO_PIN_2
#define Button_2_GPIO_Port GPIOA
#define Button_3_Pin GPIO_PIN_3
#define Button_3_GPIO_Port GPIOA
#define Button_4_Pin GPIO_PIN_7
#define Button_4_GPIO_Port GPIOA
#define Button_1_Pin GPIO_PIN_5
#define Button_1_GPIO_Port GPIOB
#define STB_Pin GPIO_PIN_7
#define STB_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
