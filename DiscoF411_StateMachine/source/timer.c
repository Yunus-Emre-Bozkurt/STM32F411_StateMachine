/*
 * timer.c
 *
 *  Created on: Feb 1, 2024
 *      Author: Agrica
 */

#include "timer.h"



timerControl_t timerControlArr[NOFTIMER] = {};

/*	startTimer
 *
 * Brief: İstenilen 'ms' değerinde timer başlatır
 *
 * Param1: NOFTIMER'a kadar olan index değerini seçer.
 * Param2: Kurulan timer'ın sayaç üst limit değeridir.
 *
 * Return: NONE
 *
 * NOTE: startTimer() fonksiyonu her çağırıldığında ilgili index'in Initial değerini günceller.
 * 		Fonksiyon döngü içerisinde sürekli kullanılırsa Initial değer sürekli güncelleneceği için
 * 		üstLimite hiçbir zaman ulaşılamayacaktır.
 */
void startTimer(uint8_t index, uint32_t upperLimit)
{
	timerControlArr[index].InitialValue = getSystickCount();
	timerControlArr[index].controlFlag = true;
	timerControlArr[index].resultFlag = false;
	timerControlArr[index].counterUpperLimit = upperLimit;
}
/*********************************************************************************************/

/*	controlTimer
 *
 * Brief: Kurulan timerların üst limite ulaşıp ulaşmadığını kontrol eder. Üst Limite ulaşan Timer varsa
 * 		kontrolünü sonlandırır ve result flag'ını HIGH ayarlar.
 *
 * Return: NONE
 */
void controlTimer(void)
{
	uint32_t elapsedTime = 0;

	for(int i = 0; i<NOFTIMER; i++)
	{
		if(timerControlArr[i].controlFlag == true)		//kontrol flag'a bakılır
		{
			elapsedTime = (getSystickCount() - timerControlArr[i].InitialValue);
			if(timerControlArr[i].counterUpperLimit <= elapsedTime)		//istenen süre dolmuşsa
			{
				timerControlArr[i].resultFlag = true;		//Süre dolma flag'ı set edilir.
				timerControlArr[i].controlFlag = false;		//Tekrar kontrol edilmemesi için kontrol flag'ı false çekilir
			}
		}
	}
}
/*********************************************************************************************/

/*	getTimerResultStatus
 *
 * Brief: Timer'ın dolma durumunu kontrol eder
 *
 * Param1: Sonucu öğrenilmek istenen timer index'i
 *
 * Return: sayacın dolma durumunu 'bool' tipinde döndürür
 * 		TRUE 	=> Timer Dolmuştur
 * 		FALSE	=> Timer Dolmamıştır
 */
bool getTimerResultStatus(uint8_t index)
{
	bool res = false;

	if(timerControlArr[index].resultFlag == true)
	{
		res = true;
	}
	else
	{
		res = false;
	}

	return res;
}
/*********************************************************************************************/

