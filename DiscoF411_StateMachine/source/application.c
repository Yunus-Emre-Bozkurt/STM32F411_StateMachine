/*
 * application.c
 *
 *  Created on: Mar 20, 2024
 *      Author: Agrica
 */

#include "application.h"

stateFunction_t appFunctionTable[4] =
{
		{.function = stateLED1, .stateTransitionCondition = FALSE},
		{.function = stateLED2, .stateTransitionCondition = FALSE},
		{.function = stateLED3, .stateTransitionCondition = FALSE},
		{.function = stateLED4, .stateTransitionCondition = FALSE}
};


uint8_t initStateMachine(void)
{


}

uint8_t stateLED1(void)
{

}

uint8_t stateLED2(void)
{

}

uint8_t stateLED3(void)
{

}

uint8_t stateLED4(void)
{

}
