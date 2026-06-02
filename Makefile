CC = gcc
CFLAGS = -Iinclude
SRC = src/*.c
TARGET = programa

all: 
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	del $(TARGET).exe