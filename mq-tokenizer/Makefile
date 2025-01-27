
CC = gcc
CFLAGS = -Wall -pthread -lrt
TARGET = tokenizer

all: $(TARGET)

$(TARGET): tokenizer.c
	$(CC) $(CFLAGS) -o $(TARGET) tokenizer.c

clean:
	rm -f $(TARGET)
	rm -f /dev/mqueue/token_queue
