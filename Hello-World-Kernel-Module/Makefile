obj-m += Hello_World.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test: all
	sudo dmesg -C
	sudo insmod Hello_World.ko
	lsmod | grep “Hello_World” && echo "yes" || echo "no"
	sudo rmmod Hello_World
	dmesg
