CC=	clang
all:	GPIO.so
GPIO.so:	GPIO.c
	$(CC) -shared -fPIC $> -o $@ -I/usr/pkg/include/python2.7
