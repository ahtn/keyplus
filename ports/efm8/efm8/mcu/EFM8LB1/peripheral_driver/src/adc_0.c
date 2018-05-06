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

#define ADC0_SFRPAGE 0x30
#define ADC0_enableTempSensor()   ADC0CN0_TEMPE = 1
#define ADC0_disableTempSensor()  ADC0CN0_TEMPE = 0

#if EFM8PDL_ADC0_USE_INIT == 1
#define MAX_SARCLK 18000000UL
#define MAX_SYSCLK 75000000UL
void ADC0_init(ADC0_ConversionStart_t convStart,
                ADC0_Resolution_t resolution,
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

	ADC0CN0 = ADC0CN0_ADGN__GAIN_0P5;
	ADC0CN1 = resolution | ADC0CN1_ADRPT__ACC_1 | ADC0CN1_ADSJST__RIGHT_NO_SHIFT;
	ADC0CN2 = convStart | ADC0CN2_PACEN__PAC_DISABLED;

	ADC0CF0 = (divider << ADC0CF0_ADSC__SHIFT) | ADC0CF0_ADCLKSEL__SYSCLK;

	// Set min tracking time to minimum needed during fastest adc clock
	ADC0CF1 = 5 << ADC0CF1_ADTK__SHIFT;

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

	ADC0MX = input;
	RESTORE_PAGE;
}

void ADC0_startConversion(void)
{
	uint8_t ADCM_save;
	DECL_PAGE;
	SET_PAGE(ADC0_SFRPAGE);

	// Save the conversion source and set to ADBUSY
	ADCM_save = ADC0CN2 & ADC0CN2_ADCM__FMASK;
	ADC0CN2 = (ADC0CN2 & ~ADC0CN2_ADCM__FMASK) | ADC0CN2_ADCM__ADBUSY;

	// Clear the conversion complete flag
	ADC0CN0_ADINT = 0;

	// Start a conversion by setting ADBUSY
	ADC0CN0_ADBUSY = 1;

	// Restore the conversion source
	ADC0CN2 |= ADCM_save;
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

#if EFM8PDL_ADC0_USE_AUTOSCAN == 1
void ADC0_setAutoscanInputs(ADC0_PositiveInput_t startChannel,
                      	  	uint8_t numChannels)
{
	uint8_t endChannel;
	DECL_PAGE;
	SET_PAGE(ADC0_SFRPAGE);

	// Channels must be 1 to 4
	SLAB_ASSERT(numChannels <= 4 && numChannels >= 1);

	// Register setting for number of channels equals numChannels - 1.
	numChannels -= 1;

	ADC0ASCF = (ADC0ASCF & ~ADC0ASCF_NASCH__FMASK) | numChannels;

	endChannel = startChannel + numChannels;

	// Channels cannot end past the last channel
	SLAB_ASSERT(endChannel <= ADC0_POSITIVE_INPUT_NONE);

	// Turn on temp sensor if it is in the scan
  if (startChannel <= ADC0_POSITIVE_INPUT_TEMP
      && endChannel >= ADC0_POSITIVE_INPUT_TEMP)
  {
    ADC0_enableTempSensor();
  }
  else
  {
    ADC0_disableTempSensor();
  }

	ADC0MX = startChannel;

	RESTORE_PAGE;
}

void ADC0_enableAutoscan(const ADC0_AutoscanBuffer_t * buffer,
                      uint8_t numElements, //Max 64
                      ADC0_AutoscanMode_t mode)
{
	uint8_t ADCM_save;
	DECL_PAGE;
	SET_PAGE(ADC0_SFRPAGE);

	// Save the conversion source and set to ADBUSY
	ADCM_save = ADC0CN2 & ADC0CN2_ADCM__FMASK;
	ADC0CN2 = (ADC0CN2 & ~ADC0CN2_ADCM__FMASK) | ADC0CN2_ADCM__ADBUSY;

	// Load the initial buffer and start the Autoscan
	ADC0_setNextAutoscanBuffer(buffer, numElements);
	ADC0ASCF |= ADC0ASCF_ASEN__START_SCAN;

	// Disable autoscan if only a single scan is to be performed
	// This prevents the next autoscan from starting after the
	// current one is finished.
  if (mode == ADC0_AUTOSCAN_MODE_SINGLE)
  {
    ADC0_disableAutoscan();
  }

	// Restore start-of-conversion source
	ADC0CN2 |= ADCM_save;
	RESTORE_PAGE;
}

const ADC0_AutoscanBuffer_t * ADC0_getNextAutoscanBuffer(void)
{
  const ADC0_AutoscanBuffer_t * buffer;
  DECL_PAGE;
  SET_PAGE(ADC0_SFRPAGE);

  buffer = (ADC0_AutoscanBuffer_t *)(((ADC0ASAH & ADC0ASAH_STADDRH__FMASK) << 8) | (ADC0ASAL & ADC0ASAL_STADDRL__FMASK));

  RESTORE_PAGE;
  return buffer;
}

void ADC0_setNextAutoscanBuffer(const ADC0_AutoscanBuffer_t * buffer,
                      uint8_t numElements)
{
	uint16_t addr = (uint16_t)buffer;
	DECL_PAGE;
	SET_PAGE(ADC0_SFRPAGE);

	// Buffer must be aligned to an even address
	SLAB_ASSERT(!(addr & 0x01));

	// Set the autoscan address
	ADC0ASAH = (ADC0ASAH & ~ADC0ASAH_STADDRH__FMASK) | ((addr >> 8) & ADC0ASAH_STADDRH__FMASK);
	ADC0ASAL = (ADC0ASAL & ~ADC0ASAL_STADDRL__FMASK) | (addr & ADC0ASAL_STADDRL__FMASK);

	// Buffer size must be 1-64
	SLAB_ASSERT(numElements <= 64 && numElements >= 1);

	// Actual count setting is count + 1, subtract one from numElements
	numElements -= 1;

	// Set autoscan count
	ADC0ASCT = (ADC0ASCT & ~ADC0ASCT_ASCNT__FMASK) | numElements;

	RESTORE_PAGE;
}

void ADC0_disableAutoscan(void)
{
	DECL_PAGE;
	SET_PAGE(ADC0_SFRPAGE);

	ADC0ASCF &= ~ADC0ASCF_ASEN__BMASK;

	RESTORE_PAGE;
}
#endif //EFM8PDL_ADC0_USE_AUTOSCAN
