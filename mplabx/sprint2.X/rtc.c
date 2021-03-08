/*
 * File:   rtc.c
 * Author: SantiniG
 *
 * Created on March 6, 2021, 7:10 PM
 */
#include "mcc_generated_files/mcc.h"
#include "rtc.h"
#include "mcc_generated_files/i2c_master.h"
#include "mcc_generated_files/drivers/i2c_simple_master.h"
#include "mcc_generated_files/tmr2.h"

uint8_t time_sleep = 0;
// static uint8_t time[8];
extern bool is_pic_on;
uint8_t time_to_sleep;
static bool couting = false;

// void rtc_time(void)
// {
//   uint8_t sendData = 0x00;
//   i2c_writeNBytes(0x68, sendData, sizeof(sendData));
//   i2c_readNBytes(0x68, time, sizeof(time));
// }

void rtc_sleep(uint8_t time) //time in seconds
{
  printf("Apagando en %d segundos\r\n", time);
  time_to_sleep = time;
  couting = true;
}
/*
void rtc_wakeup(int hour, int minute)
{
  rtc_time();
  if ((time[1] == minute) && (time[2] == hour))
    printf("Despertando...");
}
*/

/*
void rtc_shutdown(int hour, int minute)
{
  rtc_time();
  if ((time[1] == minute) && (time[2] == hour))
    printf("Apagando...");
}
*/

// This function is called every second if the interrupt is enabled
void rtc_sleep_ISR(void)
{
  if (!couting)
    return;

  // Adding 1 second to the timer
  time_sleep += 1;
  printf("Apagando en %d segundos... \r\n", time_to_sleep - time_sleep);

  if (time_sleep >= time_to_sleep)
  {
    printf("Apagando... \r\n");
    time_sleep = 0;
    time_to_sleep = 0;
    couting = false;
    is_pic_on = false;
  }
}