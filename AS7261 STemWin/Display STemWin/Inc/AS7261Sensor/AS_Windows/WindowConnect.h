/*
 * WindowConnect.h
 *
 *  Created on: 7 Dec 2018
 *      Author: milan
 */

#ifndef AS7261SENSOR_AS_WINDOWS_WINDOWCONNECT_H_
#define AS7261SENSOR_AS_WINDOWS_WINDOWCONNECT_H_

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0   (GUI_ID_USER + 0x00)
#define ID_PROGBAR_0   (GUI_ID_USER + 0x01)
#define ID_IMAGE_0   (GUI_ID_USER + 0x02)
#define ID_TEXT_0   (GUI_ID_USER + 0x03)
#define ID_BUTTON_TEST   (GUI_ID_USER + 0x04)
#define ID_BUTTON_EXIT   (GUI_ID_USER + 0x05)
#define ID_TEXT_OK   (GUI_ID_USER + 0x07)
#define ID_TEXT_FAIL   (GUI_ID_USER + 0x08)

#define ID_IMAGE_0_IMAGE_0   0x00

extern int ConnectOK;

WM_HWIN CreateWindowConnect(void);

#endif /* AS7261SENSOR_AS_WINDOWS_WINDOWCONNECT_H_ */
