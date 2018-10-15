CC=	clang
OS!=	uname
.if $(OS) == "FreeBSD"
INCLUDE= -I/usr/local/include/python2.7
.elif $(OS) == "NetBSD"
INCLUDE= -I/usr/pkg/include/python2.7
.endif

all:	GPIO.so
GPIO.so:	GPIO.c
	$(CC) -shared -fPIC $> -o $@ $(INCLUDE)
