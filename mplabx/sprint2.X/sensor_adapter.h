/*
 * File:   sensor_adapter.h
 * Author: Group 2
 *
 * Created on February 24, 2021, 8:08 PM
 */

typedef struct sensor
{
  bool (*open)(void);
  int (*read)(void);
  void (*close)(void);
} sensor;