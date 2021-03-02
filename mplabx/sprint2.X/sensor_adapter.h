/*
 * File:   sensor_adapter.h
 * Author: Group 2
 *
 * Created on February 24, 2021, 8:08 PM
 */

/**
  @Summary
    This struct is used as a hardware adapter of multiple sensors

  @Description
    The idea of this struct is to have multiple sensors and open / read them using the same function names
*/
typedef struct sensor
{
  char *name;
  bool (*open)(void);
  int (*read)(void);
} sensor;