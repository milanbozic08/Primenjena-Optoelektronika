/*
 * WindowRAW.h
 *
 *  Created on: 13 Dec 2018
 *      Author: milan
 */

#ifndef AS7261SENSOR_AS_WINDOWS_WINDOWRAW_H_
#define AS7261SENSOR_AS_WINDOWS_WINDOWRAW_H_

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0   (GUI_ID_USER + 0x00)
#define ID_TEXT_RAW0   (GUI_ID_USER + 0x01)
#define ID_BUTTON_RefreshRAW  (GUI_ID_USER + 0x02)
#define ID_BUTTON_BackRAW   (GUI_ID_USER + 0x03)
#define ID_TEXT_RAW1   (GUI_ID_USER + 0x04)
#define ID_IMAGE_RAW0   (GUI_ID_USER + 0x05)
#define ID_EDIT_XRAW   (GUI_ID_USER + 0x06)
#define ID_EDIT_YRAW   (GUI_ID_USER + 0x07)
#define ID_EDIT_ZRAW   (GUI_ID_USER + 0x08)
#define ID_TEXT_RAW2   (GUI_ID_USER + 0x09)
#define ID_TEXT_RAW3   (GUI_ID_USER + 0x0A)
#define ID_TEXT_RAW4   (GUI_ID_USER + 0x0B)
#define ID_EDIT_NIRRAW   (GUI_ID_USER + 0x10)
#define ID_EDIT_DRAW   (GUI_ID_USER + 0x11)
#define ID_TEXT_RAW5   (GUI_ID_USER + 0x12)
#define ID_TEXT_RAW6   (GUI_ID_USER + 0x13)
#define ID_EDIT_CRAW   (GUI_ID_USER + 0x14)
#define ID_TEXT_RAW7   (GUI_ID_USER + 0x16)

WM_HWIN CreateWindowRAW(void);


#endif /* AS7261SENSOR_AS_WINDOWS_WINDOWRAW_H_ */
