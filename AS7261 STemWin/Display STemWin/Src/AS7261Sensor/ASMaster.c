/*
 * ASMaster.c
 *
 *  Created on: 7 Dec 2018
 *      Author: milan
 */

#include "AS7261Sensor/ASMaster.h"
#include <stdlib.h>

int keyPressed=100;
WM_HWIN hWin;
int i=0;
float Temperatura=0;
char TempMsg[5]={'\0','\0','\0','\0','\0'};

int Xceo=0,Xdec=0,Zceo=0,Zdec=0,Yceo=0,Ydec=0;
int LUXceo=0,LUXdec=0;
int CCTceo=0,CCTdec=0;
int smallx=0,smallx1=0,smally=0,smally1=0;

uint8_t LEDind=0,LedDrv=0,LEDSet=0,LED0Read=0,LED1Read=0;




void AS7261_Sensor()
{

	while(1)
	{	keyPressed=100;

		hWin = CreateWindowMenu();  //Kreiraj MENU

		GUI_Exec();
		GUI_Delay(100);

		while(keyPressed!=ID_BUTTON_XYZ && keyPressed!=ID_BUTTON_Back && keyPressed!=ID_BUTTON_Config && keyPressed!=ID_BUTTON_LEDDrv && keyPressed!=ID_BUTTON_SpecData && keyPressed!=ID_BUTTON_SysRst)		//Cekaj Dok se ne stisne neko dugme
		{
			STMPE610_read_xyz();
			GUI_TOUCH_Exec();
			keyPressed=GUI_GetKey();
			GUI_Delay(10);
		}

		switch(keyPressed)
			  {
				case ID_BUTTON_XYZ:

					XYZ();
					break;

				case ID_BUTTON_SpecData:

					RAW();
					break;

				case ID_BUTTON_Config:

					ConfigMenu();
					break;

				case ID_BUTTON_LEDDrv:

					LED();
				break;

			case ID_BUTTON_SysRst:

				AS_Reset();
					break;

				case (GUI_ID_USER + 0x0A):

					break;
				default : break;
			  }
	}
}

void Mode()
{
	uint8_t CurrentMode;
	uint8_t ReadRadioBut;

	hWin= CreateWindowMode();
	GUI_Exec();

	AS_Read_SensorMode(&CurrentMode);
	sprintf(TempMsg, "%1d",(int)CurrentMode);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_CurrentMode), TempMsg);
	GUI_Exec();

	do
	{
		STMPE610_read_xyz();
		GUI_TOUCH_Exec();
		keyPressed=GUI_GetKey();


		switch(RADIO_GetValue(WM_GetDialogItem(hWin, ID_RADIO_Mode)))
		{
		case 0:
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Descripton), "0 -> Captures X, Y, Z, and IR (1 integration period)");
			GUI_Exec();
			break;
		case 1:
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Descripton), "1 -> Captures X, Y, Dk, and CLR (1 integration period)");
			GUI_Exec();
			break;
		case 2:
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Descripton), "2 -> Captures X, Y, Z, Dk, IR and CLR (2 integration period)");
			GUI_Exec();
			break;
		case 3:
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Descripton), "3 -> Sensors are OFF");
			GUI_Exec();
			break;
		default: break;
		}


		if(keyPressed== ID_BUTTON_RefreshMode)
		{
			AS_Read_SensorMode(&CurrentMode);
			sprintf(TempMsg, "%1d",(int)CurrentMode);
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_CurrentMode), TempMsg);
			GUI_Exec();
		}
		if(keyPressed== ID_BUTTON_SetMode)
		{
			ReadRadioBut=RADIO_GetValue(WM_GetDialogItem(hWin, ID_RADIO_Mode));
			AS_Set_SensorMode(ReadRadioBut);
		}
		GUI_Delay(10);
	}
	while(keyPressed!= ID_BUTTON_BackMode);
	while(keyPressed== ID_BUTTON_BackMode)
	{
		STMPE610_read_xyz();
		GUI_TOUCH_Exec();
		keyPressed=GUI_GetKey();
	}

	hWin= CreateWindowConfig();
	GUI_Exec();

	AS_Read_Temp(&Temperatura);
	sprintf(TempMsg, "%d",(int)Temperatura);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Temp), TempMsg);
	GUI_Exec();
}

