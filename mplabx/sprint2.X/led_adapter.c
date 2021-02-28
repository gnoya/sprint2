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

static void turn_blue();
static void turn_green();
static void turn_red();

static void set_brightness(int brightness);
static void set_color(int temperature);
static void turn_selectors(bool selector1, bool selector2);
static int map(int x, int in_min, int in_max, int out_min, int out_max);

uint16_t duty_cycle = 0;

static int map(int x, int in_min, int in_max, int out_min, int out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
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
  printf("Color is blue!\n");
  turn_selectors(1, 0);
}

static void turn_green()
{
  printf("Color is green!\n");
  turn_selectors(0, 1);
}

static void turn_red()
{
  printf("Color is red!\n");
  turn_selectors(0, 0);
}

static void set_brightness(int brightness)
{
  duty_cycle = (uint16_t)(100 - map(brightness, 0, 100, 0, 100));
  printf("Duty cycle is: %d\n", duty_cycle);

  // from 0 to 100
  PWM3_LoadDutyValue(duty_cycle);
}

static void set_color(int temperature)
{
  int color = map(temperature, 0, 100, 0, 60);

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

void initialize_led(led *led)
{
  led->set_brightness = set_brightness;
  led->set_color = set_color;
}