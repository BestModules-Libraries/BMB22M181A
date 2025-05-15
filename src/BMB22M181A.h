/*************************************************************************
File:         BMB22M181A.h
Author:       BEST MODULES CORP.
Description:  Define classes and required variables
History：     V1.0.1   -- 2025-03-28
**************************************************************************/
#ifndef _BMB22M181A_H
#define _BMB22M181A_H


#include <Arduino.h>
#include <Wire.h>

#define BMB22M181A_ADDRESS 0x77


class BMB22M181A
{
public:
	BMB22M181A(uint8_t intPin = 2,TwoWire *theWire = &Wire);
	void begin(uint8_t i2c_addr = BMB22M181A_ADDRESS);
  uint8_t getINT();
	void setChannel(uint8_t channel = 0b11111111);
  uint8_t getChannelStatus(void);
private:
  uint8_t _intPin;
  uint8_t _i2caddr;
  TwoWire *_theWire;
};
#endif
