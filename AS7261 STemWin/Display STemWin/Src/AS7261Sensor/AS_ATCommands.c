/*
 * AS_ATCommands.c
 *
 *  Created on: 1 Dec 2018
 *      Author: Bozic
 */

//This function testing communication

#include "AS7261Sensor/AS_ATCommands.h"
#include "AS7261Sensor/ASMaster.h"
#include <stdlib.h>
#include "AS7261Sensor/StringFunction.h"

UART_HandleTypeDef huart6;

uint8_t AS_Test()//RADI
{
	uint8_t MSGG[6]={'\0','\0','\0','\0','\0','\0'};
	int t=0;
	while(t<3)
	{   MSGG[0]='\0'; MSGG[1]='\0'; MSGG[2]='\0'; MSGG[3]='\0'; MSGG[4]='\0'; MSGG[5]='\0';
		HAL_Delay(10);
		t++;
		HAL_UART_Transmit(&huart6,(uint8_t*)"AT\r\n",4,100);
		HAL_UART_Receive(&huart6,MSGG,5,100);

		if(strstr((char*)MSGG,"OK"))
			return 1;
	}
	return 0;
}

uint8_t AS_Read_XYZ(int *X,int *X1,int *Y,int *Y1,int *Z,int *Z1)
{
	int Data[6];
	char RecPoruka[30];
	int f=0;

	for(f=0;f<30;f++)		// INIC MSG
	{
		RecPoruka[f]='\0';
	}

	if(AS_Test())
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON

		HAL_UART_Transmit(&huart6,(uint8_t*)"ATXYZC\r",7,100); // Read DATA
		HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,30,100);


		DelateOKinMSG(RecPoruka);
		ChangeCom(RecPoruka);


		sscanf(RecPoruka,"%d %d %d %d %d %d",&(Data[0]),&(Data[1]),&(Data[2]),&(Data[3]),&(Data[4]),&(Data[5]));

		*X=Data[0];
		*X1=Data[1];
		*Y=Data[2];
		*Y1=Data[3];
		*Z=Data[4];
		*Z1=Data[5];

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

		return 1;
	}

		return 0;
}

uint8_t AS_Read_LUX(int *LUX,int *LUX1)
{

		char RecPoruka[15];
		int f=0;
		int l=0,l1=0;

		for(f=0;f<15;f++)		// INIC MSG
		{
			RecPoruka[f]='\0';
		}

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON

			HAL_UART_Transmit(&huart6,(uint8_t*)"ATLUXC\r",7,30); // Read DATA
			HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,14,30);


			ClearSpace(RecPoruka);

			DelateOKinMSG(RecPoruka);

			ChangeCom(RecPoruka);


			sscanf(RecPoruka,"%d %d",&l,&l1);

			*LUX=l;
			*LUX1=l1;

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

			return 1;

}

uint8_t AS_Read_CCT(int *CCT,int *CCT1)
{
	char RecPoruka[15];
	int f=0;
	int cct=0,cct1=0;

	for(f=0;f<15;f++)		// INIC MSG
	{
		RecPoruka[f]='\0';
	}
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON

		HAL_UART_Transmit(&huart6,(uint8_t*)"ATCCTC\r",7,30); // Read DATA
		HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,14,30);


		ClearSpace(RecPoruka);

		DelateOKinMSG(RecPoruka);

		ChangeCom(RecPoruka);


		sscanf(RecPoruka,"%d %d",&cct,&cct1);

		*CCT=cct;
		*CCT1=cct1;

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

		return 1;

}

uint8_t AS_Read_SMAllxy(int *x,int *x1, int *y, int *y1)
{
	char RecPoruka[30];
	int f=0;

	for(f=0;f<30;f++)		// INIC MSG
	{
		RecPoruka[f]='\0';
	}

	if(AS_Test())
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON

		HAL_UART_Transmit(&huart6,(uint8_t*)"ATSMALLXYC\r",11,100); // Read DATA
		HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,30,100);


		ClearSpace(RecPoruka);

		DelateOKinMSG(RecPoruka);

		ChangeCom(RecPoruka);


		sscanf(RecPoruka,"%d %d %d %d",x,x1,y,y1);


		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

		return 1;
	}

		return 0;
}

