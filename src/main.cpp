#include <Arduino.h>
#include <Wire.h>

#include "GY45_MMA8452.h"

void setup()
{
  Serial.begin(57600);
  Serial.println("MMA8452 Basic Example");

  Wire.begin(); //Join the bus as a master

  initMMA8452(); //Test and intialize the MMA8452
}

void loop()
{
  int accelCount[3];  // Stores the 12-bit signed value
  readAccelData(accelCount);  // Read the x/y/z adc values

  // Now we'll calculate the accleration value into actual g's
  float accelG[3];  // Stores the real accel value in g's
  for (int i = 0 ; i < 3 ; i++)
  {
    accelG[i] = (float) accelCount[i] / ((1<<12)/(2*GSCALE));  // get actual g value, this depends on scale being set
  }

  // Print out values
  for (int i = 0 ; i < 3 ; i++)
  {
    Serial.print(accelG[i], 4);  // Print g values
    Serial.print("\t");  // tabs in between axes
  }
  Serial.println();

  delay(1000);  // Delay here for visibility
}
