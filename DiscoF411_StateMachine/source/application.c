/*
 * application.c
 *
 *  Created on: Mar 20, 2024
 *      Author: Agrica
 */

#include "application.h"

state_t currentState;
uint8_t uartBufferlen = 0;
char transmitBuffer[64] = {};
txMessage_t txMessage;


stateFunction_t appFunctionTable[FUNCTINON_SIZE] =
{
		{.function = stateLED1, .stateTransitionCondition = FALSE},
		{.function = stateLED2, .stateTransitionCondition = FALSE},
		{.function = stateLED3, .stateTransitionCondition = FALSE},
		{.function = stateLED4, .stateTransitionCondition = FALSE}
};

uint8_t initializeApplication(void)
{
	timerAppInit();						//systick initialze
	startTimer(STATE_TIMER_TAG, 1000);	//timer initialize 1 s

	currentState = stateLed1;			// initialze the state machine
	txMessage.datas.initial = 0xAA;		// initialize completed flag

	return ((uint8_t) uartSendDMA(&huart1, txMessage.datas.dataArray, sizeof(txMessage.datas.dataArray)));
}

uint8_t stateLED1(void)
{
	currentState = stateLed2;
	txMessage.datas.led1 = 0xBB;		// initialize completed flag
	HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);

	return ((uint8_t) uartSendDMA(&huart1, txMessage.datas.dataArray, sizeof(txMessage.datas.dataArray)));
}

uint8_t stateLED2(void)
{
	currentState = stateLed3;
	txMessage.datas.led2 = 0xCC;		// initialize completed flag
	HAL_GPIO_TogglePin(LD4_GPIO_Port, LD4_Pin);

	return ((uint8_t) uartSendDMA(&huart1, txMessage.datas.dataArray, sizeof(txMessage.datas.dataArray)));
}

uint8_t stateLED3(void)
{
	currentState = stateLed4;
	txMessage.datas.led3 = 0xDD;		// initialize completed flag
	HAL_GPIO_TogglePin(LD5_GPIO_Port, LD5_Pin);

	return ((uint8_t) uartSendDMA(&huart1, txMessage.datas.dataArray, sizeof(txMessage.datas.dataArray)));
}

uint8_t stateLED4(void)
{
	currentState = stateLed4;
	txMessage.datas.led4 = 0xFF;		// initialize completed flag
	HAL_GPIO_TogglePin(LD6_GPIO_Port, LD6_Pin);

	return ((uint8_t) uartSendDMA(&huart1, txMessage.datas.dataArray, sizeof(txMessage.datas.dataArray)));
}
