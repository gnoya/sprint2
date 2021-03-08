/*
 * File:   led_adapter.c
 * Author: Group 2
 *
 * Created on 27 de febrero de 2021, 12:24 PM
 */

#include <stdio.h>
#include <stdbool.h>
#include "led_adapter.h"
#include "mcc_generated_files/mcc.h"

uint16_t duty_cycle = 0;
#define DEFAULT_DUTY_CYCLE 0

// ----------------- Static (private) functions ----------------- //
static long map(int x, long in_min, long in_max, long out_min, long out_max)
{
  return ((long)x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

static void turn_selectors(bool selector1, bool selector2)
{
  if (selector1)
  {
    SELECTOR_1_SetHigh();
  }
  else
  {
    SELECTOR_1_SetLow();
  }

  if (selector2)
  {
    SELECTOR_2_SetHigh();
  }
  else
  {
    SELECTOR_2_SetLow();
  }
}

static void turn_blue()
{
  turn_selectors(1, 0);
}

static void turn_green()
{
  turn_selectors(0, 1);
}

static void turn_red()
{
  turn_selectors(0, 0);
}

static void set_brightness(int brightness)
{
  // This means that the sensor is disconnected or disabled
  if (brightness == 0)
  {
    PWM3_LoadDutyValue(DEFAULT_DUTY_CYCLE);
    return;
  }

  // Map between a duty cycle of 0 to 255
  int mapped_value = (int)map(brightness, 10, 1000, 0, 255);

  // It is (100 - mapped_value) because there is a NOT gate in the Demux
  duty_cycle = (uint16_t)(255 - mapped_value);

  // Set the duty cycle. This function receives a value between 0 and 255
  PWM3_LoadDutyValue(duty_cycle);
}

static void set_color(int temperature)
{
  // This means that the sensor is disconnected or disabled
  if (temperature == 0)
  {
    turn_red();
    return;
  }

  // Map the temperature between 0 and 60 (arbitrary values)
  int color = (int)map(temperature, 19, 358, 0, 60);

  // Turn a different color depending on the mapped value
  if (color >= 0 && color < 20)
  {
    turn_blue();
  }
  else if (color >= 20 && color < 40)
  {
    turn_green();
  }
  else if (color >= 40 && color <= 60)
  {
    turn_red();
  }
}

static void turn_off(void)
{
  PWM3_LoadDutyValue(255);
}

// ----------------------- Public functions ----------------------- //
void initialize_led(led_adapter *led)
{
  led->set_brightness = set_brightness;
  led->set_color = set_color;
  led->turn_off = turn_off;
}
