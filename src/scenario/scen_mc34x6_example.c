/*****************************************************************************
 *
 * Copyright (c) 2016 mCube, Inc.  All rights reserved.
 *
 * This source is subject to the mCube Software License.
 * This software is protected by Copyright and the information and source code
 * contained herein is confidential. The software including the source code
 * may not be copied and the information contained herein may not be used or
 * disclosed except with the written permission of mCube Inc.
 *
 * All other rights reserved.
 *****************************************************************************/

/*******************************************************************************
 *** INCLUDE FILES
 *******************************************************************************/
/* function includes */
#include "scen_mc34x6_example.h"
#include "m_drv_mc34x6.h"
#include "m_drv_mc_utility.h"
#include "m_drv_interface.h"
#include "m_drv_console.h"

/*******************************************************************************
 **************************   GLOBAL VARIABLES   *******************************
 ******************************************************************************/

/*******************************************************************************
 *** STRUCT/TYPE
 *******************************************************************************/

/*******************************************************************************
 *** STATIC FUNCTION
 *******************************************************************************/

/*********************************************************************
 *** _M_DRV_Tilt_Flip_Init
 *** Initial process for TF mode
 *********************************************************************/
int _M_DRV_Tilt_Flip_Init(void)
{
	//STANDBY
	M_DRV_MC34X6_SetMode(E_M_DRV_MC34X6_MODE_STANDBY);

	//set TF Threshold
	M_DRV_MC34X6_SetTFThreshold();

	//set TF Debounce
	M_DRV_MC34X6_SetTFDebounce();

	//set TF Int
	M_DRV_MC34X6_ConfigINT(E_M_DRV_MC34X6_INT_TILT_EN | E_M_DRV_MC34X6_INT_FLIP_EN | E_M_DRV_MC34X6_INT_AUTOCLR_EN);	//tilt+flip+auto
	//M_DRV_MC34X6_ConfigINT(E_M_DRV_MC34X6_INT_TILT_EN | E_M_DRV_MC34X6_INT_AUTOCLR_EN);	//tilt+auto
	//M_DRV_MC34X6_ConfigINT(E_M_DRV_MC34X6_INT_FLIP_EN | E_M_DRV_MC34X6_INT_AUTOCLR_EN);	//flip+auto

	//set Motion Control
	M_DRV_MC34X6_ConfigMotionCtl(E_M_DRV_MC34X6_MCTL_TF_EN | E_M_DRV_MC34X6_MCTL_ZORT_POS);

	return (M_DRV_MC34X6_RETCODE_SUCCESS);
}

/*********************************************************************
 *** _M_DRV_Tilt35_Init
 *** Initial process for tilt35 mode
 *********************************************************************/
int _M_DRV_Tilt35_Init(void)
{
	//STANDBY
	M_DRV_MC34X6_SetMode(E_M_DRV_MC34X6_MODE_STANDBY);

	//set Tilt35 Threshold
	M_DRV_MC34X6_SetTILT35Threshold();

	//set Tilt35 Timer
	M_DRV_MC34X6_SetTILT35Timer();

	//set TF Int
	M_DRV_MC34X6_ConfigINT(E_M_DRV_MC34X6_INT_TILT35_EN | E_M_DRV_MC34X6_INT_AUTOCLR_EN);	//tilt35+auto

	//set Motion Control
	M_DRV_MC34X6_ConfigMotionCtl(E_M_DRV_MC34X6_MCTL_ANYM_EN | E_M_DRV_MC34X6_MCTL_TILT35_EN);  //tilt35+ANYM_ENABLE

	return (M_DRV_MC34X6_RETCODE_SUCCESS);
}

/*********************************************************************
 *** _M_DRV_ANYM_Init
 *** Initial process for ANYM mode
 *********************************************************************/
int _M_DRV_ANYM_Init(void)
{
	//STANDBY
	M_DRV_MC34X6_SetMode(E_M_DRV_MC34X6_MODE_STANDBY);

	//set ANYM Threshold
	M_DRV_MC34X6_SetANYMThreshold();

	//set ANYM Debounce
	M_DRV_MC34X6_SetANYMDebounce();

	//set ANYM Int
	M_DRV_MC34X6_ConfigINT(E_M_DRV_MC34X6_INT_ANYM_EN | E_M_DRV_MC34X6_INT_AUTOCLR_EN);	//ANYM+auto

	//set Motion Control
	M_DRV_MC34X6_ConfigMotionCtl(E_M_DRV_MC34X6_MCTL_ANYM_EN);

	return (M_DRV_MC34X6_RETCODE_SUCCESS);
}

