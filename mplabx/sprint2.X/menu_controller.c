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

static bool temp_sensor_opened = false;
static bool light_sensor_opened = false;

bool temp_sensor_enabled = true;
bool light_sensor_enabled = true;

// TODO: delete modes menu

// ----------------------- Static (private) functions ----------------------- //
static void index_add(void)
{
  menu_index++;
  if (menu_current == 0 && menu_index > 4)
    menu_index = 4; // Main Menu
  if (menu_current == 1 && menu_index > 4)
    menu_index = 4; // Operating Mode Menu
  if (menu_current == 2 && menu_index > 3)
    menu_index = 3; // Select Sensor Menu
  show = 1;
}

// TODO: add comments to this function
static void index_sub(void)
{
  menu_index--;
  if (menu_index < 0)
    menu_index = 0;
  show = 1;
}

// TODO: add comments to this function
static void index_enter(void)
{
  if (menu_current == 1 && menu_index == 4)
  {
    menu_current = 0;
    menu_index = 0;
    show = 1;
    return;
  }
  if (menu_current == 2 && menu_index == 2)
  {
    menu_current = 0;
    menu_index = 0;
    show = 1;
    return;
  }

  // Temperature sensor
  if (menu_current == 2 && menu_index == 0)
  {
    temp_sensor_enabled = !temp_sensor_enabled;
    show = 1;
    return;
  }

  // Light sensor
  if (menu_current == 2 && menu_index == 1)
  {
    light_sensor_enabled = !light_sensor_enabled;
    show = 1;
    return;
  }

  if (menu_current != 0 || (menu_current == 0 && menu_index > 1))
    return;
  menu_current = menu_index + 1;
  menu_index = 0;
  show = 1;
}

static void show_index(void)
{
  printf("menu_index: %d \n\r", menu_index);
  printf("menu_current: %d \n\r", menu_current);
}

static void show_main_menu(void)
{
  switch (menu_index)
  {
  case 0:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("  Modo de uso  >");
    break;
  case 1:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<   Sensores   >");
    break;
  case 2:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("< Temporizador >");
    LCDGoto(0, 1);
    LCDPutStr("     Apagado    ");
    break;
  case 3:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<   Hora de    >");
    LCDGoto(0, 1);
    LCDPutStr("    Encendido   ");
    break;
  case 4:
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

static void show_mode_menu(void)
{
  switch (menu_index)
  {
  case 0:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("Automatico por >");
    LCDGoto(0, 1);
    LCDPutStr("    Sensores   ");
    break;
  case 1:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<  Intensidad  >");
    LCDGoto(0, 1);
    LCDPutStr("     Baja     ");
    break;
  case 2:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<  Intensidad  >");
    LCDGoto(0, 1);
    LCDPutStr("     Media     ");
    break;
  case 3:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<  Intensidad  >");
    LCDGoto(0, 1);
    LCDPutStr("     Alta     ");
    break;
  case 4:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<   Regresar   ");
    break;
  default:
    menu_index = 1;
    break;
  }
}

static void show_sensors_menu(void)
{
  switch (menu_index)
  {
  case 0:
    if (temp_sensor_opened)
    {
      LCDClear();
      LCDGoto(0, 0);
      LCDPutStr("< Temperatura >");
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
    menu_index++;
  case 1:
    if (light_sensor_opened)
    {
      LCDClear();
      LCDGoto(0, 0);
      LCDPutStr("<  Luminocidad   >");
      LCDGoto(0, 1);
      if (light_sensor_enabled)
      {
        LCDPutStr("  Habilitado    ");
      }
      else
      {
        LCDPutStr("  Deshabilitado    ");
      }
      break;
    }
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
  case 0:
    show_main_menu();
    break;
  case 1:
    show_mode_menu();
    break;
  case 2:
    show_sensors_menu();
    break;
  default:
    menu_current = 0;
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
  menu->show_index = show_index;
  menu->show_menu = show_menu;
  menu->show_main_menu = show_main_menu;
  menu->show_mode_menu = show_mode_menu;
  menu->show_sensors_menu = show_sensors_menu;
  light_sensor_opened = sensors_opened[0];
  temp_sensor_opened = sensors_opened[1];
}