uint8_t AS_Read_Up_Vp_U_V(float *Up,float *Vp,float *U,float *V)
{
	if(AS_Test())
	{

		return 1;
	}
	else
		return 0;

}

uint8_t AS_READ_DUV(float *DUV)
{
	if(AS_Test())
	{

		return 1;
	}
	else
		return 0;

}

uint8_t AS_Read_AllData_RAW(int *X,int *Y,int *Z,int *NIR,int *D,int *C)
{
	int Data[6];
	char RecPoruka[71];
	int f=0;

	for(f=0;f<71;f++)		// INIC MSG
	{
		RecPoruka[f]='\0';
	}

	if(AS_Test())
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON

		HAL_UART_Transmit(&huart6,(uint8_t*)"ATDATA\r",7,100); // Read DATA
		HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,70,100);

		ClearSpace(RecPoruka);

		DelateOKinMSG(RecPoruka);

		ChangeCom(RecPoruka);


		sscanf(RecPoruka,"%d %d %d %d %d %d",&(Data[0]),&(Data[1]),&(Data[2]),&(Data[3]),&(Data[4]),&(Data[5]));

		*X=Data[0];
		*Y=Data[1];
		*Z=Data[2];
		*NIR=Data[3];
		*D=Data[4];
		*C=Data[5];

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

		return 1;
	}

		return 0;
}

uint8_t AS_Set_IntegrationTime(uint8_t Time)//RADI
{
	char RecPoruka[15];
		int f=0;

		for(f=0;f<15;f++)		// INIC MSG
		{
			RecPoruka[f]='\0';
		}

		if(AS_Test())
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
			HAL_Delay(50);

			if(Time>=255) Time=255;
			if(Time<=1) Time=1;

			sprintf(RecPoruka,"ATINTTIME=%3d\r",(int)Time);

			HAL_UART_Transmit(&huart6,(uint8_t*)RecPoruka,14,200); // Send DATA
			HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200); // Clear RXbuffer

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

			return 1;
		}
		else
			return 0;
}

uint8_t AS_Read_IntegrationTime(uint8_t *Time)//RADI
{
	char RecPoruka[15];
	int f=0;

	for(f=0;f<15;f++)		// INIC MSG
	{
		RecPoruka[f]='\0';
	}

	if(AS_Test())
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
		HAL_Delay(50);

		HAL_UART_Transmit(&huart6,(uint8_t*)"ATINTTIME\r",10,200); // Read DATA
		HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200);

		DelateOKinMSG(RecPoruka);  // Clear OK and /r

		(*Time)=(uint8_t)atoi(RecPoruka);

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

		return 1;
	}
		(*Time)=9;// Error
		return 0;
}

uint8_t AS_Set_Gain(uint8_t Gain)//RADI
{
	char RecPoruka[15];
	int f=0;

	for(f=0;f<15;f++)		// INIC MSG
	{
		RecPoruka[f]='\0';
	}

	if(AS_Test())
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
		HAL_Delay(50);

		sprintf(RecPoruka,"ATGAIN=%1d\r",(int)Gain);

		HAL_UART_Transmit(&huart6,(uint8_t*)RecPoruka,9,200); // Send DATA
		HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200); // Clear RXbuffer

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

		return 1;
	}
	else
		return 0;
}

uint8_t AS_Read_Gain(uint8_t *Gain)//RADI
{
		char RecPoruka[15];
		int f=0;

		for(f=0;f<15;f++)		// INIC MSG
		{
			RecPoruka[f]='\0';
		}

		if(AS_Test())
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
			HAL_Delay(50);

			HAL_UART_Transmit(&huart6,(uint8_t*)"ATGAIN\r",7,200); // Read DATA
			HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200);

			DelateOKinMSG(RecPoruka);  // Clear OK and /r

			(*Gain)=(uint8_t)atoi(RecPoruka);

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

			return 1;
		}
			(*Gain)=9;// Error
			return 0;
}

