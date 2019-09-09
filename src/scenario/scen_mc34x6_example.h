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

#ifndef _M_DRV_MC34X6_TF_SHAKE_H_
#define _M_DRV_MC34X6_TF_SHAKE_H_

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 *** CONSTANT / DEFINE
 *******************************************************************************/
#define TF_TEST			0
#define TILT35_TEST		0
#define ANYM_TEST		0
#define SHAKE_TEST		0
#define LPF_TEST		0

/*****************************************************************************
 *** DATA TYPE / STRUCTURE DEFINITION / ENUM
 *****************************************************************************/

/*******************************************************************************
 *******************************   STRUCTS   ***********************************
 ******************************************************************************/

/*******************************************************************************
 *****************************   PROTOTYPES   **********************************
 ******************************************************************************/
extern int M_DRV_Mode_Event(void);
extern int M_DRV_MC34X6_Event_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* __TEMPSENS_H */
