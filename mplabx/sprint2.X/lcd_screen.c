/*
 * File:   lcd_screen.c
 * Author: Group 2
 *
 * Created on February 24, 2021, 10:07 PM
 */

#include <stdio.h>
#include <stdbool.h>
#include "lcd.h"
#include "menu.h"

/*
static void demo1();
static void demo2();
static void demo3();
*/

//void lcd_clear();

void lcd_clear(void)
{
  LCDGoto(0,0);
  LCDPutStr("                ");
  LCDGoto(0,1);
  LCDPutStr("                ");
}


/*static void demo3()
{
  printf("Demo 3!\n");
}
*/

/*
 void initialize_lcd_screen(lcd_screen *lcd_screen_var)
{
  
  lcd_screen_var->demo1 = demo1;
  lcd_screen_var->demo2 = demo2;
  lcd_screen_var->demo3 = demo3;
  
}
*/