uint8_t AS_Read_Temp(float *Temp)//RADI
{
	char RecPoruka[15];
	int f=0;

	for(f=0;f<15;f++)		// INIC MSG
	{
		RecPoruka[f]='\0';
	}

	if(AS_Test())		// if Sensor connected
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
		HAL_Delay(50);

		HAL_UART_Transmit(&huart6,(uint8_t*)"ATTEMP\r",8,200); // GET DATA
		HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200);

		DelateOKinMSG(RecPoruka);  // Clear OK and /r

		(*Temp)=atof(RecPoruka);  //Convert to float

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

		return 1;
	}

		(*Temp)=0;
		return 0;
}

uint8_t AS_Set_SensorMode(uint8_t Mode)
{
	char RecPoruka[15];
	int f=0;

	for(f=0;f<15;f++)		// INIC MSG
	{
		RecPoruka[f]='\0';
	}

	if(AS_Test())
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
		HAL_Delay(50);

		sprintf(RecPoruka,"ATTCSMD=%1d\r",(int)Mode);

		HAL_UART_Transmit(&huart6,(uint8_t*)RecPoruka,10,200); // Send DATA
		HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200); // Clear RXbuffer

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

		return 1;
	}
	else
		return 0;
}

uint8_t AS_Read_SensorMode(uint8_t *Mode)
{
	char RecPoruka[15];
	int f=0;

	for(f=0;f<15;f++)		// INIC MSG
	{
		RecPoruka[f]='\0';
	}

	if(AS_Test())
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
		HAL_Delay(50);

		HAL_UART_Transmit(&huart6,(uint8_t*)"ATTCSMD\r",8,200); // Read DATA
		HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200);

		DelateOKinMSG(RecPoruka);  // Clear OK and /r

		(*Mode)=(uint8_t)atoi(RecPoruka);

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

		return 1;
	}
		(*Mode)=9;// Error
		return 0;
}

uint8_t AS_Set_SemplingInterval(uint8_t SemplingInterval)
{
	char RecPoruka[15];
	int f=0;

	for(f=0;f<15;f++)		// INIC MSG
	{
		RecPoruka[f]='\0';
	}

	if(AS_Test())
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
		HAL_Delay(50);

		if(SemplingInterval>=255) SemplingInterval=255;
		if(SemplingInterval<=1) SemplingInterval=1;

		sprintf(RecPoruka,"ATINTRVL=%3d\r\n",(int)SemplingInterval);

		HAL_UART_Transmit(&huart6,(uint8_t*)RecPoruka,14,200); // Send DATA
		HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200); // Clear RXbuffer

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

		return 1;
	}
	else
		return 0;
}

uint8_t AS_Read_SemplingInterval(uint8_t *SemplingInterval)
{
	char RecPoruka[15];
		int f=0;

		for(f=0;f<15;f++)		// INIC MSG
		{
			RecPoruka[f]='\0';
		}

		if(AS_Test())
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
			HAL_Delay(50);

			HAL_UART_Transmit(&huart6,(uint8_t*)"ATINTRVL\r",9,200); // Read DATA
			HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200);

			DelateOKinMSG(RecPoruka);  // Clear OK and /r

			(*SemplingInterval)=(uint8_t)atoi(RecPoruka);

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

			return 1;
		}
			(*SemplingInterval)=9;// Error
			return 0;
}

uint8_t AS_Set_LED_Indicate(uint8_t ONOFF)
{
		char RecPoruka[15];
		int f=0;

		for(f=0;f<15;f++)		// INIC MSG
		{
			RecPoruka[f]='\0';
		}

		if(AS_Test())
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
			HAL_Delay(50);

			if(ONOFF==0)
			{
			sprintf(RecPoruka,"ATLED0=0\r");

			HAL_UART_Transmit(&huart6,(uint8_t*)RecPoruka,9,200); // Send DATA
			HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200); // Clear RXbuffer
			}
			else
			{
			sprintf(RecPoruka,"ATLED0=100\r");

			HAL_UART_Transmit(&huart6,(uint8_t*)RecPoruka,11,200); // Send DATA
			HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200); // Clear RXbuffer
			}


			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

			return 1;
		}
		else
			return 0;
}

