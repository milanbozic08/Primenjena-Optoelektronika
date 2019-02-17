/*
 * WindowCalibratedData.h
 *
 *  Created on: 12 Dec 2018
 *      Author: milan
 */

#ifndef AS7261SENSOR_AS_WINDOWS_WINDOWCALIBRATEDDATANEW_H_
#define AS7261SENSOR_AS_WINDOWS_WINDOWCALIBRATEDDATANEW_H_


#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0   (GUI_ID_USER + 0x00)
#define ID_TEXT_CD0   (GUI_ID_USER + 0x01)
#define ID_BUTTON_RefreshCD   (GUI_ID_USER + 0x03)
#define ID_BUTTON_BackCD   (GUI_ID_USER + 0x04)
#define ID_TEXT_CD1   (GUI_ID_USER + 0x05)
#define ID_IMAGE_CD0   (GUI_ID_USER + 0x06)
#define ID_EDIT_XCD   (GUI_ID_USER + 0x0C)
#define ID_EDIT_YCD   (GUI_ID_USER + 0x0D)
#define ID_EDIT_ZCD   (GUI_ID_USER + 0x0E)
#define ID_TEXT_CD2   (GUI_ID_USER + 0x0F)
#define ID_TEXT_CD3   (GUI_ID_USER + 0x10)
#define ID_TEXT_CD4   (GUI_ID_USER + 0x11)
#define ID_EDIT_LUXCD   (GUI_ID_USER + 0x12)
#define ID_TEXT_CD5   (GUI_ID_USER + 0x13)
#define ID_TEXT_CD6   (GUI_ID_USER + 0x14)
#define ID_EDIT_CCTCD   (GUI_ID_USER + 0x15)
#define ID_EDIT_xCD   (GUI_ID_USER + 0x16)
#define ID_EDIT_yCD   (GUI_ID_USER + 0x17)
#define ID_TEXT_CD7   (GUI_ID_USER + 0x18)
#define ID_TEXT_CD8   (GUI_ID_USER + 0x19)
#define ID_GRAPH_CD   (GUI_ID_USER + 0x1A)
#define ID_BUTTON_LUXG   (GUI_ID_USER + 0x1B)
#define ID_BUTTON_CCTG   (GUI_ID_USER + 0x1C)

#define ID_IMAGE_0_IMAGE_0   0x00


WM_HWIN CreateWindowCalibratedData(void);

#endif /* AS7261SENSOR_AS_WINDOWS_WINDOWCALIBRATEDDATANEW_H_ */
