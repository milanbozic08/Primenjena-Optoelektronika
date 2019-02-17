/*
 * WindowIntTimeDLG.h
 *
 *  Created on: 10 Dec 2018
 *      Author: milan
 */

#ifndef AS7261SENSOR_AS_WINDOWS_WINDOWINTTIMEDLG_H_
#define AS7261SENSOR_AS_WINDOWS_WINDOWINTTIMEDLG_H_

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0   (GUI_ID_USER + 0x00)
#define ID_TEXT_IntTime   (GUI_ID_USER + 0x01)
#define ID_BUTTON_SetTimeIntTime   (GUI_ID_USER + 0x03)
#define ID_BUTTON_RefreshIntTime   (GUI_ID_USER + 0x06)
#define ID_BUTTON_BackIntTime   (GUI_ID_USER + 0x07)
#define ID_TEXT_IntTime1   (GUI_ID_USER + 0x08)
#define ID_IMAGE_IntTime   (GUI_ID_USER + 0x09)
#define ID_TEXT_IntTime2   (GUI_ID_USER + 0x0A)
#define ID_EDIT_IntTime   (GUI_ID_USER + 0x0B)
#define ID_TEXT_IntTime3   (GUI_ID_USER + 0x0C)
#define ID_SPINBOX_IntTime   (GUI_ID_USER + 0x0E)

#define ID_IMAGE_0_IMAGE_0   0x00

WM_HWIN CreateWindowIntTime(void);

#endif /* AS7261SENSOR_AS_WINDOWS_WINDOWINTTIMEDLG_H_ */
