/************************************************************

Libray fuctions to access the popular PCF8563 RTC IC with AVR
Microcontroller.

WWW.EXTMEMORY.BLOGSPOT.COM 2012 - 2013

Uses eXtreme Electronics Soft  I2C Libray. WWW.EXTREMEELECTRONICS.CO.IN

************************************************************/

#include <avr/io.h>

#include "i2csoft.h"
#include "PCF8563.h"

void PCF8563Init(void)
{
	SoftI2CInit();
}

/***************************************************

Function To Read Internal Registers of PCF8563
---------------------------------------------

address : Address of the register
data: value of register is copied to this.


Returns:
0= Failure
1= Success
***************************************************/

BOOL PCF8563Read(uint8_t address,uint8_t *data)
{
	uint8_t res;	//result
	//Start
	SoftI2CStart();
	//SLA+W (for dummy write to set register pointer)
	res=SoftI2CWriteByte(PCF8563_SLA_W);	//DS1307 address + W
	//Error
	if(!res)	return FALSE;
	//Now send the address of required register
	res=SoftI2CWriteByte(address);
	//Error
	if(!res)	return FALSE;
	//Repeat Start
	SoftI2CStart();
	//SLA + R
	res=SoftI2CWriteByte(PCF8563_SLA_R);	//DS1307 Address + R
	//Error
	if(!res)	return FALSE;
	//Now read the value with NACK
	*data=SoftI2CReadByte(0);
	//Error
	if(!res)	return FALSE;
	//STOP
	SoftI2CStop();
	return TRUE;
}
/***************************************************

Function To Write Internal Registers of PCF8563
---------------------------------------------

address : Address of the register
data: value to write.


Returns:
0= Failure
1= Success
***************************************************/

BOOL PCF8563Write(uint8_t address,uint8_t data)
{
	uint8_t res;	//result

	//Start
	SoftI2CStart();

	//SLA+W
	res=SoftI2CWriteByte(PCF8563_SLA_W);	//PCF8563 address + W

	//Error
	if(!res)	return FALSE;

	//Now send the address of required register
	res=SoftI2CWriteByte(address);

	//Error
	if(!res)	return FALSE;

	//Now write the value
	res=SoftI2CWriteByte(data);

	//Error
	if(!res)	return FALSE;

	//STOP
	SoftI2CStop();

	return TRUE;
}

//Остановка часов
void ClockStop(void)
{
	PCF8563Write(0x00,0x20);
}

//Запуск часов
void ClockStart(void)
{
	PCF8563Write(0x00,0x00);
}

//Инициализация RTC
/***************************************************

Function To Init Internal Registers of PCF8563
---------------------------------------------

ctrl2 : Control/Status 2 register values to write
clkout: CLKOUT value to write.
timer_ctrl: Timer control register value

Returns:
0= Failure
1= Success
***************************************************/
BOOL ClockInit(unsigned char ctrl2,unsigned char clkout,unsigned char timer_ctrl)
{
	unsigned char tmp;
	//Initialize PCF8563 Interface
	PCF8563Init();
	if(!PCF8563Write(0x01,ctrl2)) return FALSE;
	if(!PCF8563Write(0x0D,clkout)) return FALSE;
	if(!PCF8563Write(0x0E,timer_ctrl)) return FALSE;
	if(!PCF8563Read(0x07,&tmp)) return FALSE;
	if(!PCF8563Write(0x07,tmp&0x7f)) return FALSE;
	ClockStart();
	return TRUE;

}

//Чтение даты/времени
/***************************************************

Function To Read Internal Registers of PCF8563
---------------------------------------------
datetime : array of values of registers 0x02 - 0x08

Returns:
0= Failure
1= Success
***************************************************/
BOOL GetDateTime(unsigned char *datetime)
{	unsigned char i;
	SoftI2CStart();
	if (!SoftI2CWriteByte(PCF8563_SLA_W)) return FALSE+10;
	if (!SoftI2CWriteByte(0x02)) return FALSE+11;
	SoftI2CStart();
	if (!SoftI2CWriteByte(PCF8563_SLA_R)) return FALSE+12;
	for (i = 0; i < 7; i++)
	{
		datetime[i]=SoftI2CReadByte(1);
	}
	SoftI2CStop();
	if (datetime[0] & 0x80)
	{
		return FALSE+13;
	}
	else
	{
		return TRUE;
	}
}

//Запись даты/времени
/***************************************************

Function To Write Internal Registers of PCF8563
---------------------------------------------
datetime : array of values registers 0x02 - 0x08

Returns:
0= Failure
1= Success
***************************************************/
BOOL SetDateTime(unsigned char *datetime)
{
	unsigned char i;
	ClockStop();
	//Start
	SoftI2CStart();
	//SLA+W
	if (!SoftI2CWriteByte(PCF8563_SLA_W)) return FALSE;	//PCF8563 address + W
	//Now send the address of required register
	if (!SoftI2CWriteByte(0x02)) return FALSE;
	//Now write the value
	for (i=0; i<7; i++)
	{
		if (!SoftI2CWriteByte(datetime[i])) return FALSE;
	}
	//STOP
	SoftI2CStop();
	ClockStart();
	return TRUE;
}

//Чтение будильника
/***************************************************

Function To Read Internal Registers of PCF8563
---------------------------------------------
alarm : array of values of registers 0x09 - 0x0C

Returns:
0= Failure
1= Success
***************************************************/
BOOL GetAlarm(unsigned char *alarm)
{	unsigned char i;
	SoftI2CStart();
	if (!SoftI2CWriteByte(PCF8563_SLA_W)) return FALSE;
	if (!SoftI2CWriteByte(0x09)) return FALSE;
	SoftI2CStart();
	if (!SoftI2CWriteByte(PCF8563_SLA_R)) return FALSE;
	for (i = 0; i < 4; i++)
	{
		alarm[i]=SoftI2CReadByte(1);
	}
	SoftI2CStop();
	return TRUE;
}