void TestConnection()
{
	hWin=CreateWindowConnect();
	GUI_Exec();

	do{
	  STMPE610_read_xyz();
	  GUI_TOUCH_Exec();
	  keyPressed=GUI_GetKey();

	  if(keyPressed==ID_BUTTON_TEST)
		{
			i=0;
			while(i<30)
				{
					i++;
					PROGBAR_SetValue(WM_GetDialogItem(hWin,ID_PROGBAR_0),i);
					GUI_Exec();
					HAL_Delay(20);
				}

			ConnectOK=AS_Test();


			while(i<100)
				{
					i++;
					PROGBAR_SetValue(WM_GetDialogItem(hWin,ID_PROGBAR_0),i);
					GUI_Exec();
					HAL_Delay(20);
				}
			if(ConnectOK)
			{
				TEXT_SetTextColor(WM_GetDialogItem(hWin, ID_TEXT_OK), GUI_MAKE_COLOR(0x00E10011));
				TEXT_SetText(WM_GetDialogItem(hWin, ID_TEXT_OK), "CONNECTION OK");
				GUI_Exec();

			}
			else
			{
				TEXT_SetTextColor(WM_GetDialogItem(hWin, ID_TEXT_OK), GUI_MAKE_COLOR(0x000000F4));
				TEXT_SetText(WM_GetDialogItem(hWin, ID_TEXT_OK), "CONNECTION FAIL");
				GUI_Exec();
			}

			GUI_Exec();
			GUI_Delay(10);
		}

		  GUI_Delay(10);
	  }
	while(keyPressed!= (GUI_ID_USER + 0x05));
	while(keyPressed== (GUI_ID_USER + 0x05))
	{
	  STMPE610_read_xyz();
	  GUI_TOUCH_Exec();
	  keyPressed=GUI_GetKey();

	}


	hWin= CreateWindowConfig();
	GUI_Exec();

	AS_Read_Temp(&Temperatura);
	sprintf(TempMsg, "%d",(int)Temperatura);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Temp), TempMsg);
	GUI_Exec();
}

