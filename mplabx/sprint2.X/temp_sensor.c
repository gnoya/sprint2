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

extern bool temp_sensor_enabled;

// ----------------------- Declaring static (private) functions ----------------------- //
static bool open();
static int read();
static bool is_connected = false;

static bool open()
{
  // Reading the sensor to check if the value is 0
  int opening_value = (int)ADC_GetConversion(SENSOR_TEMP);

  // If the value is greater than 0, the sensor is connected
  is_connected = opening_value > 0;
  return is_connected;
}

static int read()
{
  if (is_connected && temp_sensor_enabled)
  {
    // 19 to 358
    int measure = (int)ADC_GetConversion(SENSOR_TEMP);
    printf("Measure of the temperature sensor: %d \r\n", measure);
    return measure;
  }
  return 0;
}

void initialize_temp(sensor *sensor_var)
{
  sensor_var->name = "Temperature";
  sensor_var->open = open;
  sensor_var->read = read;
}