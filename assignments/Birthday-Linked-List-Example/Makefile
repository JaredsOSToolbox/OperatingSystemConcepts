obj-m += someone_example.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test: all
	sudo dmesg -C
	sudo insmod someone_example.ko
	lsmod | grep “someone_example” && echo "yes" || echo "no"
	sudo rmmod someone_example
	dmesg