void Gain()
{
	uint8_t ReadGain=0;
	uint8_t NumforSet=0;

	hWin= CreateWindowGain();
	GUI_Exec();

	AS_Read_Gain(&ReadGain);
	NumforSet=ReadGain;

	switch(ReadGain)
	{
	case 0:
		sprintf(TempMsg, "1X");
		EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Gain), TempMsg);
		GUI_Exec();
		break;

	case 1:
		sprintf(TempMsg, "3.7X");
		EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Gain), TempMsg);
		GUI_Exec();
		break;

	case 2:
		sprintf(TempMsg, "16X");
		EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Gain), TempMsg);
		GUI_Exec();
		break;

	case 3:
		sprintf(TempMsg, "64X");
		EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Gain), TempMsg);
		GUI_Exec();
		break;

	default : break;
	}

	do{
		  STMPE610_read_xyz();
		  GUI_TOUCH_Exec();
		  keyPressed=GUI_GetKey();

		  GUI_Delay(10);

		  if(CHECKBOX_IsChecked(WM_GetDialogItem(hWin,ID_CHECKBOX_1x)))
		  {
			  CHECKBOX_SetState(WM_GetDialogItem(hWin,ID_CHECKBOX_16x),0);
			  CHECKBOX_SetState(WM_GetDialogItem(hWin,ID_CHECKBOX_37x),0);
			  CHECKBOX_SetState(WM_GetDialogItem(hWin,ID_CHECKBOX_64x),0);
			  NumforSet=0;
		  }
		  if(CHECKBOX_IsChecked(WM_GetDialogItem(hWin,ID_CHECKBOX_16x)))
		  {
			  CHECKBOX_SetState(WM_GetDialogItem(hWin,ID_CHECKBOX_1x),0);
			  CHECKBOX_SetState(WM_GetDialogItem(hWin,ID_CHECKBOX_37x),0);
			  CHECKBOX_SetState(WM_GetDialogItem(hWin,ID_CHECKBOX_64x),0);
			  NumforSet=1;
		  }
		  if(CHECKBOX_IsChecked(WM_GetDialogItem(hWin,ID_CHECKBOX_37x)))
		  {
			  CHECKBOX_SetState(WM_GetDialogItem(hWin,ID_CHECKBOX_16x),0);
			  CHECKBOX_SetState(WM_GetDialogItem(hWin,ID_CHECKBOX_1x),0);
			  CHECKBOX_SetState(WM_GetDialogItem(hWin,ID_CHECKBOX_64x),0);
			  NumforSet=2;
		  }
		  if(CHECKBOX_IsChecked(WM_GetDialogItem(hWin,ID_CHECKBOX_64x)))
		  {
			  CHECKBOX_SetState(WM_GetDialogItem(hWin,ID_CHECKBOX_16x),0);
			  CHECKBOX_SetState(WM_GetDialogItem(hWin,ID_CHECKBOX_37x),0);
			  CHECKBOX_SetState(WM_GetDialogItem(hWin,ID_CHECKBOX_1x),0);
			  NumforSet=3;
		  }

		  if(keyPressed==ID_BUTTON_SetGain)
		  {
			  AS_Set_Gain(NumforSet);
		  }

		  if(keyPressed==ID_BUTTON_RefreshGain)
		  {
			    AS_Read_Gain(&ReadGain);
				NumforSet=ReadGain;

				switch(ReadGain)
				{
				case 0:
					sprintf(TempMsg, "1X");
					EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Gain), TempMsg);
					GUI_Exec();
					break;

				case 1:
					sprintf(TempMsg, "3.7X");
					EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Gain), TempMsg);
					GUI_Exec();
					break;

				case 2:
					sprintf(TempMsg, "16X");
					EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Gain), TempMsg);
					GUI_Exec();
					break;

				case 3:
					sprintf(TempMsg, "64X");
					EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Gain), TempMsg);
					GUI_Exec();
					break;

				default : break;
				}
		  }

	  }
	while(keyPressed!= ID_BUTTON_BackGain);
	while(keyPressed== ID_BUTTON_BackGain)
	{
		STMPE610_read_xyz();
		GUI_TOUCH_Exec();
		keyPressed=GUI_GetKey();
	}
	hWin= CreateWindowConfig();
	GUI_Exec();

	AS_Read_Temp(&Temperatura);
	sprintf(TempMsg, "%d",(int)Temperatura);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Temp), TempMsg);
	GUI_Exec();



}

void IntegrationTime()
{
	uint8_t IntTime;

	hWin= CreateWindowIntTime();
	GUI_Exec();

	AS_Read_IntegrationTime(&IntTime);
	sprintf(TempMsg, "%3d",(int)IntTime);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_IntTime), TempMsg);
	GUI_Exec();

	do
	{
		STMPE610_read_xyz();
		GUI_TOUCH_Exec();
		keyPressed=GUI_GetKey();

		if(keyPressed==ID_BUTTON_RefreshIntTime)
		{
			AS_Read_IntegrationTime(&IntTime);
			sprintf(TempMsg, "%3d",IntTime);
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_IntTime), TempMsg);
			GUI_Exec();
		}

		if(keyPressed==ID_BUTTON_SetTimeIntTime)
		{
			AS_Set_IntegrationTime(SPINBOX_GetValue(WM_GetDialogItem(hWin, ID_SPINBOX_IntTime)));
		}

		GUI_Delay(10);
	}
	while(keyPressed!=ID_BUTTON_BackIntTime);
	while(keyPressed==ID_BUTTON_BackIntTime)
	{
		STMPE610_read_xyz();
		GUI_TOUCH_Exec();
		keyPressed=GUI_GetKey();
	}

	hWin= CreateWindowConfig();
	GUI_Exec();

	AS_Read_Temp(&Temperatura);
	sprintf(TempMsg, "%d",(int)Temperatura);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Temp), TempMsg);
	GUI_Exec();
}

