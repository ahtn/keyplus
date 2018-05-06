/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "adc_0.h"
#include "assert.h"

#if EFM8PDL_ADC0_AUTO_PAGE == 1
// declare variable needed for autopage enter/exit
#define DECL_PAGE uint8_t savedPage
// enter autopage section
#define SET_PAGE(p)     do                                                    \
                        {                                                     \
                          savedPage = SFRPAGE;  /* save current SFR page */   \
                          SFRPAGE = (p);        /* set SFR page */            \
                        } while(0)
// exit autopage section
#define RESTORE_PAGE    do                                                    \
                        {                                                     \
                          SFRPAGE = savedPage;  /* restore saved SFR page */  \
                        } while(0)
#else
#define DECL_PAGE
#define SET_PAGE(p)
#define RESTORE_PAGE
#endif
 
#define ADC0_SFRPAGE 0x00	 
#define ADC0_enableTempSensor()   REF0CN |= 0x04
#define ADC0_disableTempSensor()  REF0CN &= 0xFB

#if EFM8PDL_ADC0_USE_INIT == 1
#define MAX_SARCLK  8333333UL
#define MAX_SYSCLK 48000000UL
 
void ADC0_init(ADC0_ConversionStart_t convStart,
                uint32_t sysclk)
{
	uint8_t divider;
	DECL_PAGE;
	SET_PAGE(ADC0_SFRPAGE);

	// Sysclk cannot be greater than the maximum
	SLAB_ASSERT(sysclk <= MAX_SYSCLK);

    // calculate SAR clock divider 
    divider = 0; 
  while(sysclk > MAX_SARCLK * (divider + 1))
  {
    divider++;
  }

 	ADC0CF = divider << ADC0CF_ADSC__SHIFT | ADC0CF_ADLJST__RIGHT_JUSTIFIED;
	ADC0CN0 = convStart; 

	// Enable ADC
	ADC0CN0_ADEN = 1;
	RESTORE_PAGE;
}
#endif //EFM8PDL_ADC0_USE_INIT

uint8_t ADC0_getIntFlags()
{
  uint8_t val;
  DECL_PAGE;
  SET_PAGE(ADC0_SFRPAGE);
  val = ADC0CN0 & (ADC0_CONVERSION_COMPLETE_IF | ADC0_WINDOW_COMPARE_IF);
  RESTORE_PAGE;
  return val;
}

void ADC0_clearIntFlags(uint8_t flags)
{
  DECL_PAGE;
  SET_PAGE(ADC0_SFRPAGE);
 
  // Must pass one of the valid flags
  SLAB_ASSERT(flags & (ADC0_CONVERSION_COMPLETE_IF | ADC0_WINDOW_COMPARE_IF));

  ADC0CN0 &= ~(flags & (ADC0_CONVERSION_COMPLETE_IF | ADC0_WINDOW_COMPARE_IF));
  RESTORE_PAGE;
}

void ADC0_enableInt(uint8_t flags, bool enable)
{
  uint8_t en;
  DECL_PAGE;
  SET_PAGE(0x00);

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
  RESTORE_PAGE;
}


void ADC0_enable(void)
{
	DECL_PAGE;
	SET_PAGE(ADC0_SFRPAGE);
	ADC0CN0_ADEN = 1;
	RESTORE_PAGE;
}

void ADC0_disable(void)
{
	DECL_PAGE;
	SET_PAGE(ADC0_SFRPAGE);
	ADC0CN0_ADEN = 0;
	RESTORE_PAGE;
}

void ADC0_setPositiveInput(ADC0_PositiveInput_t input)
{
	DECL_PAGE;
	SET_PAGE(ADC0_SFRPAGE);

	// Turn on the temp sensor if it is the input
  if (input == ADC0_POSITIVE_INPUT_TEMP)
  {
    ADC0_enableTempSensor();
  }
  else
  {
    ADC0_disableTempSensor();
  }
 
	AMX0P = input;
	RESTORE_PAGE;
}

void ADC0_setNegativeInput(ADC0_NegativeInput_t input)
{
	DECL_PAGE;
	SET_PAGE(ADC0_SFRPAGE);

	AMX0N = input;
	RESTORE_PAGE;
}
void ADC0_startConversion(void)
{
	uint8_t ADCM_save;
	DECL_PAGE;
	SET_PAGE(ADC0_SFRPAGE);

	// Save the conversion source and set to ADBUSY
 	ADCM_save = ADC0CN0 & ADC0CN0_ADCM__FMASK;
	ADC0CN0 = (ADC0CN0 & ~ADC0CN0_ADCM__FMASK) | ADC0CN0_ADCM__ADBUSY;
 
	// Clear the conversion complete flag
	ADC0CN0_ADINT = 0;

	// Start a conversion by setting ADBUSY
	ADC0CN0_ADBUSY = 1;

	// Restore the conversion source
	ADC0CN0 |= ADCM_save;
	RESTORE_PAGE;
}

bool ADC0_isConversionComplete(void)
{
	bool conversionComplete;
	DECL_PAGE;
	SET_PAGE(ADC0_SFRPAGE);
	conversionComplete = ADC0CN0_ADINT;
	RESTORE_PAGE;
	return conversionComplete;
}

uint16_t ADC0_getResult(void)
{
	uint16_t result;
	DECL_PAGE;
	SET_PAGE(ADC0_SFRPAGE);
	result = ADC0;
	RESTORE_PAGE;
	return result;
}

void ADC0_setWindowCompare(uint16_t lessThan, uint16_t greaterThan)
{
	DECL_PAGE;
	SET_PAGE(ADC0_SFRPAGE);
    ADC0LT = lessThan;
	ADC0GT = greaterThan;
	RESTORE_PAGE;
}

