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
#include "rtc.h"

#define MAIN_MENU 0
#define MAIN_BACK_INDEX 4

#define SENSORS_MENU 1
#define SENSORS_BACK_INDEX 2

#define TURN_OFF_TIMER_MENU 2
#define TURN_OFF_TIMER_BACK_INDEX 4

// ----------------------- Static (private) variables ----------------------- //
static bool temp_sensor_opened = false;
static bool light_sensor_opened = false;
static bool debouncing = false;
static int menu_current = 0;
static int menu_index = 0;
extern bool is_pic_on;

// ----------------------- Static (private) functions ----------------------- //
static void index_add(void)
{
  // ------------- Setting debouncing ------------- //
  if (debouncing)
    return;

  TMR2_LoadPeriodRegister(5);
  TMR2_SetInterruptHandler(debouncing_ISR);

  menu_index++;
  if (menu_current == MAIN_MENU && menu_index > 4)
    menu_index = MAIN_BACK_INDEX; // Main Menu
  if (menu_current == SENSORS_MENU && menu_index > SENSORS_BACK_INDEX)
    menu_index = SENSORS_BACK_INDEX; // Select Sensor Menu
  show = 1;
}

static void index_sub(void)
{
  // ------------- Setting debouncing ------------- //
  if (debouncing)
    return;

  TMR2_LoadPeriodRegister(5);
  TMR2_SetInterruptHandler(debouncing_ISR);

  /* If the current menu is sensors' menu
     This is a particular case since the previous
     index is not always the menu_index--
  */
  if (menu_current == SENSORS_MENU)
  {
    /* If we are in the last item of this menu
      we need to check which sensors are available
      so we don't show unavailable sensors in the screen
    */
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

  // The index should always be greater than 0
  if (menu_index < 0)
    menu_index = 0;

  show = 1;
}

static void reset_menu(void)
{
  // Reset indexes
  menu_current = 0;
  menu_index = 0;
  show = 1;
}

static void index_enter(void)
{
  // ------------- Setting debouncing ------------- //
  if (debouncing)
    return;

  TMR2_LoadPeriodRegister(5);
  TMR2_SetInterruptHandler(debouncing_ISR);

  // Turning on pic if it was off
  if (!is_pic_on)
  {
    is_pic_on = true;
    reset_menu();
    return;
  }

  // Back button of sensors menu
  if (menu_current == SENSORS_MENU && menu_index == SENSORS_BACK_INDEX)
  {
    reset_menu();
    return;
  }

  // Back button of turn off timer menu
  if (menu_current == TURN_OFF_TIMER_MENU && menu_index == TURN_OFF_TIMER_BACK_INDEX)
  {
    reset_menu();
    return;
  }

  // Enter on any turn off timer item
  if (menu_current == TURN_OFF_TIMER_MENU && menu_index != TURN_OFF_TIMER_BACK_INDEX)
  {
    switch (menu_index)
    {
    case 0:
      rtc_sleep(5);
      break;
    case 1:
      rtc_sleep(10);
      break;
    case 2:
      rtc_sleep(15);
      break;
    case 3:
      rtc_sleep(20);
      break;
    default:
      rtc_sleep(5);
      break;
    }

    reset_menu();
    return;
  }

  // Temperature sensor enter
  if (menu_current == SENSORS_MENU && menu_index == 0)
  {
    temp_sensor_enabled = !temp_sensor_enabled;
    show = 1;
    eeprom_write(temp_sensor_enabled, light_sensor_enabled);
    return;
  }

  // Light sensor enter
  if (menu_current == SENSORS_MENU && menu_index == 1)
  {
    light_sensor_enabled = !light_sensor_enabled;
    show = 1;
    eeprom_write(temp_sensor_enabled, light_sensor_enabled);
    return;
  }

  // For unavailable options like "Hora apagado/encendido"
  if (menu_current != MAIN_MENU || (menu_current == MAIN_MENU && menu_index > 2))
    return;

  // Update the menu and index (this only occurs in the main menu)
  menu_current = menu_index + 1;
  menu_index = 0;
  show = 1;
}

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
    LCDPutStr("   de Apagado   ");
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

static void show_turn_off_timer_menu(void)
{
  switch (menu_index)
  {
  case 0:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("      5      >");
    LCDGoto(0, 1);
    LCDPutStr("     minutos   ");
    break;
  case 1:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<      10      >");
    LCDGoto(0, 1);
    LCDPutStr("     minutos   ");
    break;
  case 2:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<      15      >");
    LCDGoto(0, 1);
    LCDPutStr("     minutos   ");
    break;
  case 3:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<      20      ");
    LCDGoto(0, 1);
    LCDPutStr("     minutos   ");
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

static void show_menu(void)
{
  // So we don't reset the screen everytime
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
  case TURN_OFF_TIMER_MENU:
    show_turn_off_timer_menu();
    break;
  default:
    menu_current = MAIN_MENU;
    break;
  }
  show = 0;
}

static void off(void)
{
  // Clear the screen
  LCDClear();
}

static void debouncing_ISR(void)
{
  TMR2_SetInterruptHandler(rtc_sleep_ISR);
  TMR2_LoadPeriodRegister((uint8_t)999);
  debouncing = false;
}

// ----------------------- Public functions ----------------------- //
void initialize_menu(menu_controller *menu, bool sensors_opened[])
{
  menu->index_add = index_add;
  menu->index_sub = index_sub;
  menu->index_enter = index_enter;
  menu->show_menu = show_menu;
  menu->show_main_menu = show_main_menu;
  menu->show_sensors_menu = show_sensors_menu;
  menu->off = off;
  temp_sensor_opened = sensors_opened[0];
  light_sensor_opened = sensors_opened[1];
}