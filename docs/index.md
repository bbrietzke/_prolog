
_prolog is an attempt at porting the the [Prolog](https://en.wikipedia.org/wiki/Prolog) 
language to something that can run on modern and not so modern [µControllers](https://en.wikipedia.org/wiki/Microcontroller).

## Why?
The idea does seem more than a little crazy, I'll be the first to admit it. 

Given Prolog's nature as a rules based nature, where as a developer or engineer assigns _facts_ and creates _rules_ which are 
bound together with relationships that are then consulted with to find an answer it seems like a like an
ideal way to build a closed-system system with a given challenge domain.  Most programs that run on microcontrollers are 
designed to take external inputs (i.e. temperatures, switches, etc.), consult an internal logic set to do *something* such as turn on a light, or activate a fan.

For example, the processor in your computer is a heat generating device that is enclosed in a shell or case that does 
not provide much airflow.  In most situations, you will have a fan or heat sink that will help mitigate the heat build up.  It is a 
microcontroller of some variety that will keep tabs on the controller temperature either through a sensor or talking 
with the processor directly and will decided to activate a fan when the processor gets within certain heat thresholds.  If the 
processor temperature gets over a critical threshold, an alarm may be triggered to turn off the system as a whole before irreparable
 damage is done.

That pretty much sounds like an rules engine to me.

This engine is more than likely coded in [C](https://en.wikipedia.org/wiki/C_(programming_language)) with a jumbled mess of 
_if/then/else_ statements interspersed with function calls to turn on or off [GPIO](https://en.wikipedia.org/wiki/General-purpose_input/output) ports 
to use [PWM](https://en.wikipedia.org/wiki/Pulse-width_modulation) to control fans or activate [LEDs](https://en.wikipedia.org/wiki/Light-emitting_diode) to notify the operator.  This engine will be uploaded or flashed to the microcontroller so that it can do it's job of keeping the processor safe.

There is nothing wrong with writing such an engine in C.  If fact, it's being done that way across billions of microcontroller 
and installed on millions of devices.  C is comparatively easy programming language to learn and use and is still one of the most
popular languages out in the wild today.

But does that means it's the best?

## Comparisons
Lets stick with example of controlling heat for a closed-system with limited ventilation.  This could be the inside of a computer case or an industrial controller in a manufacturing plant.  

With such a system you will have the device that is being monitored (i.e. processor or relay bank) along with a one or more
temperature sensors, one or more fans, zero or more visual indicators and zero or more remote notifiers.
