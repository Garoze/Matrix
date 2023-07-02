# _*_ MakeFile _*_

CC     := gcc
CFLAGS := -w -g -Wall

SRC    := src
BIN    := bin
BUILD  := build

SOURCES  := $(shell find $(SRC/**) -type f -regex ".*\.c")
HEADERS  := $(shell find $(SRC/include/**) -type f -regex ".*\.h")
OBJECTS  := $(patsubst %, $(BUILD)/%, $(notdir $(SOURCES:.c=.c.o)))

.PHONY: default config all clean

TARGET := matrix

all: $(TARGET)

$(BUILD)/%.c.o: $(SRC)/%.c $(HEADERS)
	@echo "Building: $@"; $(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(TARGET): $(OBJECTS)
	@echo "Linking: $@"; $(CC) $^ -o $(TARGET) $(LIB)

config: $(eval SHELL:=/usr/bin/env bash)
	@echo $(shell ./configure.sh)

clean:
	@echo "Cleaning $(TARGET), $(BUILD)"; $(RM) -rf $(OBJECTS) $(TARGET)
