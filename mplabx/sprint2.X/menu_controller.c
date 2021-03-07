/*
 * File:   menu.c
 * Author: Group 2
 *
 * Created on February 27, 2021, 8:16 PM
 */

#include <stdio.h>
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"
#include "menu_controller.h"
#include "lcd.h"
#include "eeprom.h"

#define MAIN_MENU 0
#define MAIN_BACK_INDEX 4

#define SENSORS_MENU 1
#define SENSORS_BACK_INDEX 2

// ----------------------- Static (private) variables ----------------------- //
static bool temp_sensor_opened = false;
static bool light_sensor_opened = false;
static int menu_current = 0;
static int menu_index = 0;

// ----------------------- Static (private) functions ----------------------- //
static void index_add(void)
{
  menu_index++;
  if (menu_current == MAIN_MENU && menu_index > 4)
    menu_index = MAIN_BACK_INDEX; // Main Menu
  if (menu_current == SENSORS_MENU && menu_index > SENSORS_BACK_INDEX)
    menu_index = SENSORS_BACK_INDEX; // Select Sensor Menu
  show = 1;
}

// TODO: add comments to this function
static void index_sub(void)
{
  if (menu_current == SENSORS_MENU)
  {
    if (menu_index == SENSORS_BACK_INDEX)
    {
      if (light_sensor_opened)
        menu_index--;
      else if (temp_sensor_opened)
        menu_index -= 2;
    }
    else
    {
      menu_index--;
    }
  }
  else
  {
    menu_index--;
  }

  if (menu_index < 0)
    menu_index = 0;

  show = 1;
}

// TODO: add comments to this function
static void index_enter(void)
{
  // Back button of sensors menu
  if (menu_current == SENSORS_MENU && menu_index == SENSORS_BACK_INDEX)
  {
    menu_current = 0;
    menu_index = 0;
    show = 1;
    return;
  }

  // Temperature sensor enter
  if (menu_current == SENSORS_MENU && menu_index == 0)
  {
    temp_sensor_enabled = !temp_sensor_enabled;
    show = 1;
    eeprom_write(temp_sensor_enabled,light_sensor_enabled);
    return;
  }

  // Light sensor enter
  if (menu_current == SENSORS_MENU && menu_index == 1)
  {
    light_sensor_enabled = !light_sensor_enabled;
    show = 1;
    eeprom_write(temp_sensor_enabled,light_sensor_enabled);
    return;
  }

  if (menu_current != MAIN_MENU || (menu_current == MAIN_MENU && menu_index > 1))
    return;
  menu_current = menu_index + 1;
  menu_index = 0;
  show = 1;
}

/*static void show_index(void)
{
  printf("menu_index: %d \n\r", menu_index);
  printf("menu_current: %d \n\r", menu_current);
}*/

static void show_main_menu(void)
{
  switch (menu_index)
  {
  case 0:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("    Sensores   >");
    break;
  case 1:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("< Temporizador >");
    LCDGoto(0, 1);
    LCDPutStr("    Apagado     ");
    break;
  case 2:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<   Hora de    >");
    LCDGoto(0, 1);
    LCDPutStr("    Encendido   ");
    break;
  case 3:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<   Hora de ");
    LCDGoto(0, 1);
    LCDPutStr("    Apagado   ");
    break;
  default:
    menu_index = 1;
    break;
  }
}

static void show_sensors_menu(void)
{
  printf("menu_index: %d \n\r", menu_index);
  printf("menu_current: %d \n\r", menu_current);

  switch (menu_index)
  {
  case 0:
    // If the temperature sensor is open, show it
    if (temp_sensor_opened)
    {
      LCDClear();
      LCDGoto(0, 0);
      LCDPutStr("<  Temperatura >");
      LCDGoto(0, 1);
      if (temp_sensor_enabled)
      {
        LCDPutStr("   Habilitado   ");
      }
      else
      {
        LCDPutStr("  Deshabilitado    ");
      }
      break;
    }
    else
      menu_index++;

  case 1:
    // If the light sensor is open, show it
    if (light_sensor_opened)
    {
      LCDClear();
      LCDGoto(0, 0);
      LCDPutStr("<  Luminosidad >");
      LCDGoto(0, 1);
      if (light_sensor_enabled)
      {
        LCDPutStr("   Habilitado   ");
      }
      else
      {
        LCDPutStr("  Deshabilitado    ");
      }
      break;
    }
    else
      menu_index++;

  case 2:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<   Regresar   ");
    break;
  default:
    menu_index = 1;
    break;
  }
}

static void show_menu(void)
{
  if (!show)
  {
    return;
  }

  switch (menu_current)
  {
  case MAIN_MENU:
    show_main_menu();
    break;
  case SENSORS_MENU:
    show_sensors_menu();
    break;
  default:
    menu_current = MAIN_MENU;
    break;
  }
  show = 0;
}

// ----------------------- Public functions ----------------------- //
void initialize_menu(menu_controller *menu, bool sensors_opened[])
{
  menu->index_add = index_add;
  menu->index_sub = index_sub;
  menu->index_enter = index_enter;
//  menu->show_index = show_index;
  menu->show_menu = show_menu;
  menu->show_main_menu = show_main_menu;
  menu->show_sensors_menu = show_sensors_menu;
  temp_sensor_opened = sensors_opened[0];
  light_sensor_opened = sensors_opened[1];
}