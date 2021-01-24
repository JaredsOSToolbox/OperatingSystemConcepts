obj-m += birthday.o
COMPILER = clang
CFLAGS = -Wall
OUTPUT = birthday

all: birthday

birthday $(obj-m):
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

birthday.o:
	$(COMPILER) $(CFLAGS) -c -g src/birthday.c

load:
	sudo dmesg -C
	sudo insmod lkm_example.ko
	lsmod | grep “lkm_example”
	sudo rmmod lkm_example
	dmesg

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
