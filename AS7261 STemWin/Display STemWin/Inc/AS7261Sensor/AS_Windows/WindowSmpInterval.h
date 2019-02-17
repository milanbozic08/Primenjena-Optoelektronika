/*
 * WindowSmpInterval.h
 *
 *  Created on: 11 Dec 2018
 *      Author: milan
 */

#ifndef AS7261SENSOR_AS_WINDOWS_WINDOWSMPINTERVAL_H_
#define AS7261SENSOR_AS_WINDOWS_WINDOWSMPINTERVAL_H_

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0   (GUI_ID_USER + 0x00)
#define ID_TEXT_SMP0   (GUI_ID_USER + 0x01)
#define ID_BUTTON_SetSMP   (GUI_ID_USER + 0x02)
#define ID_BUTTON_RefreshSMP   (GUI_ID_USER + 0x03)
#define ID_BUTTON_BackSMP   (GUI_ID_USER + 0x04)
#define ID_TEXT_SMP1   (GUI_ID_USER + 0x05)
#define ID_IMAGE_SMP0   (GUI_ID_USER + 0x06)
#define ID_TEXT_SMP2   (GUI_ID_USER + 0x07)
#define ID_EDIT_CurrentIntSMP   (GUI_ID_USER + 0x08)
#define ID_TEXT_SMP3   (GUI_ID_USER + 0x09)
#define ID_SLIDER_SMP   (GUI_ID_USER + 0x0A)
#define ID_SPINBOX_SMP   (GUI_ID_USER + 0x0B)

#define ID_IMAGE_0_IMAGE_0   0x00


WM_HWIN CreateWindowSMPInterval(void);

#endif /* AS7261SENSOR_AS_WINDOWS_WINDOWSMPINTERVAL_H_ */
