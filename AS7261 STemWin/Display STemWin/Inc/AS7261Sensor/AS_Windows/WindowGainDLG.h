/*
 * WindowGainDLG.h
 *
 *  Created on: 10 Dec 2018
 *      Author: milan
 */

#ifndef AS7261SENSOR_AS_WINDOWS_WINDOWGAINDLG_H_
#define AS7261SENSOR_AS_WINDOWS_WINDOWGAINDLG_H_

#include "DIALOG.h"


#define ID_WINDOW_0   (GUI_ID_USER + 0x00)
#define ID_TEXT_Gain  (GUI_ID_USER + 0x01)
#define ID_BUTTON_SetGain   (GUI_ID_USER + 0x03)
#define ID_BUTTON_RefreshGain   (GUI_ID_USER + 0x06)
#define ID_BUTTON_BackGain   (GUI_ID_USER + 0x07)
#define ID_TEXT_1   (GUI_ID_USER + 0x08)
#define ID_IMAGE_Gain   (GUI_ID_USER + 0x09)
#define ID_TEXT_2   (GUI_ID_USER + 0x0A)
#define ID_EDIT_Gain   (GUI_ID_USER + 0x0B)
#define ID_CHECKBOX_1x   (GUI_ID_USER + 0x0D)
#define ID_CHECKBOX_37x   (GUI_ID_USER + 0x0E)
#define ID_CHECKBOX_16x   (GUI_ID_USER + 0x0F)
#define ID_CHECKBOX_64x   (GUI_ID_USER + 0x10)

#define ID_IMAGE_0_IMAGE_0   0x00

WM_HWIN CreateWindowGain(void);

#endif /* AS7261SENSOR_AS_WINDOWS_WINDOWGAINDLG_H_ */
