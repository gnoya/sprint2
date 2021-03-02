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

void index_add(void)
{

  menu_index = menu_index + 1;
  if (menu_current == 0 && menu_index > 4)
    menu_index = 4; // Main Menu
  if (menu_current == 1 && menu_index > 4)
    menu_index = 4; // Operating Mode Menu
  if (menu_current == 2 && menu_index > 3)
    menu_index = 3; // Select Sensor Menu
  show = 1;
}

void index_sub(void)
{

  menu_index = menu_index - 1;
  if (menu_index < 0)
    menu_index = 0;
  show = 1;
}

void index_current(void)
{

  if (menu_current == 1 && menu_index == 4)
  {
    menu_current = 0;
    menu_index = 0;
    show = 1;
    return;
  }
  if (menu_current == 2 && menu_index == 3)
  {
    menu_current = 0;
    menu_index = 0;
    show = 1;
    return;
  }
  if (menu_current != 0 || (menu_current == 0 && menu_index > 1))
    return;
  menu_current = menu_index + 1;
  menu_index = 0;
  show = 1;
}

void show_index(void)
{

  printf("menu_index: %d \n\r", menu_index);
  printf("menu_current: %d \n\r", menu_current);
}

void lcd_menu(void)
{
  switch (menu_current)
  {
  case 0:
    lcd_menu_main();
    break;
  case 1:
    lcd_menu_mode();
    break;
  case 2:
    lcd_menu_sensors();
    break;
  default:
    menu_current = 0;
    break;
  }
}

void lcd_menu_main(void)
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

void lcd_menu_mode(void)
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

void lcd_menu_sensors(void)
{
  switch (menu_index)
  {
  case 0:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("  Sensor de    >");
    LCDGoto(0, 1);
    LCDPutStr("  Temperatura    ");
    break;
  case 1:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<  Sensor de   >");
    LCDGoto(0, 1);
    LCDPutStr("    Luminocidad  ");
    break;
  case 2:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<  Sensor de   >");
    LCDGoto(0, 1);
    LCDPutStr("     Sonido     ");
    break;
  case 3:
    LCDClear();
    LCDGoto(0, 0);
    LCDPutStr("<   Regresar   ");
    break;
  default:
    menu_index = 1;
    break;
  }
}

void initialize_menu(menu_controller *menu)
{
  menu->index_add = index_add;
  menu->index_sub = index_sub;
  menu->index_current = index_current;
  menu->show_index = show_index;
  menu->lcd_menu = lcd_menu;
  menu->lcd_menu_main = lcd_menu_main;
  menu->lcd_menu_mode = lcd_menu_mode;
  menu->lcd_menu_sensors = lcd_menu_sensors;
}