void SamplingIntervalFunction()
{
	uint8_t SliderBackValue,SliderCurValue;
	uint8_t SamplingValue;

	hWin= CreateWindowSMPInterval();
	GUI_Exec();

	SLIDER_SetRange(WM_GetDialogItem(hWin, ID_SLIDER_SMP),1,255);
	SLIDER_SetValue(WM_GetDialogItem(hWin, ID_SLIDER_SMP),100);
	SPINBOX_SetValue(WM_GetDialogItem(hWin, ID_SPINBOX_SMP),100);
	SPINBOX_SetRange(WM_GetDialogItem(hWin, ID_SPINBOX_SMP),1,255);
	SliderBackValue=100;
	SliderCurValue=100;

	AS_Read_SemplingInterval(&SamplingValue);
	sprintf(TempMsg, "%d",(int)SamplingValue);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_CurrentIntSMP), TempMsg);
	GUI_Exec();

	do
	{
		STMPE610_read_xyz();
		GUI_TOUCH_Exec();
		keyPressed=GUI_GetKey();

		SliderCurValue=SLIDER_GetValue(WM_GetDialogItem(hWin, ID_SLIDER_SMP));
		if(SliderCurValue!=SliderBackValue)
		{
			SliderBackValue=SliderCurValue;
			SPINBOX_SetValue(WM_GetDialogItem(hWin, ID_SPINBOX_SMP),SliderCurValue);
		}

		if(keyPressed== ID_BUTTON_SetSMP)
		{
			SamplingValue=SPINBOX_GetValue(WM_GetDialogItem(hWin, ID_SPINBOX_SMP));
			AS_Set_SemplingInterval(SamplingValue);
		}

		if(keyPressed== ID_BUTTON_RefreshSMP)
		{
			AS_Read_SemplingInterval(&SamplingValue);
			sprintf(TempMsg, "%d",(int)SamplingValue);
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_CurrentIntSMP), TempMsg);
			GUI_Exec();
		}

		GUI_Delay(10);

	}
	while(keyPressed!= ID_BUTTON_BackSMP);
	while(keyPressed== ID_BUTTON_BackSMP)
	{
		STMPE610_read_xyz();
		GUI_TOUCH_Exec();
		keyPressed=GUI_GetKey();
	}

	hWin= CreateWindowConfig();
	GUI_Exec();

	AS_Read_Temp(&Temperatura);
	sprintf(TempMsg, "%d",(int)Temperatura);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Temp), TempMsg);
	GUI_Exec();

}

void ConfigMenu()
{
	hWin= CreateWindowConfig();
	GUI_Exec();

	AS_Read_Temp(&Temperatura);
	sprintf(TempMsg, "%d",(int)Temperatura);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_Temp), TempMsg);
	GUI_Exec();

	do{
		STMPE610_read_xyz();
		GUI_TOUCH_Exec();
		keyPressed=GUI_GetKey();

		if(keyPressed==ID_BUTTON_TestConnection)
		{
			TestConnection();
		}

		if(keyPressed==ID_BUTTON_Gain)
		{
			Gain();
		}

		if(keyPressed==ID_BUTTON_IntTime)
		{
			IntegrationTime();
		}

		if(keyPressed==ID_BUTTON_SensorMode)
		{
			Mode();
		}

		if(keyPressed==ID_BUTTON_Sampling)
		{
			SamplingIntervalFunction();
		}

		GUI_Delay(10);
	  }
	while(keyPressed!= ID_BUTTON_BackConfig); //ConfigBack
}


void Merenja()
{
	AS_Read_XYZ(&Xceo,&Xdec,&Yceo,&Ydec,&Zceo,&Zdec);
	AS_Read_LUX(&LUXceo,&LUXdec);
	AS_Read_CCT(&CCTceo,&CCTdec);
	AS_Read_SMAllxy(&smallx,&smallx1,&smally,&smally1);

	sprintf(TempMsg, "%d,%d",Xceo,Xdec);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_XCD), TempMsg);
	sprintf(TempMsg, "%d,%d",Yceo,Ydec);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_YCD), TempMsg);
	sprintf(TempMsg, "%d,%d",Zceo,Zdec);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_ZCD), TempMsg);
	sprintf(TempMsg, "%d,%d",LUXceo,LUXdec);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_LUXCD), TempMsg);
	sprintf(TempMsg, "%d,%d",CCTceo,CCTdec);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_CCTCD), TempMsg);
	sprintf(TempMsg, "%d,%d",smallx,smallx1);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_xCD), TempMsg);
	sprintf(TempMsg, "%d,%d",smally,smally1);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_yCD), TempMsg);
	GUI_Exec();
}

