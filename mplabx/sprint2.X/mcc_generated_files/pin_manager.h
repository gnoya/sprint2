/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16LF1717
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SENSOR_TEMP aliases
#define SENSOR_TEMP_TRIS                 TRISAbits.TRISA0
#define SENSOR_TEMP_LAT                  LATAbits.LATA0
#define SENSOR_TEMP_PORT                 PORTAbits.RA0
#define SENSOR_TEMP_WPU                  WPUAbits.WPUA0
#define SENSOR_TEMP_OD                   ODCONAbits.ODA0
#define SENSOR_TEMP_ANS                  ANSELAbits.ANSA0
#define SENSOR_TEMP_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SENSOR_TEMP_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SENSOR_TEMP_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SENSOR_TEMP_GetValue()           PORTAbits.RA0
#define SENSOR_TEMP_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SENSOR_TEMP_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SENSOR_TEMP_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define SENSOR_TEMP_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define SENSOR_TEMP_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define SENSOR_TEMP_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define SENSOR_TEMP_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define SENSOR_TEMP_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set SENSOR_LIGHT aliases
#define SENSOR_LIGHT_TRIS                 TRISAbits.TRISA1
#define SENSOR_LIGHT_LAT                  LATAbits.LATA1
#define SENSOR_LIGHT_PORT                 PORTAbits.RA1
#define SENSOR_LIGHT_WPU                  WPUAbits.WPUA1
#define SENSOR_LIGHT_OD                   ODCONAbits.ODA1
#define SENSOR_LIGHT_ANS                  ANSELAbits.ANSA1
#define SENSOR_LIGHT_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define SENSOR_LIGHT_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define SENSOR_LIGHT_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define SENSOR_LIGHT_GetValue()           PORTAbits.RA1
#define SENSOR_LIGHT_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define SENSOR_LIGHT_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define SENSOR_LIGHT_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define SENSOR_LIGHT_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define SENSOR_LIGHT_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define SENSOR_LIGHT_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define SENSOR_LIGHT_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define SENSOR_LIGHT_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA3 procedures
#define RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetPullup()             do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()           do { WPUAbits.WPUA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set SELECTOR_1 aliases
#define SELECTOR_1_TRIS                 TRISBbits.TRISB1
#define SELECTOR_1_LAT                  LATBbits.LATB1
#define SELECTOR_1_PORT                 PORTBbits.RB1
#define SELECTOR_1_WPU                  WPUBbits.WPUB1
#define SELECTOR_1_OD                   ODCONBbits.ODB1
#define SELECTOR_1_ANS                  ANSELBbits.ANSB1
#define SELECTOR_1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SELECTOR_1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SELECTOR_1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SELECTOR_1_GetValue()           PORTBbits.RB1
#define SELECTOR_1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SELECTOR_1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SELECTOR_1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define SELECTOR_1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define SELECTOR_1_SetPushPull()        do { ODCONBbits.ODB1 = 0; } while(0)
#define SELECTOR_1_SetOpenDrain()       do { ODCONBbits.ODB1 = 1; } while(0)
#define SELECTOR_1_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define SELECTOR_1_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set SELECTOR_2 aliases
#define SELECTOR_2_TRIS                 TRISBbits.TRISB2
#define SELECTOR_2_LAT                  LATBbits.LATB2
#define SELECTOR_2_PORT                 PORTBbits.RB2
#define SELECTOR_2_WPU                  WPUBbits.WPUB2
#define SELECTOR_2_OD                   ODCONBbits.ODB2
#define SELECTOR_2_ANS                  ANSELBbits.ANSB2
#define SELECTOR_2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define SELECTOR_2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define SELECTOR_2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define SELECTOR_2_GetValue()           PORTBbits.RB2
#define SELECTOR_2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define SELECTOR_2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define SELECTOR_2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define SELECTOR_2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define SELECTOR_2_SetPushPull()        do { ODCONBbits.ODB2 = 0; } while(0)
#define SELECTOR_2_SetOpenDrain()       do { ODCONBbits.ODB2 = 1; } while(0)
#define SELECTOR_2_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define SELECTOR_2_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/