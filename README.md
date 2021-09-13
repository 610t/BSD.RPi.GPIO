# BSD.RPi.GPIO
Python RPi.GPIO library for BSD

## How to run
### 1. Check out from github
Check out this library.
> $ git clone https://github.com/610t/BSD.RPi.GPIO 

Check out blinkt library.
> $ $ git clone https://github.com/pimoroni/blinkt

Directory structure is below:
- blinkt/
   -  library/
      - blinkt.py : Library in Python for Blinkt!.
   -  examples/
      - *.py : Demo programs
- BSD.RPi.GPIO/
   - RPi/
      - GPIO.c : Source code in C language for GPIO handling.
      - GPIO.py : Source code in Python using gpioctl.
      - Makefile : Makefile for build GPIO.o from GPIO.c.

### 2. Compile GPIO.c
Compile GPIO.c for creating GPIO.o.  
> $ cd BSD.RPi.GPIO/RPi/  
> $ make  

### 3. Create demo environment
Place file for running examples like this.
- blinkt/examples/
   - blinkt.py
   - GPIO.so
   - *.py

The command line inputs is below:
> $ pwd  
> blinkt/examples/  
> $ cp ../library/blinkt.py .  
> $ cp ../../BSD.RPi.GPIO/RPi/GPIO.so .  

### 4. Patch for blinkt.py for your pin configuration
Except Raspberry Pi, you must patch for blinkt.py for your pin configuration.

In this example, if Blynkt! is inserted at 24 pins at NanoPi NEO2, use pin 88 for DAT(PG8) and pin 89(PG9) for CLK.
[![Blynkt! at NanoPi NEO2](https://img.youtube.com/vi/c4HuA0kCc2I/0.jpg)](https://www.youtube.com/watch?v=c4HuA0kCc2I)

> $ diff -u blinkt.py.org blinkt.py  
> --- blinkt.py.org       2021-09-13 12:23:59.033536897 +0900  
> +++ blinkt.py   2021-09-13 12:25:04.346071363 +0900  
> @@ -2,13 +2,13 @@  
>  import atexit  
>  import time  
>    
> -import RPi.GPIO as GPIO  
> +import GPIO as GPIO  
>    
>    
>  __version__ = '0.1.2'  
>    
> -DAT = 23  
> -CLK = 24  
> +DAT = 88  
> +CLK = 89  
>  NUM_PIXELS = 8  
>  BRIGHTNESS = 7  
>    

### 5. Let's run demo!!
Like this.
> $ pwd  
> blinkt/examples/  
> $ sudo python2.7 rainbow.py  