void XYZ()
{
	int luxGraph=0,CCTGraph=0;

	GRAPH_DATA_Handle hData;
	GRAPH_DATA_Handle hData1;


	hWin= CreateWindowCalibratedData();
	GUI_Exec();

	hData=GRAPH_DATA_YT_Create(GUI_BLUE, 440, 0, 0);
	hData1=GRAPH_DATA_YT_Create(GUI_RED, 440, 0, 0);
	GRAPH_AttachData(WM_GetDialogItem(hWin, ID_GRAPH_CD), hData);
	GRAPH_AttachData(WM_GetDialogItem(hWin, ID_GRAPH_CD), hData1);
	GUI_Exec();

	Merenja();
	do
	{

		STMPE610_read_xyz();
		GUI_TOUCH_Exec();
		keyPressed=GUI_GetKey();

		GUI_Exec();


		if(keyPressed==ID_BUTTON_RefreshCD )
		{
			Merenja();

		}
		if(keyPressed==ID_BUTTON_LUXG)
		{
			if(luxGraph==1)
				luxGraph=0;
			else
				luxGraph=1;
		}

		if(keyPressed==ID_BUTTON_CCTG)
		{
			if(CCTGraph==1)
				CCTGraph=0;
			else
				CCTGraph=1;
		}

		if(luxGraph==1)
		{
			AS_Read_LUX(&LUXceo,&LUXdec);
			GRAPH_DATA_YT_AddValue(hData, (uint16_t)(LUXceo/10));
			sprintf(TempMsg, "%d,%d",LUXceo,LUXdec);
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_LUXCD), TempMsg);
			GUI_Exec();
		}
		if(CCTGraph==1)
		{
			AS_Read_CCT(&CCTceo,&CCTdec);
			GRAPH_DATA_YT_AddValue(hData1, (uint16_t)(CCTceo/400));
			sprintf(TempMsg, "%d,%d",CCTceo,CCTdec);
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_CCTCD), TempMsg);
			GUI_Exec();
		}

		GUI_Delay(10);
	}
	while(keyPressed!=ID_BUTTON_BackCD);
	while(keyPressed==ID_BUTTON_BackCD)
	{
		STMPE610_read_xyz();
		GUI_TOUCH_Exec();
		keyPressed=GUI_GetKey();
	}
	hWin= CreateWindowMenu();
	GUI_Exec();
}


void RAW()
{
	int XRAW,YRAW,ZRAW,NIRRAW,DRAW,CRAW;

	hWin= CreateWindowRAW();
	GUI_Exec();


	AS_Read_AllData_RAW(&XRAW,&YRAW,&ZRAW,&NIRRAW,&DRAW,&CRAW);

	sprintf(TempMsg, "%d",(int)XRAW);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_XRAW), TempMsg);
	sprintf(TempMsg, "%d",(int)YRAW);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_YRAW), TempMsg);
	sprintf(TempMsg, "%d",(int)ZRAW);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_ZRAW), TempMsg);
	sprintf(TempMsg, "%d",(int)NIRRAW);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_NIRRAW), TempMsg);
	sprintf(TempMsg, "%d",(int)DRAW);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_DRAW), TempMsg);
	sprintf(TempMsg, "%d",(int)CRAW);
	EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_CRAW), TempMsg);
	GUI_Exec();


	do
	{
		STMPE610_read_xyz();
		GUI_TOUCH_Exec();
		keyPressed=GUI_GetKey();


		if(keyPressed==ID_BUTTON_RefreshRAW)
		{
			AS_Read_AllData_RAW(&XRAW,&YRAW,&ZRAW,&NIRRAW,&DRAW,&CRAW);

			sprintf(TempMsg, "%d",(int)XRAW);
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_XRAW), TempMsg);
			sprintf(TempMsg, "%d",(int)YRAW);
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_YRAW), TempMsg);
			sprintf(TempMsg, "%d",(int)ZRAW);
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_ZRAW), TempMsg);
			sprintf(TempMsg, "%d",(int)NIRRAW);
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_NIRRAW), TempMsg);
			sprintf(TempMsg, "%d",(int)DRAW);
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_DRAW), TempMsg);
			sprintf(TempMsg, "%d",(int)CRAW);
			EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_CRAW), TempMsg);
			GUI_Exec();
		}
		GUI_Delay(10);

	}
	while(keyPressed!=ID_BUTTON_BackRAW);
	while(keyPressed==ID_BUTTON_BackRAW)
	{
		STMPE610_read_xyz();
		GUI_TOUCH_Exec();
		keyPressed=GUI_GetKey();
	}
	hWin= CreateWindowMenu();
	GUI_Exec();
}



