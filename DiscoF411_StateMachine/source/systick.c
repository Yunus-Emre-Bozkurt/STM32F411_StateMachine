/*
 * systick.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Agrica
 */

#include "systick.h"

/** !!!!!!!!!!!!!!!!!!!!!!!!!
 * 		IMPORTANT NOTE
 *  !!!!!!!!!!!!!!!!!!!!!!!!!
 *
 * If you want to use configSystickTimer() function, You have to declare into your application main.c file "void SysTick_Handler (void)"
 * function to increment tick value in ISR callback function !!
 *
 * If void SysTick_Handler (void) predefined by IDE, disable the generated function and write own function
 * with same name.
 */

/*
 * @note Check Example Application as HAL_Delay() function
 *
 * */

/**
  * @brief Initiliaze the SysTick Timer with 1 ms time base. Interrupt priority setting '0'
  * @note  Initiliazing step done automatically while setting up HAL_INIT and SystemClockConfig phase
  *
  * @retval None
  */
void systickinit(void)
{
	HAL_InitTick(0);
}
/*********************************************************************************************/

/**
  * @brief Suspend Tick increment.
  * @note In the default implementation , SysTick timer is the source of time base. It is
  *       used to generate interrupts at regular time intervals. Once disableSystickInterrupt()
  *       is called, the SysTick interrupt will be disabled and so Tick increment
  *       is suspended.
  * @retval None
  */
void disableSystickInterrupt(void)
{
	SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
}
/*********************************************************************************************/

/**
  * @brief Resume Tick increment.
  * @note In the default implementation , SysTick timer is the source of time base. It is
  *       used to generate interrupts at regular time intervals. Once enableSystickInterrupt()
  *       is called, the SysTick interrupt will be enabled and so Tick increment
  *       is resumed.
  * @retval None
  */
void enableSystickInterrupt(void)
{
	SysTick->CTRL  |= SysTick_CTRL_TICKINT_Msk;
}
/*********************************************************************************************/

/**
  * @brief Provides a tick value in millisecond.
  *
  * @retval tick value
  */
uint32_t getSystickCount(void)
{
	return HAL_GetTick();
}
/*********************************************************************************************/