/*********************************************************************
 *** _M_DRV_Shake_Init
 *** Initial process for Shake mode
 *********************************************************************/
int _M_DRV_Shake_Init(void)
{
	//STANDBY
	M_DRV_MC34X6_SetMode(E_M_DRV_MC34X6_MODE_STANDBY);

	//set Shake Threshold
	M_DRV_MC34X6_SetShakeThreshold();

	//set Shake counter and peak to peak duration
	M_DRV_MC34X6_SetShake_P2P_DUR_THRESH();

	//set Shake Int
	M_DRV_MC34X6_ConfigINT(E_M_DRV_MC34X6_INT_SHAKE_EN | E_M_DRV_MC34X6_INT_AUTOCLR_EN);	//shake+auto

	//set Motion Control
	M_DRV_MC34X6_ConfigMotionCtl(E_M_DRV_MC34X6_MCTL_ANYM_EN | E_M_DRV_MC34X6_MCTL_SHAKE_EN);  //shake+ANYM_ENABLE

	return (M_DRV_MC34X6_RETCODE_SUCCESS);
}

/*********************************************************************
 *** _M_DRV_LPF_Init
 *** Initial process for Low Pass Filter
 *********************************************************************/
int _M_DRV_LPF_Init(void)
{

	//STANDBY
	M_DRV_MC34X6_SetMode(E_M_DRV_MC34X6_MODE_STANDBY);

	//Set ODR to 2044Hz
	M_DRV_MC34X6_SetSampleRate(E_M_DRV_MC34X6_SR_512);

	//set Int
	M_DRV_MC34X6_ConfigINT(E_M_DRV_MC34X6_INT_DIS);				//Disable

	//set Motion Control
	M_DRV_MC34X6_ConfigMotionCtl(E_M_DRV_MC34X6_MCTL_DIS);		//Disable

	//set LPF BW, according to spec, LPF BW is closed to 128Hz
	M_DRV_MC34X6_ConfigRegResRngLPFCtrl(E_M_DRV_MC34X6_RESOLUTION_16BIT, E_M_DRV_MC34X6_RANGE_2G, \
			                            E_M_DRV_MC34X6_LPF_128Hz | E_M_DRV_MC34X6_LPF_ENABLE);

	return (M_DRV_MC34X6_RETCODE_SUCCESS);
}

/*********************************************************************
 *** M_DRV_Mode_Event
 *********************************************************************/
int M_DRV_Mode_Event(void)
{
	unsigned char _baBuf[2] = {0};

	_M_DRV_MC34X6_Delay(10240);
	_M_DRV_MC34X6_Delay(10240);
	_M_DRV_MC34X6_Delay(10240);
	_M_DRV_MC34X6_Delay(10240);
	_M_DRV_MC34X6_Delay(10240);
	M_DRV_MC34X6_GetMotion(&_baBuf[0]);

	switch(_baBuf[0])
	{
		case 5:
			M_PRINTF("-------------------- TILT35 --------------------");
			break;
		case 4:
			M_PRINTF("-------------------- SHAKE --------------------");
			break;
		case 3:
			M_PRINTF("-------------------- ANYM --------------------");
			break;
		case 2:
			M_PRINTF("-------------------- FLIP --------------------");
			break;
		case 1:
			M_PRINTF("-------------------- TILT --------------------");
			break;
	}
	return (M_DRV_MC34X6_RETCODE_SUCCESS);
}


/*********************************************************************
 *** M_DRV_MC34X6_Event_Init
 *** Sensor Initialize
 *** Select function between TF or Shake
 *********************************************************************/
int M_DRV_MC34X6_Event_Init(void)
{

#if TF_TEST
	_M_DRV_Tilt_Flip_Init();	//Tilt_Flip_Test
#elif TILT35_TEST
	_M_DRV_Tilt35_Init();		//Tilt35_Test
#elif ANYM_TEST
	_M_DRV_ANYM_Init();			//ANYM_Test
#elif SHAKE_TEST
	_M_DRV_Shake_Init(); 		//Shake_Test
#elif LPF_TEST
	_M_DRV_LPF_Init(); 			//LPF_Test
#endif

	return (M_DRV_MC34X6_RETCODE_SUCCESS);
}

