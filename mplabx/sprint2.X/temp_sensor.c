/*
 * File:   temp_sensor.c
 * Author: Group 2
 *
 * Created on February 24, 2021, 8:54 PM
 */

#include <stdio.h>
#include <stdbool.h>
#include "sensor_adapter.h"
#include "mcc_generated_files/mcc.h"

static bool open();
static int read();

static bool open()
{
  // Reading the sensor to check if the value is 0
  int opening_value = (int)ADC_GetConversion(SENSOR_TEMP);

  // If the value is greater than 0, the sensor is connected
  bool is_connected = opening_value > 0;
  return is_connected;
}

static int read()
{
  // 19 to 358
  return (int)ADC_GetConversion(SENSOR_TEMP);
}

void initialize_temp(sensor *sensor_var)
{
  sensor_var->name = "Temperature";
  sensor_var->open = open;
  sensor_var->read = read;
}