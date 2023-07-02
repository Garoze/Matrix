# _*_ MakeFile _*_

CC     := gcc
CFLAGS := -w -g -Wall

SRC    := src
BIN    := bin
BUILD  := build

SOURCE  := $(shell find $(SRC/**) -type f -regex ".*\.c")
HEADERS := $(shell find $(SRC/include/**) -type f -regex ".*\.h")
OBJECT  := $(patsubst %, $(BUILD)/%, $(notdir $(SOURCE:.c=.c.o)))

.PHONY: default config all clean

TARGET := matrix

all: $(TARGET)

$(BUILD)/%.c.o: $(SRC)/%.c $(HEADERS)
	@echo "Building: $@"; $(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(TARGET): $(OBJECT)
	@echo "Linking: $@"; $(CC) $^ -o $(TARGET) $(LIB)

config: $(eval SHELL:=/usr/bin/env bash)
	@echo $(shell ./configure.sh)

clean:
	@echo "Cleaning $(TARGET), $(BUILD)"; $(RM) -rf $(OBJECT) $(TARGET)
