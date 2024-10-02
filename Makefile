CC = gcc
CFLAGS = -Iinclude -Wall
SRC = src/main.c src/queue.c
OBJ = $(SRC:.c=.o)
TARGET = task_scheduler

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
