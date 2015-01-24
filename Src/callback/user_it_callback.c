/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private variables ---------------------------------------------------------*/
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim10;

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern ADC_HandleTypeDef hadc3;

//#include "TimesBase.h"
#include "peripherals/gyroscope/adxrs620.h"
#include "peripherals/telemeters/telemeters.h"
#include "peripherals/multimeter/multimeter.h"
#include "peripherals/lineSensors/lineSensors.h"
#include "peripherals/encoders/ie512.h"
#include "controls/pid/pid.h"
#include "times_base/times_base.h"

/* TIM callback --------------------------------------------------------------*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	  if( htim == &htim2)
	  {
//		  Telemeters_IT();
	  }
	  if( htim == &htim5)
	  {

	  }
	  if( htim == &htim7)
	  {
//		  High_Freq_IT();
	  }
	  if( htim == &htim6)
	  {
		  Low_Freq_IT();
	  }
	  if( htim == &htim1)
	  {
		  Left_Encoder_IT();
	  }
	  if( htim == &htim3)
	  {
		  Right_Encoder_IT();
	  }
}

void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
	  if( htim == &htim4)
	  {
		  Multimeter_IT();
	  }
}

/* ADC callback --------------------------------------------------------------*/
void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	if (hadc == &hadc1)
	{
		Gyroscope_INJECTED_ADC_IT();
	}
}

void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
	if (hadc == &hadc1)
	{
		Multimeter_REGULAR_ADC_IT();
	}
	if (hadc == &hadc2)
	{
//		Telemeters_REGULAR_ADC_IT();
	}
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	if (hadc == &hadc2)
	{
//		Telemeters_REGULAR_ADC_IT();
	}
}
