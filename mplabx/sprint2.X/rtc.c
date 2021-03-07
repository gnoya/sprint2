/*
 * File:   rtc.c
 * Author: SantiniG
 *
 * Created on March 6, 2021, 7:10 PM
 */
#include "rtc.h"
#include "mcc_generated_files/i2c_master.h"
#include "mcc_generated_files/drivers/i2c_simple_master.h"
#include "mcc_generated_files/tmr2.h"

static uint8_t time_sleep = 0;
static bool  timer_on = 0;
static uint8_t time[8];

void rtc_time(void)
{
  //uint8_t sendData[1] = {0x68,0x00,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF}; 
  //printf("Entro a RTC \r\n");
  uint8_t sendData = 0x00;
  //uint8_t receiveData[7]; // seg/min/hora/day of the week/day/month/year
  i2c_writeNBytes(0x68,sendData,sizeof(sendData));
  i2c_readNBytes(0x68,time,sizeof(time));
  /*printf("Receive Data 0: %x \r\n", receiveData[0]);
  printf("Receive Data 1: %x \r\n", receiveData[1]);
  printf("Receive Data 2: %x \r\n", receiveData[2]);
  printf("Receive Data 3: %x \r\n", receiveData[3]);
  printf("Receive Data 4: %x \r\n", receiveData[4]);
  printf("Receive Data 5: %x \r\n", receiveData[5]);
  printf("Receive Data 6: %x \r\n", receiveData[6]);*/
}


void rtc_sleep(int time) //time in seconds
{
    if(timer_on == 0) 
    {
        //printf("Interrupt Enable");
        TMR2_InterruptEnable();
        timer_on = 1;
    }
    if(time_sleep >= time)
    {
        //printf("Entro al if, apagando... \r\n");
        TMR2_InterruptDisable();
        rtc_wakeup(0x14,0x06);
        time_sleep = 0;
    }
}

void rtc_wakeup(int h,int m)
{
    rtc_time();
    //int min = time[1], hour = time[2];
    //printf("Hora y minutos: %x:%x \n\r",time[2],time[1]);
    //printf("Hora y minutos entrante: %x:%x \n\r",h, m);
    if ((time[1] == m) && (time[2] == h)) printf("WakeeUP!!");
}

void rtc_shutdown(int h, int m)
{
    rtc_time();
    if ((time[1] == m) && (time[2] == h)) printf("Shutdow!!");
}


void rtc_sleep_ISR(void)
{
    time_sleep += 30;
}