/**************************************************************************//**
 * Copyright (c) 2016 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "adc_0.h"
#include "assert.h"

#define ADC0_enableTempSensor()   REF0CN |= 0x04
#define ADC0_disableTempSensor()  REF0CN &= 0xFB

#if EFM8PDL_ADC0_USE_INIT == 1
#define MAX_SARCLK 12500000UL
#define MAX_SYSCLK 25000000UL
 
void ADC0_init(ADC0_ConversionStart_t convStart,
                ADC0_Resolution_t resolution,
                uint32_t sysclk)
{
	uint8_t divider;

	// Sysclk cannot be greater than the maximum
	SLAB_ASSERT(sysclk <= MAX_SYSCLK);

    // calculate SAR clock divider 
    divider = 0; 
  while(sysclk > MAX_SARCLK * (divider + 1))
  {
    divider++;
  }

	if(resolution == ADC0_RESOLUTION_8_BIT)
	{
		ADC0CF = resolution | ADC0CF_ADGN__GAIN_0P5 | (divider << ADC0CF_ADSC__SHIFT);
		ADC0AC = ADC0AC_ADRPT__ACC_1 | ADC0AC_ADSJST__RIGHT_NO_SHIFT; 
		ADC0CN0 = convStart; 	
	}
	else
	{   
		ADC0CF = ADC0CF_ADGN__GAIN_0P5 | (divider << ADC0CF_ADSC__SHIFT);
		if(resolution == ADC0_RESOLUTION_10_BIT)
		{
			ADC0AC = resolution | ADC0AC_ADRPT__ACC_1 | ADC0AC_ADSJST__RIGHT_NO_SHIFT;
			ADC0CN0 = convStart; 
		}	
		else // resolution == ADC0_RESOLUTION_12_BIT
		{
			ADC0AC = resolution | ADC0AC_ADRPT__ACC_4 | ADC0AC_ADSJST__RIGHT_NO_SHIFT;
			ADC0CN0 = convStart | ADC0CN0_ADBMEN__BURST_ENABLED; 	
		}
	}
		
	// Enable ADC
	ADC0CN0_ADEN = 1;
}
#endif //EFM8PDL_ADC0_USE_INIT

uint8_t ADC0_getIntFlags()
{
  uint8_t val;
  val = ADC0CN0 & (ADC0_CONVERSION_COMPLETE_IF | ADC0_WINDOW_COMPARE_IF);
  return val;
}

void ADC0_clearIntFlags(uint8_t flags)
{
 
  // Must pass one of the valid flags
  SLAB_ASSERT(flags & (ADC0_CONVERSION_COMPLETE_IF | ADC0_WINDOW_COMPARE_IF));

  ADC0CN0 &= ~(flags & (ADC0_CONVERSION_COMPLETE_IF | ADC0_WINDOW_COMPARE_IF));
}

void ADC0_enableInt(uint8_t flags, bool enable)
{
  uint8_t en;

  // Must pass one of the valid flags
  SLAB_ASSERT(flags & (ADC0_CONVERSION_COMPLETE_IF | ADC0_WINDOW_COMPARE_IF));

  en = (uint8_t) enable;

  if (flags & ADC0_CONVERSION_COMPLETE_IF)
  {
    EIE1 &= ~EIE1_EADC0__BMASK;
    EIE1 |= en << EIE1_EADC0__SHIFT;
  }

  if (flags & ADC0_WINDOW_COMPARE_IF)
  {
    EIE1 &= ~EIE1_EWADC0__BMASK;
    EIE1 |= en << EIE1_EWADC0__SHIFT;
  }
}


void ADC0_enable(void)
{
	ADC0CN0_ADEN = 1;
}

void ADC0_disable(void)
{
	ADC0CN0_ADEN = 0;
}

void ADC0_setPositiveInput(ADC0_PositiveInput_t input)
{

	// Turn on the temp sensor if it is the input
  if (input == ADC0_POSITIVE_INPUT_TEMP)
  {
    ADC0_enableTempSensor();
  }
  else
  {
    ADC0_disableTempSensor();
  }
 
	ADC0MX = input;
}

void ADC0_startConversion(void)
{
	uint8_t ADCM_save;

	// Save the conversion source and set to ADBUSY
 	ADCM_save = ADC0CN0 & ADC0CN0_ADCM__FMASK;
	ADC0CN0 = (ADC0CN0 & ~ADC0CN0_ADCM__FMASK) | ADC0CN0_ADCM__ADBUSY;
 
	// Clear the conversion complete flag
	ADC0CN0_ADINT = 0;

	// Start a conversion by setting ADBUSY
	ADC0CN0_ADBUSY = 1;

	// Restore the conversion source
	ADC0CN0 |= ADCM_save;
}

bool ADC0_isConversionComplete(void)
{
	bool conversionComplete;
	conversionComplete = ADC0CN0_ADINT;
	return conversionComplete;
}

uint16_t ADC0_getResult(void)
{
	uint16_t result;
	result = ADC0;
	return result;
}

void ADC0_setWindowCompare(uint16_t lessThan, uint16_t greaterThan)
{
    ADC0LT = lessThan;
	ADC0GT = greaterThan;
}

