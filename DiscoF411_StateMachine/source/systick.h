/*
 * systick.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Agrica
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "integration.h"

void systickinit(void);
void disableSystickInterrupt(void);
void enableSystickInterrupt(void);
uint32_t getSystickCount(void);



#endif /* SYSTICK_H_ */
