/*
 * WindowMenu.h
 *
 *  Created on: 7 Dec 2018
 *      Author: milan
 */

#ifndef AS7261SENSOR_AS_WINDOWS_WINDOWMENU_H_
#define AS7261SENSOR_AS_WINDOWS_WINDOWMENU_H_

#include "DIALOG.h"
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_MENU   (GUI_ID_USER + 0x00)
#define ID_TEXT_Menu   (GUI_ID_USER + 0x04)
#define ID_BUTTON_XYZ   (GUI_ID_USER + 0x05)
#define ID_BUTTON_SpecData   (GUI_ID_USER + 0x06)
#define ID_BUTTON_Config   (GUI_ID_USER + 0x07)
#define ID_BUTTON_LEDDrv   (GUI_ID_USER + 0x08)
#define ID_BUTTON_SysRst   (GUI_ID_USER + 0x09)
#define ID_BUTTON_Back   (GUI_ID_USER + 0x0A)
#define ID_TEXT_AS   (GUI_ID_USER + 0x0C)
#define ID_IMAGE_RGB   (GUI_ID_USER + 0x0D)

#define ID_IMAGE_0_IMAGE_0   0x00

WM_HWIN CreateWindowMenu(void);


#endif /* AS7261SENSOR_AS_WINDOWS_WINDOWMENU_H_ */
