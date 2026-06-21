/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

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
#define NMI_Pin GPIO_PIN_2
#define NMI_GPIO_Port GPIOE
#define INTR_Pin GPIO_PIN_3
#define INTR_GPIO_Port GPIOE
#define READY_Pin GPIO_PIN_4
#define READY_GPIO_Port GPIOE
#define CLK_Pin GPIO_PIN_5
#define CLK_GPIO_Port GPIOE
#define nTEST_Pin GPIO_PIN_6
#define nTEST_GPIO_Port GPIOE
#define nINTA_Pin GPIO_PIN_13
#define nINTA_GPIO_Port GPIOC
#define AD0_Pin GPIO_PIN_0
#define AD0_GPIO_Port GPIOC
#define AD1_Pin GPIO_PIN_1
#define AD1_GPIO_Port GPIOC
#define AD2_Pin GPIO_PIN_2
#define AD2_GPIO_Port GPIOC
#define AD3_Pin GPIO_PIN_3
#define AD3_GPIO_Port GPIOC
#define AD4_Pin GPIO_PIN_4
#define AD4_GPIO_Port GPIOC
#define AD5_Pin GPIO_PIN_5
#define AD5_GPIO_Port GPIOC
#define MN_nMX_Pin GPIO_PIN_7
#define MN_nMX_GPIO_Port GPIOE
#define nRQGT0_Pin GPIO_PIN_8
#define nRQGT0_GPIO_Port GPIOE
#define nRQGT1_Pin GPIO_PIN_9
#define nRQGT1_GPIO_Port GPIOE
#define A8_Pin GPIO_PIN_8
#define A8_GPIO_Port GPIOD
#define A9_Pin GPIO_PIN_9
#define A9_GPIO_Port GPIOD
#define A10_Pin GPIO_PIN_10
#define A10_GPIO_Port GPIOD
#define A11_Pin GPIO_PIN_11
#define A11_GPIO_Port GPIOD
#define A12_Pin GPIO_PIN_12
#define A12_GPIO_Port GPIOD
#define A13_Pin GPIO_PIN_13
#define A13_GPIO_Port GPIOD
#define A14_Pin GPIO_PIN_14
#define A14_GPIO_Port GPIOD
#define A15_Pin GPIO_PIN_15
#define A15_GPIO_Port GPIOD
#define AD6_Pin GPIO_PIN_6
#define AD6_GPIO_Port GPIOC
#define AD7_Pin GPIO_PIN_7
#define AD7_GPIO_Port GPIOC
#define nRD_Pin GPIO_PIN_8
#define nRD_GPIO_Port GPIOC
#define nDEN_nS2_Pin GPIO_PIN_9
#define nDEN_nS2_GPIO_Port GPIOC
#define nDTR_nS1_Pin GPIO_PIN_10
#define nDTR_nS1_GPIO_Port GPIOC
#define IOM_nS1_Pin GPIO_PIN_11
#define IOM_nS1_GPIO_Port GPIOC
#define nWR_nLOCK_Pin GPIO_PIN_12
#define nWR_nLOCK_GPIO_Port GPIOC
#define A16_S3_Pin GPIO_PIN_0
#define A16_S3_GPIO_Port GPIOD
#define A17_S4_Pin GPIO_PIN_1
#define A17_S4_GPIO_Port GPIOD
#define A18_S5_Pin GPIO_PIN_2
#define A18_S5_GPIO_Port GPIOD
#define A19_S6_Pin GPIO_PIN_3
#define A19_S6_GPIO_Port GPIOD
#define nSSO_Pin GPIO_PIN_4
#define nSSO_GPIO_Port GPIOD
#define RESET_Pin GPIO_PIN_1
#define RESET_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
