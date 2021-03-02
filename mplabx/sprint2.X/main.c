/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16LF1717
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include <stdbool.h>
#include <string.h>
#include "mcc_generated_files/mcc.h"
#include "sensor_adapter.h"
#include "light_sensor.h"
#include "temp_sensor.h"
#include "lcd_screen.h"
#include "led_adapter.h"
#include "lcd.h"

/*
                         Main application
 */
sensor light_sensor;
sensor temp_sensor;
lcd_screen lcd_screen_var;
led led_var;

void read_sensors(void)
{
}

void main(void)
{
  SYSTEM_Initialize();
  LCD_Initialize();
  // ------------------- Initializing variables ---------------- //
  char *sensor_names[3] = {};
  char **names_pointer = sensor_names;
  int sensor_counter = 0;

  // ------------------- Initializing structs ----------------- //
  initialize_light(&light_sensor);
  initialize_temp(&temp_sensor);
  initialize_lcd_screen(&lcd_screen_var);
  initialize_led(&led_var);

  // --------------------- Opening sensors ------------------- //
  if (temp_sensor.open())
  {
    printf("Temperature sensor is available\r\n");
    names_pointer[sensor_counter++] = temp_sensor.name;
  }

  if (light_sensor.open())
  {
    printf("Light sensor is available\r\n");
    names_pointer[sensor_counter++] = light_sensor.name;
  }

  // --------------------- Printing available sensors ------------------- //
  int i;
  for (i = 0; i < sensor_counter; i++)
    printf("%s \r\n", names_pointer[i]);

  // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
  // Use the following macros to:

  // Enable the Global Interrupts
  // INTERRUPT_GlobalInterruptEnable();

  // Enable the Peripheral Interrupts
  // INTERRUPT_PeripheralInterruptEnable();
  LCDPutStr("hola");
  while (1)
  {
    int light_value = light_sensor.read();
    int temp_value = temp_sensor.read();

    led_var.set_brightness(light_value);
    led_var.set_color(temp_value);
  }
}
/**
 End of File
*/