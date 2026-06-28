CC=gcc
CFLAGS=-Wall -g
TARGET=hello
SRC=hello.c

$(TARGET):$(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
.PHONY:clean
clean:
	rm -rf $(TARGET)
