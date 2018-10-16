import subprocess

BCM=0
OUT=0
IN=1

def output(pin,v):
  if v>0: v=1
  shell="gpioctl -q gpio0 %d %d" % (pin,v)
  #print shell
  subprocess.call(shell.split())

# dummy function
def setmode(mode):
  print "setmode:",mode

def setwarnings(f):
  print "setwarnings:",f

def setup(pin,mode):
  print "setup:",pin, mode
