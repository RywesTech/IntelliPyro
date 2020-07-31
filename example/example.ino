/*
  example.ino
  Created by Ryan Westcott - July 2020
*/

#include "Pyro.h"

float batteryVoltage = 0;

// Initilize a pyro object
// pin, jumpHeight, jumpTime, slopeTime, runHeight, runTime
Pyro pyro(2, 60, 15, 200, 12, 1500);

void setup() {
  Serial.begin(115200);
  pyro.init();
  pyro.enableSafety(11.0,9.5);

  // wait 3 seconds then fire the pyro channel
  delay(3000);
  Serial.println("desired,actual,voltage"); // header for the serial plotter
  pyro.fire();
}

void loop() {
  batteryVoltage = (((analogRead(A9) / 1023.0) * 3.3) * (51.0 + 360.0)) / 51.0; // Determine your battery voltage (in V) however you want.
  
  pyro.update(batteryVoltage); // this needs to be called at every loop

  // Print out data to serial monitor
  Serial.print(pyro.getDesiredValue());
  Serial.print("\t");
  Serial.print(pyro.getActualValue());
  Serial.print("\t");
  Serial.println(batteryVoltage);
}