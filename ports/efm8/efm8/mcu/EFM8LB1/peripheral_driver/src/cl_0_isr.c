
#include "efm8_config.h"
#include "SI_EFM8LB1_Register_Enums.h"

#if !defined(EFM8PDL_CLU0_USE_ISR)
#define EFM8PDL_CLU0_USE_ISR 0
#endif

#if !defined(EFM8PDL_CLU1_USE_ISR)
#define EFM8PDL_CLU1_USE_ISR 0
#endif

#if !defined(EFM8PDL_CLU2_USE_ISR)
#define EFM8PDL_CLU2_USE_ISR 0
#endif

#if !defined(EFM8PDL_CLU3_USE_ISR)
#define EFM8PDL_CLU3_USE_ISR 0
#endif

#if EFM8PDL_CLU0_USE_ISR == 1
#include "clu_0.h"
#endif

#if EFM8PDL_CLU1_USE_ISR == 1
#include "clu_1.h"
#endif

#if EFM8PDL_CLU2_USE_ISR == 1
#include "clu_2.h"
#endif

#if EFM8PDL_CLU3_USE_ISR == 1
#include "clu_3.h"
#endif

#define CLU0_RISING_EDGE_ENABLED (CLIE0 & CLIE0_C0FIE__BMASK)
#define CLU0_FALLING_EDGE_ENABLED (CLIE0 & CLIE0_C0RIE__BMASK)
#define CLU1_RISING_EDGE_ENABLED (CLIE0 & CLIE0_C1FIE__BMASK)
#define CLU1_FALLING_EDGE_ENABLED (CLIE0 & CLIE0_C1RIE__BMASK)
#define CLU2_RISING_EDGE_ENABLED (CLIE0 & CLIE0_C2FIE__BMASK)
#define CLU2_FALLING_EDGE_ENABLED (CLIE0 & CLIE0_C2RIE__BMASK)
#define CLU3_RISING_EDGE_ENABLED (CLIE0 & CLIE0_C3FIE__BMASK)
#define CLU3_FALLING_EDGE_ENABLED (CLIE0 & CLIE0_C3RIE__BMASK)

#if EFM8PDL_CLU0_USE_ISR || EFM8PDL_CLU1_USE_ISR || EFM8PDL_CLU2_USE_ISR || EFM8PDL_CLU3_USE_ISR
//-----------------------------------------------------------------------------
// CL0_ISR
//-----------------------------------------------------------------------------
//
// CL0 ISR Content goes here. Remember to clear flag bits:
// CLIF0::C0FIF (CLU0 Falling Edge Interrupt Flag)
// CLIF0::C0RIF (CLU0 Rising Edge Interrupt Flag)
// CLIF0::C1FIF (CLU1 Falling Edge Interrupt Flag)
// CLIF0::C1RIF (CLU1 Rising Edge Interrupt Flag)
// CLIF0::C2FIF (CLU2 Falling Edge Interrupt Flag)
// CLIF0::C2RIF (CLU2 Rising Edge Interrupt Flag)
// CLIF0::C3FIF (CLU3 Falling Edge Interrupt Flag)
// CLIF0::C3RIF (CLU3 Rising Edge Interrupt Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (CL0_ISR, CL0_IRQn)
{
  uint8_t flags = CLIF0;
  CLIF0 = 0;

#if EFM8PDL_CLU0_USE_ISR
  if ((flags & CLIF0_C0FIF__BMASK) && CLU0_RISING_EDGE_ENABLED)
  {
    CLU0_fallingEdgeCb();
  }

  if ((flags & CLIF0_C0RIF__BMASK) && CLU0_FALLING_EDGE_ENABLED)
  {
    CLU0_risingEdgeCb();
  }
#endif

#if EFM8PDL_CLU1_USE_ISR
  if ((flags & CLIF0_C1FIF__BMASK) && CLU1_RISING_EDGE_ENABLED)
  {
    CLU1_fallingEdgeCb();
  }

  if ((flags & CLIF0_C1RIF__BMASK) && CLU1_FALLING_EDGE_ENABLED)
  {
    CLU1_risingEdgeCb();
  }
#endif

#if EFM8PDL_CLU2_USE_ISR
  if ((flags & CLIF0_C2FIF__BMASK) && CLU2_RISING_EDGE_ENABLED)
  {
    CLU2_fallingEdgeCb();
  }

  if ((flags & CLIF0_C2RIF__BMASK) && CLU2_FALLING_EDGE_ENABLED)
  {
    CLU2_risingEdgeCb();
  }
#endif

#if EFM8PDL_CLU3_USE_ISR
  if ((flags & CLIF0_C3FIF__BMASK) && CLU3_RISING_EDGE_ENABLED)
  {
    CLU3_fallingEdgeCb();
  }

  if ((flags & CLIF0_C3RIF__BMASK) && CLU3_FALLING_EDGE_ENABLED)
  {
    CLU3_risingEdgeCb();
  }
#endif
}

#endif
