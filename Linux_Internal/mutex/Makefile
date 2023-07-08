obj-m += driver.o
 
KDIR = /home/g07/Module3: Linux Internal/Program/mutex/$(shell uname -r)/g
 
 
all:
	make -C $(KDIR) M=$(shell pwd) modules
 
clean:
	make -C $(KDIR) M=$(shell pwd) clean