void OsveziLed()
{
	AS_Read_LED_Indicate(&LEDind);
	AS_Read_LED_DRV(&LedDrv);

	if(LEDind==0)
	{

		BUTTON_SetText(WM_GetDialogItem(hWin, ID_BUTTON_LED0On),"ON");
		GUI_Exec();

	}
	else
	{
		BUTTON_SetText(WM_GetDialogItem(hWin, ID_BUTTON_LED0On),"OFF");
		GUI_Exec();
	}

	if(LedDrv==0)
	{

		BUTTON_SetText(WM_GetDialogItem(hWin, ID_BUTTON_LED1On),"ON");
		GUI_Exec();

	}
	else
	{
		BUTTON_SetText(WM_GetDialogItem(hWin, ID_BUTTON_LED1On),"OFF");
		GUI_Exec();
	}}


void LED()
{
	hWin= CreateWindowLED();
	GUI_Exec();

	do
	{
		STMPE610_read_xyz();
		GUI_TOUCH_Exec();
		keyPressed=GUI_GetKey();


		if(keyPressed==ID_BUTTON_RefreshLED)
		{
			OsveziLed();
			AS_Read_LEDCurrent(&LED0Read,&LED1Read);

			switch(LED1Read)
			{
			case 0:

				EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_LED0), "1mA");
				GUI_Exec();
				break;
			case 1:

				EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_LED0), "2mA");
				GUI_Exec();
				break;
			case 2:

				EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_LED0), "4mA");
				GUI_Exec();
				break;
			case 3:

				EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_LED0), "8mA");
				GUI_Exec();
				break;
			default : break;
			}

			switch(LED0Read)
			{
			case 0:

				EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_LED1), "12.5mA");
				GUI_Exec();
				break;
			case 1:

				EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_LED1), "25mA");
				GUI_Exec();
				break;
			case 2:

				EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_LED1), "50mA");
				GUI_Exec();
				break;
			case 3:

				EDIT_SetText(WM_GetDialogItem(hWin, ID_EDIT_LED1), "100mA");
				GUI_Exec();
				break;
			default : break;
			}

		}

		if(keyPressed==ID_BUTTON_LED0On)
		{
			if(LEDind==0)
			AS_Set_LED_Indicate(1);
			else
			AS_Set_LED_Indicate(0);

			OsveziLed();
		}
		if(keyPressed==ID_BUTTON_LED1On)
		{
			if(LedDrv==0)
			AS_Set_LED_DRV(1);
			else
			AS_Set_LED_DRV(0);

			OsveziLed();
		}
		if(keyPressed==ID_BUTTON_SetLED0 || keyPressed==ID_BUTTON_SetLED1)
		{
			LEDSet=RADIO_GetValue(WM_GetDialogItem(hWin, ID_RADIO_LED1));
			LEDSet*=0x10;
			LEDSet+=RADIO_GetValue(WM_GetDialogItem(hWin, ID_RADIO_LED0));

			AS_Set_LEDCurrent(LEDSet);
		}
		GUI_Delay(10);

	}
	while(keyPressed!=ID_BUTTON_BackLED);
	while(keyPressed==ID_BUTTON_BackLED)
	{
		STMPE610_read_xyz();
		GUI_TOUCH_Exec();
		keyPressed=GUI_GetKey();
	}
	hWin= CreateWindowMenu();
	GUI_Exec();
}
