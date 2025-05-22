CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC = src
OBJ = obj
INCLUDE = include
TARGET = program

SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SOURCES))

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(OBJ)/%.o: $(SRC)/%.c
	if not exist $(OBJ) mkdir $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJ)\*.o
	del /Q $(TARGET).exe
