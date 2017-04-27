obj-m += random.o

all: module

module:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
