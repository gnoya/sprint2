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

/*
  This project was developed by the Group 2 in the Embbeded Systems 1 course from USB.
  This project aims to develop a lighting system using sensors.
  Version: 1.0
*/

#include <stdbool.h>
#include <string.h>
#include "mcc_generated_files/mcc.h"
#include "menu_controller.h"
#include "sensor_adapter.h"
#include "light_sensor.h"
#include "temp_sensor.h"
#include "led_adapter.h"
#include "lcd.h"

/*
                         Main application
 */
sensor light_sensor;
sensor temp_sensor;
led_adapter led;
menu_controller menu;

void main(void)
{
  SYSTEM_Initialize();
  LCD_Initialize();
  // ------------------- Initializing variables ---------------- //
  char *sensor_names[3] = {};
  char **names_pointer = sensor_names;
  int sensor_counter = 0;

  // ------------------- Initializing sensors ----------------- //
  initialize_light(&light_sensor);
  initialize_temp(&temp_sensor);

  // --------------------- Opening sensors ------------------- //
  bool temp_sensor_opened = temp_sensor.open();
  bool light_sensor_opened = light_sensor.open();

  bool sensors_opened[2] = {temp_sensor_opened, light_sensor_opened};

  // --------------- Initializing led and menu --------------- //
  initialize_led(&led);
  initialize_menu(&menu, sensors_opened);

  // ------------------ Enabling Interrupts -------------------- //
  INTERRUPT_GlobalInterruptEnable();
  INTERRUPT_PeripheralInterruptEnable();

  // ------------ Setting button's Interrupt Handlers ------------ //
  IOCAF5_SetInterruptHandler(menu.index_add);
  IOCAF6_SetInterruptHandler(menu.index_sub);
  IOCAF7_SetInterruptHandler(menu.index_enter);

  // ----------- Writing a welcome message in the LCD ----------- //
  LCDPutStr("Bienvenido!");
  __delay_ms(200);

  // ------------------------ Main loop ----------------------- //
  while (1)
  {
    // -------------------- Reading sensors -------------------- //
    int temp_value = temp_sensor.read();
    int light_value = light_sensor.read();

    // -------------------- Changing LEDs --------------------- //
    led.set_color(temp_value);
    led.set_brightness(light_value);

    // -------------------- Showing menu --------------------- //
    menu.show_menu();
  }
}
/**
 End of File
*/