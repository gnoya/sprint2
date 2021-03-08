/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   menu.c
 * Author: Group 2
 * Comments:
 * Revision history: 
 */

/**
  @Summary
    This struct is used to control the flow of the menu

  @Description
    This struct is used to control the flow of the menu and submenus
*/
typedef struct menu_controller
{
  bool light_sensor_opened;
  bool temp_sensor_opened;
  void (*index_add)(void);
  void (*index_sub)(void);
  void (*index_enter)(void);
  void (*show_index)(void);
  void (*show_menu)(void);
  void (*show_main_menu)(void);
  void (*show_mode_menu)(void);
  void (*show_sensors_menu)(void);
} menu_controller;

// --------- Public variables --------- //
bool show = 1;
bool temp_sensor_enabled = true;
bool light_sensor_enabled = true;

/**
  @Summary
    Adds one to the variable menu_index

  @Description
    This function increments the value of the menu_index variable by 1, to scroll through the current menu options.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
static void index_add(void);

/**
  @Summary
    Subtracts one from the variable menu_index

  @Description
    This function decrements the value of the menu_index variable by 1, to scroll through the current menu options.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
static void index_sub(void);

/**
  @Summary
    Updates the current_menu variable with the value of the selected menu.

  @Description
    This function updates the menu_current variable with the value of the menu 
 *  selected by the user, to show the corresponding submenu in the GUI.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
static void index_enter(void);

/**
  @Summary
    Prints on the serial console the values of the indexes menu_index and 
 *  menu_current.

  @Description
    This function prints to the serial console the values of the 
 *  menu_index and menu_current indexes used to navigate between the GUI menus.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
static void show_index(void);

/**
  @Summary
    Selects the GUI menu to be displayed on the screen.

  @Description
    This function selects and displays in the GUI the menu corresponding to the 
 *  value of menu_current.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
static void show_menu(void);

/**
  @Summary
    Show the main menu in the GUI.

  @Description
    This function sets the main menu template and displays the option 
 *  corresponding to the value of menu_index in the GUI.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
static void show_main_menu(void);

/**
  @Summary
    Show the Operating Mode submenu in the GUI.

  @Description
    This function sets the Operating Mode submenu template and displays the option 
 *  corresponding to the value of menu_index in the GUI.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
static void show_mode_menu(void);

/**
  @Summary
    Show the Sensors submenu in the GUI.

  @Description
    This function sets the Sensors submenu template and displays the option 
 *  corresponding to the value of menu_index in the GUI.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
static void show_sensors_menu(void);

// TODO: comentar
static void show_turn_off_timer_menu(void);

/**
  @Summary
    Initializes the menu controller

  @Description
    This function assigns the static functions to the menu_controller variable

  @Preconditions
    None

  @Param
    menu_controller menu, bool sensors_opened[]

  @Returns
    None
*/
void initialize_menu(menu_controller *menu, bool sensors_opened[]);