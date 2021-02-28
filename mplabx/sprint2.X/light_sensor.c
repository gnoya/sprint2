/*
 * File:   light_sensor.c
 * Author: Group 2
 *
 * Created on February 24, 2021, 8:28 PM
 */

#include <stdio.h>
#include <stdbool.h>
#include "sensor_adapter.h"
#include "mcc_generated_files/mcc.h"

static bool open();
static int read();
static void close();

static bool open()
{
  return true;
}

static int read()
{
  printf("Reading light sensor\r\n");
  return ((int)ADC_GetConversion(channel_AN1));;
}

static void close()
{
  printf("Light sensor closed!\n");
}

void initialize_light(sensor *sensor_var)
{
  sensor_var->open = open;
  sensor_var->read = read;
  sensor_var->close = close;
}