#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <err.h>
#include <errno.h>

#include "Python.h"

#include <sys/types.h>
#include <sys/gpio.h>
#include <sys/ioctl.h>

#define BCM	0
#define OUT	0
#define IN	1

static PyObject *bcm;
static PyObject *out;
static PyObject *in;

#define DEV	"/dev/gpio0"
int fd;

PyObject* GPIO_output(PyObject* self, PyObject* args)
{
	int pin,v;
	struct gpio_req req;

	if (!PyArg_ParseTuple(args, "ii", &pin, &v))
		return NULL;

	// printf("output: %d %d\n",pin,v);

	if(v>1) v=1;
	if(v<0) v=0;

	memset(&req, 0, sizeof(req));
	req.gp_pin = pin;
	req.gp_value = v;
	if(ioctl(fd, GPIOWRITE, &req)==-1)
		err(EXIT_FAILURE, "GPIOWRITE");

	return Py_BuildValue("");
}

PyObject* GPIO_setmode(PyObject* self, PyObject* args)
{
	int mode;

	if (!PyArg_ParseTuple(args, "i", &mode))
		return NULL;
	printf("setmode: %d\n",mode);
	return Py_BuildValue("");
}

PyObject* GPIO_setwarnings(PyObject* self, PyObject* args)
{
	int f;

	if (!PyArg_ParseTuple(args, "i", &f))
	printf("setwarnings: %d\n",f);
	return Py_BuildValue("");
}

PyObject* GPIO_setup(PyObject* self, PyObject* args)
{
	int pin,mode;

	if (!PyArg_ParseTuple(args, "ii", &pin, &mode))
	printf("setup: %d %d\n",pin,mode);

	if((fd=open(DEV,O_RDWR)) == -1)
		err(EXIT_FAILURE, "%s", DEV);

	return Py_BuildValue("");
}

static PyMethodDef GPIOmethods[] = {
	{"output", GPIO_output, METH_VARARGS},
	{"setmode", GPIO_setmode, METH_VARARGS},
	{"setwarnings", GPIO_setwarnings, METH_VARARGS},
	{"setup", GPIO_setup, METH_VARARGS},
	{NULL},
};

void initGPIO()
{
	PyObject *module = NULL;

	module=Py_InitModule("GPIO", GPIOmethods);

	bcm = Py_BuildValue("i", BCM);
	PyModule_AddObject(module, "BCM", bcm);
	out = Py_BuildValue("i", OUT);
	PyModule_AddObject(module, "OUT", out);
	in = Py_BuildValue("i", IN);
	PyModule_AddObject(module, "IN", in);
}
