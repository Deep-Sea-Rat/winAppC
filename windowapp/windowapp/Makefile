# Конфигурация
CC = gcc
RC = windres
CFLAGS = -Wall -Wextra -I utils
RFLAGS = -O coff
LDFLAGS = -mwindows -lgdi32
SRC_DIR = utils
RES_DIR = res
RES = $(RES_DIR)/resource.resource
TARGET = app.exe

# Исходные файлы
APP_SRC = main.c
WIN_SRC = $(SRC_DIR)/winproc.c
WIN_HEADER = $(SRC_DIR)/winproc.h
RC_SRC = $(RES_DIR)/resource.rc

# Объектные файлы
OBJ = $(APP_SRC:.c=.o) $(WIN_SRC:.c=.o) $(RES)

# Правила
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c $(WIN_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(RES): $(RC_SRC)
	$(RC) $(RCFLAGS) $< -o $@

clean:
	del /Q /F $(TARGET) *.o
	del /Q /F $(SRC_DIR)\*.o
	del /Q /F $(RES_DIR)\*.res

.PHONY: all clean