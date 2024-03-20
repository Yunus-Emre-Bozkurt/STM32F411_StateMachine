/*
 * application.h
 *
 *  Created on: Mar 20, 2024
 *      Author: Agrica
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "main.h"
#include <stdbool.h>

#define FALSE	0x00u
#define TRUE	0x01u

// State transtion variables
typedef enum
{
	stateInit = 0,
	stateLed1,
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

// state functions
uint8_t initStateMachine(void);
uint8_t stateLED1(void);
uint8_t stateLED2(void);
uint8_t stateLED3(void);
uint8_t stateLED4(void);


#endif /* APPLICATION_H_ */
