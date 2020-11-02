import subprocess
import platform

BCM=0
OUT=0
IN=1

OS=platform.system()
print(OS)

def output(pin,v):
  print("pin,value:%d,%d"%(pin,v))
  if v>0: v=1
  if OS=="FreeBSD":
    shell="gpioctl -f /dev/gpioc0 -p %d %d" % (pin,v)
  else:
    # NetBSD or OpenBSD
    shell="gpioctl -q gpio0 %d %d" % (pin,v)
  subprocess.call(shell.split())

# dummy function
def setmode(mode):
  print("setmode:",mode)

def setwarnings(f):
  print("setwarnings:",f)

def setup(pin,mode):
  print("setup:",pin, mode)
  if mode==0:
    mstr="OUT"
  else:
    mstr="IN"

  # If you use NetBSD or OpenBSD, you must setup GPIO at boottime with /etc/gpio.conf and /etc/rc.conf.
  # For example:
  # At /etc/rc.conf
  # gpio=YES
  # At /etc/gpio.conf
  # #GPIO	pin    	mode	name
  # gpio0	23	set	out		dat
  # gpio0	24	set	out		clk
  if OS=="FreeBSD":
    shell="gpioctl -f /dev/gpioc0 -c %d %s" % (pin,mstr)
  subprocess.call(shell.split())
