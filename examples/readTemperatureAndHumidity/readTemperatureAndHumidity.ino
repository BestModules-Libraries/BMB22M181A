/*****************************************************************
File:         readTemperatureAndHumidity.ino
Description:      1.The Wire is used for IIC communication with the BMB22M181A/BME33M251A.
                  2.Use a hardware serial port (BAUDRATE 9600) to communicate with the serial monitor.
                  Two BME33M251A temperature and humidity data are read every 2s and displayed on the serial monitor.
connection method： i2cPort:Wire  intPin:D2         
******************************************************************/
#include "BMB22M181A.h"
#include "BM25S2021-1.h"

BMB22M181A        IICPort(2,&Wire);  //Please uncomment out this line of code if you use HW Wire on BMduino
//BMB22M181A        IICPort(22,&Wire1);  //Please uncomment out this line of code if you use HW Wire1 on BMduino
//BMB22M181A        IICPort(25,&Wire2);  //Please uncomment out this line of code if you use HW Wire1 on BMduino
BM25S2021_1       BMht(&Wire);       //Please uncomment out this line of code if you use HW Wire on BMduino
//BM25S2021_1       BMht(&Wire1);       //Please uncomment out this line of code if you use HW Wire1 on BMduino
//BM25S2021_1       BMht(&Wire2);       //Please uncomment out this line of code if you use HW Wire1 on BMduino

float  Temperature1,Humidity1,Temperature2,Humidity2;

void setup() 
{
  Serial.begin(9600);
  IICPort.begin();  //Module initialization
  BMht.begin();     //Module initialization
  delay(2000);
}

void loop()
{
   Temperature1 = 0;
   Humidity1 = 0;
   Temperature2 = 0;
   Humidity2 = 0;

   IICPort.setChannel(0b00001000);         //IIC3 is enabled and other IIC interfaces are disabled
   Temperature1 = BMht.readTemperature();  //Read temperature
   Humidity1 = BMht.readHumidity();        //Read humidity
   Serial.print("Temperature1 : ");
   Serial.print(Temperature1);
   Serial.print(" °C ");
   Serial.print("Humidity1 : ");
   Serial.print(Humidity1);
   Serial.println(" %    ");

   IICPort.setChannel(0b00010000);         //IIC4 is enabled and other IIC interfaces are disabled
   Temperature2 = BMht.readTemperature();  //Read temperature
   Humidity2 = BMht.readHumidity();        //Read humidity
   Serial.print("Temperature2 : ");
   Serial.print(Temperature2);
   Serial.print(" °C ");
   Serial.print("Humidity2 : ");
   Serial.print(Humidity2);
   Serial.println(" %    ");
   Serial.println(" ");   
   delay(2000);
}