uint8_t AS_Read_LED_Indicate(uint8_t *ONOFF)
{
	char RecPoruka[15];
		int f=0;

		for(f=0;f<15;f++)		// INIC MSG
		{
			RecPoruka[f]='\0';
		}

		if(AS_Test())
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
			HAL_Delay(50);

			HAL_UART_Transmit(&huart6,(uint8_t*)"ATLED0\r",7,200); // Read DATA
			HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200);

			DelateOKinMSG(RecPoruka);  // Clear OK and /r

			(*ONOFF)=(uint8_t)atoi(RecPoruka);

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

			return 1;
		}
			(*ONOFF)=9;// Error
			return 0;
}

uint8_t AS_Set_LED_DRV(uint8_t ONOFF)
{
	char RecPoruka[15];
			int f=0;

			for(f=0;f<15;f++)		// INIC MSG
			{
				RecPoruka[f]='\0';
			}

			if(AS_Test())
			{
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
				HAL_Delay(50);

				if(ONOFF==0)
				{
				sprintf(RecPoruka,"ATLED1=0\r");

				HAL_UART_Transmit(&huart6,(uint8_t*)RecPoruka,9,200); // Send DATA
				HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200); // Clear RXbuffer
				}
				else
				{
				sprintf(RecPoruka,"ATLED1=100\r");

				HAL_UART_Transmit(&huart6,(uint8_t*)RecPoruka,11,200); // Send DATA
				HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200); // Clear RXbuffer
				}


				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

				return 1;
			}
			else
				return 0;
}

uint8_t AS_Read_LED_DRV(uint8_t *ONOFF)
{
	char RecPoruka[15];
	int f=0;

	for(f=0;f<15;f++)		// INIC MSG
	{
		RecPoruka[f]='\0';
	}

	if(AS_Test())
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
		HAL_Delay(50);

		HAL_UART_Transmit(&huart6,(uint8_t*)"ATLED1\r",7,200); // Read DATA
		HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200);

		DelateOKinMSG(RecPoruka);  // Clear OK and /r

		(*ONOFF)=(uint8_t)atoi(RecPoruka);

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

		return 1;
	}
		(*ONOFF)=9;// Error
		return 0;
}

uint8_t AS_Set_LEDCurrent(uint8_t Current)
{
	char RecPoruka[15];
	int f=0;

	for(f=0;f<15;f++)		// INIC MSG
	{
		RecPoruka[f]='\0';
	}

	if(AS_Test())
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
		HAL_Delay(50);

		sprintf(RecPoruka,"ATLEDC=%d\r",Current);

		HAL_UART_Transmit(&huart6,(uint8_t*)RecPoruka,10,200); // Send DATA
		HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200); // Clear RXbuffer

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

		return 1;
	}
	else
		return 0;
}

uint8_t AS_Read_LEDCurrent(uint8_t *CurrentLed0, uint8_t *CurrentLed1)
{
		char RecPoruka[15];
		int f=0;

		for(f=0;f<15;f++)		// INIC MSG
		{
			RecPoruka[f]='\0';
		}

		if(AS_Test())
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON
			HAL_Delay(50);

			sprintf(RecPoruka,"ATLEDC\r");

			HAL_UART_Transmit(&huart6,(uint8_t*)RecPoruka,10,200); // Send DATA
			HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,10,200); // Clear RXbuffer

			*CurrentLed0=RecPoruka[0]-48;
			*CurrentLed1=RecPoruka[1]-48;

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

			return 1;
		}
		else
			return 0;
}

uint8_t AS_Reset()
{

		char RecPoruka[50];
		int f=0;

		for(f=0;f<50;f++)		// INIC MSG
		{
			RecPoruka[f]='\0';
		}

		if(AS_Test())
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); //LED ON

			HAL_Delay(500);

			HAL_UART_Transmit(&huart6,(uint8_t*)"ATSRST\r",7,100); // Read DATA
			HAL_UART_Receive(&huart6,(uint8_t*)RecPoruka,50,1000);

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);  // LED OFF

			if(strstr((char*)RecPoruka,"OK"))
			return 1;


		}
		return 0;
}

uint8_t AS_VersionSS(uint8_t *Ver)
{
	if(AS_Test())
	{

		return 1;
	}
	else
		return 0;
}

uint8_t AS_VersionSH(uint8_t *Ver)
{
	if(AS_Test())
	{

		return 1;
	}
	else
		return 0;
}




