/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/main.h 
  * @author  Debug406 Team
  * @date    13-March-2018
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  * If you want to see the system's configuration to @file system_stm32f4xx.c
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "systick.h"
#include "serial.h"
#include "servo.h"
#include "board.h"
#include "buttom.h"

#include "point.h"
#include "p2l.h"
#include "line.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Main Function select */
//#define _TEST_TAG_

/* Car Hardware Version */
//#define CAR_VERSION_OLD
//#define CAR_VERSION_1
#define CAR_VERSION_NEW

/* Serial Settings */
#define _USE_BLUETOOTH

/* Gyro Settings */
#define _USE_SOFTIIC

/* Line Mode & Buttom ADC Settings */
//#define _USE_SERIAL_DEBUG

/* Exported macro ------------------------------------------------------------*/

#define _CAR_D    _CAR_FRAME_ROTATION_DIAMETER
#define _WEL_D    _CAR_WHEEL_DIAMETER
#define _ANG_COS  _CAR_FRAME_SHAFTS_ANGLE
#define _CAR_RAT  _CAR_WHEEL_SPEED_RATIO
#define _ADC_Y    _GRAYSENSOR_DISTANCE
#define _ADC_dx   _SINGLESENSOR_DISTANCE

#if defined(CAR_VERSION_OLD)
const static double _CAR_FRAME_ROTATION_DIAMETER = 24.2     /*cm*/;
const static double _CAR_FRAME_SHAFTS_ANGLE      = 0.7660444/*cos(40)*/;
const static double _CAR_WHEEL_DIAMETER          = 6.8      /*cm*/;
const static double _CAR_WHEEL_SPEED_RATIO       = 80       /*80:1*/;
const static double _GRAYSENSOR_DISTANCE         = 0        /*cm*/;
const static double _SINGLESENSOR_DISTANCE       = 0        /*cm*/;
#elif defined(CAR_VERSION_1)
const static double _CAR_FRAME_ROTATION_DIAMETER = 23.9     /*cm*/;
const static double _CAR_FRAME_SHAFTS_ANGLE      = 0.8660254/*cos(30)*/;
const static double _CAR_WHEEL_DIAMETER          = 6.8      /*cm*/;
const static double _CAR_WHEEL_SPEED_RATIO       = 80       /*80:1*/;
const static double _GRAYSENSOR_DISTANCE         = 7.4      /*cm*/;
const static double _SINGLESENSOR_DISTANCE       = 1.16     /*cm*/;
#elif defined(CAR_VERSION_NEW)
const static double _CAR_FRAME_ROTATION_DIAMETER = 24.7     /*cm*/;
const static double _CAR_FRAME_SHAFTS_ANGLE      = 0.7771459/*cos(39)*/;
const static double _CAR_WHEEL_DIAMETER          = 6.8      /*cm*/;
const static double _CAR_WHEEL_SPEED_RATIO       = 80       /*80:1*/;
const static double _GRAYSENSOR_DISTANCE         = 001      /*cm*/;
const static double _SINGLESENSOR_DISTANCE       = 1.16     /*cm*/;

const static int32_t _GOSTRAIGHT_SPEEDLEFT       = 1200;
const static int32_t _GOSTRAIGHT_SPEEDRIGHT      = 1260;
#endif

const static double _CONSTANT_OF_ROTATE_BASE     
                      = _CAR_D / _WEL_D / _ANG_COS / 360 * _CAR_RAT * 2;
const static double _CONSTANT_OF_SKEWING_BASE     
                      = 2 * 3.141592 * _CAR_D / _ANG_COS / 360 / _ADC_Y;
/* VERSION1: 0.06508979700480151145525295849497 */

/* Exported functions ------------------------------------------------------- */
#endif /* __MAIN_H */

/**
  ******************************************************************************
  * @text    PROJECT Style Guide
  * @date    15-Fabrulary-2018
  ******************************************************************************
  * @style
  *                   Head & Source    ::   lowerCamelCase  .c or .h
  *                   Parameters       ::   lowerCamelCase
  *                   Local variables  ::  _lowerCamelCase
  *    # dont use! #  Global variables ::   lowerCamelCase_g              
  *                   Enums & Union    ::   lowerCamelCase__
  *                   Structs          ::   UpperCamelCase
  *                   Global functions ::   UpperCamelCase
  *                   Local functions  ::  _UpperCamelCase
  *                   Typedefs         ::   UowerCamelCase_t
  *                   macros           ::   ALL_UPPER
  *                   Private macros   ::  _ALL_UPPER
  *                   Private define   ::  _ALL_UPPER
  *
  * @CoreStyle        
  *                   funcitons        :: UpperCamelCase_UnderscoreTolerant
  *
  ******************************************************************************
  */
