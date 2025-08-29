/*****************************************************************************

 Project Name		: SDP - SOC Development Project
 Project Code		: ET1035
 Created		: 23-Nov-2024
 Filename		: pwm.h
 Purpose		: Configuration for different peripherals
 Description		: Base address/configuration for peripherals 
 Author(s)		: Manjunath Inamati
 Email			: manjunathinamati80@gmail.com
    
 See LICENSE for license details.
******************************************************************************/

#ifndef _PWMC_H
#define _PWMC_H
/**
 @file pwmc.h
 @brief header file for PWMC driver
 @detail 
 */

/*  Include section
* 
*
***************************************************/

#include "stdlib.h"	//for datatypes
#include "config.h"	//for base address

typedef unsigned char UC;  // 1 Byte
typedef unsigned short US; // 2 Bytes
typedef unsigned int UI;   // 4 Bytes
typedef unsigned long UL;  // 8 Bytes

/** Definition section*/

typedef struct pwm_reg
{
	UI PWM_DC;     // Duty Cycle register  0x00
	
}PWM_REG;

#define pwm_reg (*((volatile PWM_REG*)(PWM_BASE_ADDR)))

// Function prototypes
void PWM_Set_Duty(UI Duty);

#endif	/* _PWMC_H */	





