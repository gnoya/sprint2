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
 * File: light_adapter.h
 * Author: Group 2
 * Comments:
 * Revision history: 
 */

/**
  @Summary
    This struct is used to control the LEDs of the system

  @Description
    This struct is used to control the LEDs of the system
*/
typedef struct led_adapter
{
  void (*set_brightness)(int brightness);
  void (*set_color)(int temperature);
  void (*turn_off)(void);
} led_adapter;

/**
  @Summary
    This functions changes the color of the leds to blue

  @Description
    This functions changes the color of the leds to blue by changing the demux selectors

  @Preconditions
    None

  @Param
    int brightness: brightness value from 10 to 1000

  @Returns
    None
*/
static void turn_blue();

/**
  @Summary
    This functions changes the color of the leds to green

  @Description
    This functions changes the color of the leds to green by changing the demux selectors

  @Preconditions
    None

  @Param
    int brightness: brightness value from 10 to 1000

  @Returns
    None
*/
static void turn_green();

/**
  @Summary
    This functions changes the color of the leds to red

  @Description
    This functions changes the color of the leds to red by changing the demux selectors

  @Preconditions
    None

  @Param
    int brightness: brightness value from 10 to 1000

  @Returns
    None
*/
static void turn_red();

/**
  @Summary
    This functions changes the brightness of the leds

  @Description
    This functions changes the brightness of the leds by changing the PWM's duty cycle

  @Preconditions
    None

  @Param
    int brightness: brightness value from 10 to 1000

  @Returns
    None
*/
static void set_brightness(int brightness);

/**
  @Summary
    This functions changes the color of the leds

  @Description
    This functions changes the color of the leds by changing the demux selectors

  @Preconditions
    None

  @Param
    int temperature: temperature value from 19 to 358

  @Returns
    None
*/
static void set_color(int temperature);

/**
  @Summary
    This functions changes the value of the Demux selectors

  @Description
    This functions changes the value of two IO pins that are used as Demux selectors
    to change the PWM output to different RGB channels

  @Preconditions
    None

  @Param
    bool selector1, bool selector2

  @Returns
    None
*/
static void turn_selectors(bool selector1, bool selector2);

// TODO: comentar
static void turn_off(void);

/**
  @Summary
    This functions maps a value from a range to another

  @Description
    This function maps a value "x" that has a range of "in_min" to "in_max", to
    a new range from "out_min" to "out_max"

  @Preconditions
    None

  @Param
    int x, long in_min, long in_max, long out_min, long out_max

  @Returns
    long var
*/
static long map(int x, long in_min, long in_max, long out_min, long out_max);

/**
  @Summary
    Initializes the led adapter

  @Description
    This function assigns the static functions to the led adapter

  @Preconditions
    None

  @Param
    led_adapter *led

  @Returns
    None
*/
void initialize_led(led_adapter *led);