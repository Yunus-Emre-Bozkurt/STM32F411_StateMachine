/*
 * application.h
 *
 *  Created on: Mar 20, 2024
 *      Author: Agrica
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "integration.h"

#define FALSE				0x00u
#define TRUE				0x01u
#define BUFFER_SIZE 		5
#define FUNCTINON_SIZE 		4
#define STATE_TIMER_TAG 	0

// State transtion variables
typedef enum
{
	stateLed1 = 0,
	stateLed2,
	stateLed3,
	stateLed4
}state_t;

// State table typedef definitions
typedef uint8_t (*functionPtr)(void);
typedef struct
{
	functionPtr	function;
	bool stateTransitionCondition;
}stateFunction_t;

//Uart Message definitions
typedef struct{
	union{
		uint8_t dataArray[BUFFER_SIZE];
		struct
		{
			uint8_t	initial;
			uint8_t led1;
			uint8_t led2;
			uint8_t led3;
			uint8_t led4;
		}__attribute__((packed));
	}datas;
}txMessage_t;

// state functions
uint8_t initializeApplication(void);
uint8_t stateLED1(void);
uint8_t stateLED2(void);
uint8_t stateLED3(void);
uint8_t stateLED4(void);

// Extern variables
extern UART_HandleTypeDef huart1;
extern state_t currentState;
extern stateFunction_t appFunctionTable[FUNCTINON_SIZE];


#endif /* APPLICATION_H_ */