//Запись будильника
/***************************************************

Function To Write Internal Registers of PCF8563
---------------------------------------------
alarm : array of values of registers 0x09 - 0x0C

Returns:
0= Failure
1= Success
***************************************************/
BOOL SetAlarm(unsigned char *alarm)
{
	unsigned char i;

	//Start
	SoftI2CStart();
	//SLA+W
	if (!SoftI2CWriteByte(PCF8563_SLA_W)) return FALSE;	//PCF8563 address + W
	//Now send the address of required register
	if (!SoftI2CWriteByte(0x09)) return FALSE;
	//Now write the value
	for (i=0; i<4; i++)
	{
		if (!SoftI2CWriteByte(alarm[i])) return FALSE;
	}
	//STOP
	SoftI2CStop();
	return TRUE;
}

//Выключение будильника
/***************************************************

Function To Turn Off Alarm
---------------------------------------------

Returns:
None
***************************************************/
void AlarmOff(void)
{	unsigned char val;

	PCF8563Read(0x09,&val);
	PCF8563Write(0x09, (val | 0x80));
	PCF8563Read(0x0A,&val);
	PCF8563Write(0x0A, (val | 0x80));
	PCF8563Read(0x0B,&val);
	PCF8563Write(0x0B, (val | 0x80));
	PCF8563Write(0x0C,0x80);
}

//Включение будильника
/***************************************************

Function To Turn On Alarm
---------------------------------------------

Returns:
None
***************************************************/
void AlarmOn(void)
{
	unsigned char d,val;
	PCF8563Read(0x09,&val);
	PCF8563Write(0x09, val & 0x7f);
	PCF8563Read(0x0A,&val);
	PCF8563Write(0x0A,val & 0x3f);
	d=PCF8563Read(0x0B,&val) & 0x3f;
	if (d==0) d=0x80;
	PCF8563Write(0x0B,d);
}

//Запись начального значения таймера
/***************************************************

Function Set Timer CountDown Value
---------------------------------------------
val : Timer CountDown Value, 0x0F Register

Returns:
None
***************************************************/
void SetTimer(unsigned char val)
{
	PCF8563Write(0x0F,val);
}

//Чтение флагов для определения источника возникновения прерывания
/***************************************************

Function To Detect Interrupt Source
---------------------------------------------

Returns:
0= Failure
1= Alarm Interrupt
2= Timer Interrupt
***************************************************/
unsigned char IntVector(void)
{
	unsigned char val;
	PCF8563Read(0x01,&val);
	if (val & 0x08)	return ALARM_VECT;
	if (val & 0x04) return TIMER_VECT;
	return FALSE;
}

//Время в виде строки
/***************************************************

Function To Convert BCD Register Values Into Time String
---------------------------------------------
datetime : pointer to array of values registers 0x02 - 0x08
time : pointer to time string
mode : defines view of result string
FULL_T - 23:50:31
SHORT_T - 23:50 with blinking delimiter(once per second)
Returns:
0= Failure
1= Success
***************************************************/
BOOL TimeStr(unsigned char *datetime, unsigned char *time, unsigned char mode)
{
	   time[0] = 0x30 +((datetime[2] & 0b00110000) >> 4);
	   time[1] = 0x30 + (datetime[2] & 0b00001111);
	   time[3] = 0x30 + ((datetime[1] & 0b01110000) >> 4);
	   time[4] = 0x30 + (datetime[1] & 0b00001111);
		if (mode == SHORT_T)
		{
			if (datetime[0]&0x01)
			{
				time[2] = ':';
			}
		else
			{
				time[2] = ' ';
			}
		}
		if (mode == FULL_T)
		{
			time[2] = ':';
			time[5] = ':';
			time[6] = 0x30 + ((datetime[0] & 0b01110000) >> 4);
			time[7] = 0x30 + (datetime[0] & 0b00001111);
		}
		if (mode != SHORT_T && mode != FULL_T)
		{
			return FALSE;
		}
	return TRUE;
}

//Дата в виде строки
/***************************************************

Function To Convert BCD Register Values Into Date String
---------------------------------------------
datetime : pointer to array of values registers 0x02 - 0x08
date : pointer to date string
mode : defines view of result string
FULL_D - 25.12.2012
SHORT_T - 25.12.12
delimiter : delimiter between values in result string (such as '/','.' etc.)
Returns:
0= Failure
1= Success
***************************************************/
BOOL DateStr(unsigned char *datetime, unsigned char *date, unsigned char mode, unsigned char delimiter)
{
		   date[0] = 0x30 +((datetime[3] & 0b00110000) >> 4);
		   date[1] = 0x30 + (datetime[3] & 0b00001111);
		   date[2] = delimiter;
		   date[3] = 0x30 +((datetime[5] & 0b00010000) >> 4);
		   date[4] = 0x30 + (datetime[5] & 0b00001111);
		   date[5] = delimiter;
		   if (mode == FULL_D)
		   {
			   if(!(datetime[5]&0x80))
			   {
				   date[6] = '2';
				   date[7] = '0';
			   }
			   else
			   {
				   date[6] = '1';
				   date[7] = '9';
			   }
				date[8] = 0x30 +((datetime[6] & 0b11110000) >> 4);
				date[9] = 0x30 + (datetime[6] & 0b00001111);
			}
			else
			{
				date[6] = 0x30 +((datetime[6] & 0b11110000) >> 4);
				date[7] = 0x30 + (datetime[6] & 0b00001111);
			}
			if (mode != FULL_D && mode != SHORT_D)
			{
				return FALSE;
			}
				return TRUE;
}
