/*
  Pyro.cpp
  Created by Ryan Westcott - July 2020
*/

#include "Arduino.h"
#include "Pyro.h"

Pyro::Pyro(int pin, int jumpHeight, int jumpTime, int slopeTime, int runHeight, int runTime) {
  _pin = pin;
  _jumpHeight = jumpHeight;
  _jumpTime = jumpTime;
  _slopeTime = slopeTime;
  _runHeight = runHeight;
  _runTime = runTime;
}


void Pyro::init() {
  pinMode(_pin, OUTPUT);
}

void Pyro::fire() {
  _beginMillis = millis();
  _active = true;
}

void Pyro::update(float bVoltage) {

  if (_active) {
    _localMillis = millis() - _beginMillis;

    int slice0 = 0;
    int slice1 = _jumpTime;
    int slice2 = _jumpTime + _slopeTime;
    int slice3 = _jumpTime + _slopeTime + _runTime;

    if (_localMillis >= slice0 && _localMillis < slice1) {
      _desiredValue = _jumpHeight;
    } else if (_localMillis >= slice1 && _localMillis < slice2) {
      float slope = (_runHeight - _jumpHeight) / float(_slopeTime); // y2-y1/x2-x1
      _desiredValue = slope * (_localMillis - _jumpTime) + _jumpHeight;
    } else if (_localMillis >= slice2 && _localMillis < slice3) {
      _desiredValue = _runHeight;
    } else if (_localMillis >= slice3) {
      _desiredValue = 0;
      _active = false;
    }

    if(_safetyEnabled) { // if we have brown-out protection, check battery voltage to make sure we're not too
      float multiplier = constrain(map(bVoltage, _lowerVoltage, _upperVoltage, 0, 100), 0, 100);
      _actualValue = _desiredValue * (multiplier/100.0);
    } else {
      _actualValue = _desiredValue;
    }

  } else {
    _actualValue = 0;
  }

  analogWrite(_pin, (_actualValue / 100.0) * 255.0); // convert % to PWM write
}

void Pyro::enableSafety(float upperVoltage, float lowerVoltage) {
  _safetyEnabled = true;
  _upperVoltage = upperVoltage;
  _lowerVoltage = lowerVoltage;
}

void Pyro::reset() {
  _active = false;
}

bool Pyro::getActive() {
  return _active;
}

int Pyro::getDesiredValue() {
  return _desiredValue;
}

int Pyro::getActualValue() {
  return _actualValue;
}
