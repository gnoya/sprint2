/*
 * File:   temp_sensor.c
 * Author: Group 2
 *
 * Created on February 24, 2021, 8:54 PM
 */

#include <stdio.h>
#include <stdbool.h>
#include "sensor_adapter.h"

static bool open();
static float read();
static void close();

static bool open()
{
  bool opened = true;

  if (opened)
  {
    printf("Temp sensor opened!\n");
    return true;
  }
  printf("Temp sensor opening failed!\n");
  return false;
}

static float read()
{
  printf("Reading temp sensor\n");
  return 4.4;
}

static void close()
{
  printf("Temp sensor closed!\n");
}

void initialize_temp(sensor *sensor_var)
{
  sensor_var->open = open;
  sensor_var->read = read;
  sensor_var->close = close;
}