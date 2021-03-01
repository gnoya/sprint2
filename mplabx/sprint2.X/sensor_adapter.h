/*
 * File:   sensor_adapter.h
 * Author: Group 2
 *
 * Created on February 24, 2021, 8:08 PM
 */

typedef struct sensor
{
  char *name;
  bool (*open)(void);
  int (*read)(void);
} sensor;