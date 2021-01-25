obj-m += main.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test: all
	sudo dmesg -C
	sudo insmod main.ko
	lsmod | grep “main” && echo "yes" || echo "no"
	sudo rmmod main
	dmesg
