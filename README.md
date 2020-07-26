Kids GoKart Controller
======
**Kids GoKart Controller** Controls a simple and cheap geared DC motor. 

Last year, we got the kids a cheap WalMart plastic ride-in car that runs on a 12V Lead Acid battery.

It's alright for power (that'll probably change when the get a few years older ;)), but the controller is just a switch.

So, whenever they press the gas, it just closes a switch and drops the full battery voltage across the motor terminals, and the whole car lurches forward.

Anyway, that's not great for their necks, so this is a simple bit of code you can use to control the ramp up of the motor if your system has a single 1 bit input to toggle
the motor on or off.  If you like whipping your melon on the headrest every time you touch the gas, then by all means, don't let me keep you.  But, if you enjoy the finer
things in cheap imported bottom-dollar whatch-the-sparks motor controls, then step this way.

#### Screenshot
## Behold the (Neck) Kracken!
![Screenshot software](https://i5.walmartimages.com/asr/b12fd4e6-a230-48ca-a588-b58e65d6c5d6_1.c6e39c4c21f71234ce7eaa1315832471.jpeg?odnHeight=450&odnWidth=450&odnBg=FFFFFF)

## Usage
```$ git clone https://github.com/dale6998/FW_GoKart.git
```$ cd FW_GoKart
   $ make
...
Flash using whatever you wish.  I like OpenOCD and gdb, but other flashing environments should work too.
```
## Contributors

### Contributors on GitHub

### Translations

### Third party libraries
  STM32CubeMx 5.4

## License 
IDGAF...take it and have fun!

## Version 
* Version 0.1

## How-to use this code
This is meant to be used with the schamtics provided at [this repo](https://github.com/dale6998/Electrical_GoKart).

Put that together, test for shorts, apply power, hit the deck (very important lol), and you should be done.

## Contact
#### Dale
* e-mail: dale@bubblestech.com
* Twitter: [@twitterhandle](https://twitter.com/dale6998 "dale6998")
* other communication/social media

[![Flattr this git repo](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=username&url=https://github.com/username/sw-name&title=sw-name&language=&tags=github&category=software) 
