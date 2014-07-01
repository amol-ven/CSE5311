CC = gcc

CFLAGS = -Wall -I./inc/

SRCDIR = ./src

SRC += $(SRCDIR)/treaps.c

TARGET = lab1


	 
all: $(TARGET).c
	 $(CC) $(CFLAGS) $(TARGET).c $(SRC) -o $(TARGET)
	 
run: $(TARGET)
	 ./$(TARGET)

gdb: $(TARGET).c
	 $(CC) $(CFLAGS) -g $(TARGET).c $(SRC) -o $(TARGET)
	 

debug: $(TARGET)
	 gdb ./$(TARGET)
