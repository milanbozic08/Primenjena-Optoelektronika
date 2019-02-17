/*
 * WindowConfig.h
 *
 *  Created on: 8 Dec 2018
 *      Author: milan
 */

#ifndef AS7261SENSOR_AS_WINDOWS_WINDOWCONFIG_H_
#define AS7261SENSOR_AS_WINDOWS_WINDOWCONFIG_H_

#include "DIALOG.h"

#define ID_WINDOW_0   (GUI_ID_USER + 0x00)
#define ID_TEXT_Config   (GUI_ID_USER + 0x01)
#define ID_BUTTON_TestConnection   (GUI_ID_USER + 0x02)
#define ID_BUTTON_Gain   (GUI_ID_USER + 0x03)
#define ID_BUTTON_IntTime   (GUI_ID_USER + 0x04)
#define ID_BUTTON_SensorMode   (GUI_ID_USER + 0x05)
#define ID_BUTTON_Sampling   (GUI_ID_USER + 0x06)
#define ID_BUTTON_BackConfig   (GUI_ID_USER + 0x07)
#define ID_TEXT_1   (GUI_ID_USER + 0x08)
#define ID_IMAGE_Config   (GUI_ID_USER + 0x09)
#define ID_TEXT_2   (GUI_ID_USER + 0x0A)
#define ID_EDIT_Temp   (GUI_ID_USER + 0x0B)
#define ID_TEXT_3   (GUI_ID_USER + 0x0C)

#define ID_IMAGE_0_IMAGE_0   0x00

WM_HWIN CreateWindowConfig(void);

#endif /* AS7261SENSOR_AS_WINDOWS_WINDOWCONFIG_H_ */
