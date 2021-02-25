/*
 * File:   light_sensor.c
 * Author: Group 2
 *
 * Created on February 24, 2021, 8:28 PM
 */

#include <stdio.h>
#include <stdbool.h>
#include "sensor_adapter.h"

static bool open();
static float read();
static void close();

static bool open()
{
  printf("Light sensor opened!\n");
  return true;
}

static float read()
{
  printf("Reading light sensor\n");
  return 2.2;
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