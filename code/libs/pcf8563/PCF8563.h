/************************************************************

Libray fuctions to access the popular DS1307 RTC IC with AVR
Microcontroller.

The libray has just two functions. One reads the register whose
address is provided. Other writes to the given register with
given data.Please see DS1307 Datasheet for more info on
the registers.

Requires eXtreme Electronics Low Level Soft I2C Libray.

PLEASE SEE WWW.EXTREMEELECTRONICS.CO.IN FOR DETAILED 
SCHEMATICS,USER GUIDE AND VIDOES.

COPYRIGHT (C) 2008-2012 EXTREME ELECTRONICS INDIA

************************************************************/

#ifndef _PCF8563_H_
#define _PCF8563_H_

#define BOOL uint8_t

#define PCF8563_SLA_W 0XA2
#define PCF8563_SLA_R 0XA3

#define TRUE 	1
#define FALSE 	0

/* Значения регистра Control/Status2
   для инициализации RTC */
#define RTC_TIE_ON 1 //Вкл. таймер
#define RTC_AIE_ON 2 //Вкл. будильника
#define RTC_TP_ON 0x10 //Вкл сигнала прерывания по таймеру/будильнику

/* Значения для инициализации CLKOUT
   для инициализации RTC */
#define RTC_CLKOUT_OFF 0
#define RTC_CLKOUT_1 0x83
#define RTC_CLKOUT_32 0x82
#define RTC_CLKOUT_1024 0x81
#define RTC_CLKOUT_32768 0x80

/* Значения частоты источника импульсов для таймера */
#define RTC_TIMER_OFF 0
#define RTC_TIMER_CLK_1_60 0x83
#define RTC_TIMER_CLK_1 0x82
#define RTC_TIMER_CLK_64 0x81
#define RTC_TIMER_CLK_4096 0x80
/*Значения флагов для определения источника прерывания*/
#define ALARM_VECT 1
#define TIMER_VECT 2

/* Режим формирования строки Даты/Времени*/
#define SHORT_T 6
#define FULL_T  9
#define SHORT_D 9
#define FULL_D  11
//Public Functions

void PCF8563Init(void);
BOOL PCF8563Write(uint8_t address,uint8_t data);
/***************************************************

Function To Read Internal Registers of PCF8563
---------------------------------------------

address : Address of the register
data: value of register is copied to this.


Returns:
0= Failure
1= Success
***************************************************/
BOOL PCF8563Read(uint8_t address,uint8_t *data);
/***************************************************

Function To Write Internal Registers of PCF8563
---------------------------------------------

address : Address of the register
data: value to write.


Returns:
0= Failure
1= Success
***************************************************/
BOOL PCF8563ReadDateTime(uint8_t *data);
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
BOOL ClockInit(unsigned char ctrl2,unsigned char clkout,unsigned char timer_ctrl);
/***************************************************

Function To Read Internal Registers of PCF8563
---------------------------------------------
datetime : array of values of registers 0x02 - 0x08

Returns:
0= Failure
1= Success
***************************************************/
BOOL GetDateTime(unsigned char *datetime);
/***************************************************

Function To Write Internal Registers of PCF8563
---------------------------------------------
datetime : array of values registers 0x02 - 0x08

Returns:
0= Failure
1= Success
***************************************************/
BOOL SetDateTime(unsigned char *datetime);
/***************************************************

Function To Read Internal Registers of PCF8563
---------------------------------------------
alarm : array of values of registers 0x09 - 0x0C

Returns:
0= Failure
1= Success
***************************************************/
BOOL GetAlarm(unsigned char *alarm);
/***************************************************

Function To Write Internal Registers of PCF8563
---------------------------------------------
alarm : array of values of registers 0x09 - 0x0C
Alarm is turned on after this function
Returns:
0= Failure
1= Success
***************************************************/
BOOL SetAlarm(unsigned char *alarm);
/***************************************************

Function To Turn On Alarm
---------------------------------------------

Returns:
None
***************************************************/
void AlarmOn(void);
/***************************************************

Function To Turn Off Alarm
---------------------------------------------

Returns:
None
***************************************************/
void AlarmOff(void);
/***************************************************

Function Set Timer CountDown Value
---------------------------------------------
val : Timer CountDown Value, 0x0F Register

Returns:
None
***************************************************/
void SetTimer(unsigned char val);
/***************************************************

Function To Detect Interrupt Source
---------------------------------------------

Returns:
0= Failure
1= Alarm Interrupt
2= Timer Interrupt
***************************************************/
unsigned char IntVector(void);
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
BOOL TimeStr(unsigned char *datetime, unsigned char *time, unsigned char mode);
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
BOOL DateStr(unsigned char *datetime, unsigned char *date, unsigned char mode, unsigned char delimiter);
#endif
