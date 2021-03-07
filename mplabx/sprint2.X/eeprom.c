/*
 * File:   eeprom.c
 * Author: grupo 2
 *
 * Created on March 6, 2021, 7:42 PM
 */
#include <stdio.h>
#include <stdbool.h>
#include "eeprom.h"
#include "mcc_generated_files/mcc.h"

#define EEPROM_DEVICE_ADDRESS 0x50

void eeprom_read (bool *temp_sensor_enabled, bool *light_sensor_enabled)
{
  uint8_t receiveData[2];
  uint8_t address[2] = {0x00,0x00};
  i2c_writeNBytes(0x50,address,2);
  i2c_readNBytes(0x50,receiveData,sizeof(receiveData));
  
  if (receiveData[0] == 0x00){
      *temp_sensor_enabled = false;
  }
  else {
      *temp_sensor_enabled = true;
  }
  
  if (receiveData[1] == 0x00){
      *light_sensor_enabled = false;
  }
  else {
      *light_sensor_enabled = true;
  }
}


void eeprom_write(bool temp_sensor_enabled,bool light_sensor_enabled)
{   
    
    uint8_t sendData[4] = {0x00,0x00,0x00,0x00};
    
    if (temp_sensor_enabled){
        sendData[2]=0x01;
    }
    if (light_sensor_enabled){
        sendData[3]=0x01;
    }
    
     i2c_writeNBytes(EEPROM_DEVICE_ADDRESS,sendData,sizeof(sendData));
     __delay_ms(20);
}

/*// ----------- i2c example -----------------------------------//
  uint8_t i=0;
  uint8_t sendData[17] = {0x00,0x00,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF}; 
  uint8_t receiveData[15];
  i2c_writeNBytes(0x50,sendData,sizeof(sendData));
  __delay_ms(200);
  i2c_writeNBytes(0x50,sendData,2);
  i2c_readNBytes(0x50,receiveData,sizeof(receiveData));
  
  for(i=0;i<sizeof(receiveData);i++)
    {
        printf("0x%x  ",receiveData[i]);
        if(((i+1)%5)==0){
            printf("\n\r");
        }
    }*/