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

extern bool light_sensor_enabled;

// ----------------------- Declaring static (private) functions ----------------------- //
static bool open();
static int read();
static void close();
static bool is_connected = false;

// ----------------------- Static (private) functions ----------------------- //
static bool open()
{
  // Reading the sensor to check if the value is 0
  int opening_value = (int)ADC_GetConversion(SENSOR_LIGHT);

  // If the value is greater than 0, the sensor is connected
  is_connected = opening_value > 0;
  return is_connected;
}

static int read()
{
  if (is_connected && light_sensor_enabled)
  {
    // 10 to 1000
    int measure = (int)ADC_GetConversion(SENSOR_LIGHT);
    printf("Measure of the light sensor: %d \r\n", measure);
    return measure;
  }
  return 0;
}

// ----------------------- Public functions ----------------------- //
void initialize_light(sensor *sensor_var)
{
  sensor_var->name = "Light";
  sensor_var->open = open;
  sensor_var->read = read;
}