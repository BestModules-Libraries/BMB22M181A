/*********************************************************************************************
File:             BMB22M181A.cpp
Author:           BEST MODULES CORP.
Description:      Enable the IIC sub-serial port for IIC communication with BMB22M181A
History：         V1.0.1   -- 2025-03-28
**********************************************************************************************/
#include "BMB22M181A.h"

/************************************************************************* 
Description:  Constructor
Parameters:   intPin  ：INT Output pin connection with Arduino 
              theWire : Wire object if your board has more than one I2C interface     
Return:       none  
Others:       none  
*************************************************************************/
BMB22M181A::BMB22M181A(uint8_t intPin ,TwoWire *theWire)
{
     _intPin = intPin;
     _theWire = theWire;     
}

/************************************************************************* 
Description:  Initialize 
parameter:    i2c_addr:  i2c communication address (Default: 0x77)       
Return:       void  
Others:       none  
*************************************************************************/
void BMB22M181A::begin(uint8_t i2c_addr)
{
  pinMode(_intPin,INPUT_PULLUP);
  _theWire->begin();   
  _i2caddr = i2c_addr;
}


/**********************************************************
Description: Get INT Status
Parameters:         
Return:     Returns the INT Status  0:INT output low level 
                                    1:INT output high level  
Others:     
**********************************************************/
uint8_t BMB22M181A::getINT()
{
     return (digitalRead(_intPin));
}

/************************************************************************* 
Description:   set Channel
parameter:     channel: Select the IIC subinterface      
                         bit0: Whether to enable the IIC0 interface
                               0: Off
                               1: open
                         bit1: Whether to enable the IIC1 interface
                               0: Off
                               1: open
                         bit2: Whether to enable the IIC2 interface
                               0: Off
                               1: open
                         bit3: Whether to enable the IIC3 interface
                               0: Off
                               1: open
                         bit4: Whether to enable the IIC4 interface
                               0: Off
                               1: open
                         bit5: Whether to enable the IIC5 interface
                               0: Off
                               1: open
                         bit6: Whether to enable the IIC6 interface
                               0: Off
                               1: open    
                         bit7: Whether to enable the IIC7 interface
                               0: Off
                               1: open                                         
Return:        void
Others:        none 
*************************************************************************/
void BMB22M181A::setChannel(uint8_t channel)
{
  _theWire->beginTransmission(_i2caddr);
  _theWire->write(channel);
  _theWire->endTransmission();
}


/************************************************************************* 
Description:   get Channel Status
parameter:     void                                           
Return:        channelStatus: IIC interface status     
                         bit0: IIC0 interface status 
                               0: Off
                               1: open
                         bit1: IIC1 interface status
                               0: Off
                               1: open
                         bit2: IIC2 interface status
                               0: Off
                               1: open
                         bit3: IIC3 interface status
                               0: Off
                               1: open
                         bit4: IIC4 interface status
                               0: Off
                               1: open
                         bit5: IIC5 interface status
                               0: Off
                               1: open
                         bit6: IIC6 interface status
                               0: Off
                               1: open     
                         bit7: IIC7 interface status
                               0: Off
                               1: open
Others:        none 
*************************************************************************/
uint8_t BMB22M181A::getChannelStatus(void)
{
  uint8_t channelStatus = 0;
  _theWire->requestFrom(_i2caddr, 1);
  if(_theWire->available()==1)
  {
      for (uint8_t i = 0; i < 1; i++)
      {
        channelStatus = _theWire->read();
      }
     return channelStatus;
  }
  else
  {
      return 0;
  }
}