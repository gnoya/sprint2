/*
 * File:   led_adapter.c
 * Author: Group 2
 *
 * Created on 27 de febrero de 2021, 12:24 PM
 */

#include <stdio.h>
#include <stdbool.h>
#include "led_adapter.h"

static void turn_blue();
static void turn_green();
static void turn_red();
static void set_brightness(float brightness);
static void set_color(float temperature);

static void turn_blue()
{
  printf("Demo 1!\n");
}

static void turn_green()
{
  printf("Demo 2!\n");
}

static void turn_red()
{
  printf("Demo 3!\n");
}

void set_brightness(float brightness)
{
  printf("Demo 3!\n");
}

void set_color(float temperature)
{
  printf("Demo 3!\n");
}

void initialize_led(led *led)
{
  led->turn_blue = turn_blue;
  led->turn_green = turn_green;
  led->turn_red = turn_red;
  led->set_brightness = set_brightness;
  led->set_color = set_color;
}