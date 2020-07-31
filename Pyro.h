/*
  Pyro.h
  Created by Ryan Westcott - July 2020
*/

#ifndef Pyro_h
#define Pyro_h

#include "Arduino.h"

class Pyro {
  public:
    Pyro(int pin, int jumpHeight, int jumpTime, int slopeTime, int runHeight, int runTime);
    void init();
    void fire();
    void update(float bVoltage);
    void enableSafety(float _upperVoltage, float _lowerVoltage);
    void reset();
    bool getActive();
    int getDesiredValue();
    int getActualValue();
  private:
    int _pin;
    int _jumpHeight;
    int _jumpTime;
    int _slopeTime;
    int _runHeight;
    int _runTime;

    float _upperVoltage;
    float _lowerVoltage;
    bool _safetyEnabled;

    int _beginMillis;
    int _localMillis;
    int _active;
    int _desiredValue;
    int _actualValue;
};

#endif
