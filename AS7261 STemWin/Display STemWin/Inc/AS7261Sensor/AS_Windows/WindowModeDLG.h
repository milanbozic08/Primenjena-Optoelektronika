/*
 * WindowModeDLG.h
 *
 *  Created on: 11 Dec 2018
 *      Author: milan
 */

#ifndef AS7261SENSOR_AS_WINDOWS_WINDOWMODEDLG_H_
#define AS7261SENSOR_AS_WINDOWS_WINDOWMODEDLG_H_

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0   (GUI_ID_USER + 0x00)
#define ID_TEXT_Mode  (GUI_ID_USER + 0x01)
#define ID_BUTTON_SetMode   (GUI_ID_USER + 0x02)
#define ID_BUTTON_RefreshMode   (GUI_ID_USER + 0x03)
#define ID_BUTTON_BackMode   (GUI_ID_USER + 0x04)
#define ID_TEXT_Mode1   (GUI_ID_USER + 0x05)
#define ID_IMAGE_Mode0   (GUI_ID_USER + 0x06)
#define ID_TEXT_Mode2   (GUI_ID_USER + 0x07)
#define ID_EDIT_CurrentMode   (GUI_ID_USER + 0x08)
#define ID_EDIT_Descripton   (GUI_ID_USER + 0x0E)
#define ID_RADIO_Mode   (GUI_ID_USER + 0x0F)

#define ID_IMAGE_0_IMAGE_0   0x00

WM_HWIN CreateWindowMode(void);

#endif /* AS7261SENSOR_AS_WINDOWS_WINDOWMODEDLG_H_ */
