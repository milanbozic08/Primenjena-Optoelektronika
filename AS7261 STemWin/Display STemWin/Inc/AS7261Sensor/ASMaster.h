/*
 * ASMaster.h
 *
 *  Created on: 7 Dec 2018
 *      Author: milan
 */

#ifndef AS7261SENSOR_ASMASTER_H_
#define AS7261SENSOR_ASMASTER_H_

#include <AS7261Sensor/AS_Windows/WindowCalibratedDataNew.h>
#include "AS7261Sensor/AS_ATCommands.h"
#include "AS7261Sensor/AS_Windows/WindowMenu.h"
#include "AS7261Sensor/AS_Windows/WindowConnect.h"
#include "AS7261Sensor/AS_Windows/WindowConfig.h"
#include "AS7261Sensor/AS_Windows/WindowGainDLG.h"
#include "AS7261Sensor/AS_Windows/WindowIntTimeDLG.h"
#include "AS7261Sensor/AS_Windows/WindowModeDLG.h"
#include "AS7261Sensor/AS_Windows/WindowSmpInterval.h"
#include "AS7261Sensor/AS_Windows/WindowRAW.h"
#include "AS7261Sensor/AS_Windows/WindowLED.h"

void ConfigMenu();

void AS7261_Sensor();
void TestConnection();
void Gain();
void IntegrationTime();
void Mode();
void SamplingIntervalFunction();
void Merenja();
void XYZ();
void RAW();
void OsveziLed();
void LED();

#endif /* AS7261SENSOR_ASMASTER_H_ */
