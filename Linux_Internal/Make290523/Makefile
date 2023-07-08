#compiler
CC = gcc

#compiler Flags
CFLAG = -c -g

#Output-flag
OFLAG = -o

App:App.o print.o add.o header.h
	#gcc App.o add.o print.o -o App
	$(CC) $^ $(OFLAG) $@
	@echo "Application Binary Generated"

App.o:App.c
	@echo "App.o Binary Generated"
	#gcc -c App.c -o App.o
	$(CC) $^ $(CFLAG) $(OFLAG) $@

add.o:add.c
	@echo "add.o Binary Generated"
	#gcc -c add.c -o add.o
	$(CC) $^ $(CFLAG) $@

print.o:print.c
	@echo "print.o Binary Generated"
	#gcc -c print.c -o print.o
	$(CC) $^ $(CFLAG) $@

clean:
	rm -rf *.o App
