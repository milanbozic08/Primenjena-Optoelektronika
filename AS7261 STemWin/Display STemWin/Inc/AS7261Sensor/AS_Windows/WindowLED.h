/*
 * WindowLED.h
 *
 *  Created on: 13 Dec 2018
 *      Author: milan
 */

#ifndef AS7261SENSOR_AS_WINDOWS_WINDOWLED_H_
#define AS7261SENSOR_AS_WINDOWS_WINDOWLED_H_

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_LED0   (GUI_ID_USER + 0x00)
#define ID_BUTTON_RefreshLED   (GUI_ID_USER + 0x02)
#define ID_BUTTON_BackLED   (GUI_ID_USER + 0x03)
#define ID_TEXT_LED0   (GUI_ID_USER + 0x04)
#define ID_IMAGE_LED0   (GUI_ID_USER + 0x05)
#define ID_BUTTON_SetLED0   (GUI_ID_USER + 0x13)
#define ID_BUTTON_SetLED1   (GUI_ID_USER + 0x14)
#define ID_RADIO_LED0   (GUI_ID_USER + 0x15)
#define ID_RADIO_LED1   (GUI_ID_USER + 0x16)
#define ID_EDIT_LED0   (GUI_ID_USER + 0x17)
#define ID_BUTTON_LED0On   (GUI_ID_USER + 0x18)
#define ID_BUTTON_LED1On   (GUI_ID_USER + 0x19)
#define ID_EDIT_LED1   (GUI_ID_USER + 0x1A)
#define ID_TEXT_LED1   (GUI_ID_USER + 0x1B)

#define ID_IMAGE_0_IMAGE_0   0x00


WM_HWIN CreateWindowLED(void);

#endif /* AS7261SENSOR_AS_WINDOWS_WINDOWLED_H_ */
