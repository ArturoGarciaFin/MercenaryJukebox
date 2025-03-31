CC = gcc

TARGET = jukebox
SRCS = main.c jukebox_queue.c request.c

all:
	$(CC) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET) *.txt
