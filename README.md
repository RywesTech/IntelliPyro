# InteliPyro Library

### This library is still in development, use at your own risk!

This library has 3 objectives:
1. (✅ working) Heat up nichrome faster than just simply applying a constant current/voltage
2. (✅ working) Prevent brown-outs by decreasing pyro current when the battery voltage drops too low.
3. (❌ in progress) Prevent short-circuits by disabling the pyro channel when an immediate drop in battery voltage is detected.

## How to tune your pyro channel
A tuned pyro channel is necessary for heating up your nichrome fast. Begin by inserting your desired length and gauge of nichrome into your flight computer. Set the jumpTime to 0, and runTime to 2 or 3 seconds. Begin to increase your runHeight by ~5% until you reach a temperature that is sustainable and hot enough to cut whatever you need. Then, set jump time to about 70ms and increase jumpHeight in the same manner that you used for runHeight. Keep increasing until your nichrome gets a bit too hot at the beginning, then decrease runTime and increase runHeight until you get down to 20ms or so. By the end there should be a fast start time with little to no overshoot in temperature.

Here is an important graphic to use when tuning your channels:

![Image not loading](images/legend.png)

## How to tune for brown-out prevention

Choose a upperVoltage to be about 3.2 volts per cell (this is where the decrease in Pyro power starts) and a lowerVoltage of about 2.8 volts per cell (this is where your pyro channel will be completely off). Test in different scenarios to make sure your particular flight computer can still receive enough power.

## More info

Hit me up on Twitter! [@rswestcott](https://twitter.com/rswestcott)
