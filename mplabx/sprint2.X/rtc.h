/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File: rtc.h
 * Author: Group 2
 * Comments:
 * Revision history: 
 */

/**
  @Summary
    Read the values of the RTC

  @Description
    Read the values of the RTC

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
// void rtc_time(void);

/**
  @Summary
    Puts the PIC on "sleep" mode in "time" seconds

  @Description
    Puts the PIC on "sleep" mode in "time" seconds

  @Preconditions
    None

  @Param
    int time: time in seconds to put on sleep mode

  @Returns
    None
*/
void rtc_sleep(uint8_t time);

/**
  @Summary
    Wakes up the PIC at hour "h" and minute "m"

  @Description
    Wakes up the PIC at hour "h" and minute "m"

  @Preconditions
    None

  @Param
    int hour, int minute: hour and minute to wake up

  @Returns
    None
*/
// void rtc_wakeup(int hour, int minute);

/**
  @Summary
    Shuts down the PIC at hour "h" and minute "m"

  @Description
    Shuts down the PIC at hour "h" and minute "m"

  @Preconditions
    None

  @Param
    int hour, int minute: hour and minute to shut down

  @Returns
    None
*/
// void rtc_shutdown(int hour, int minute);

/**
  @Summary
    Callback function to add +1 to the second timer

  @Description
    Callback function to add +1 to the second timer

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void rtc_sleep_ISR(void);

/**
 End of File
*/