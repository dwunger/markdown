# Compiler settings
CC := gcc
CXX := g++
CFLAGS := -Wall -Wextra -std=c11 -I./src -I./include -I./googletest/googletest/include
CXXFLAGS := -Wall -Wextra -std=c++11 -I./src -I./include -I./googletest/googletest/include

# Directories
SRC_DIR := ./src
TEST_DIR := ./test/unit
BUILD_DIR := ./build
OBJ_DIR := $(BUILD_DIR)/obj
BIN_DIR := $(BUILD_DIR)/bin

# Source files (excluding main.c)
SRCS := $(filter-out $(SRC_DIR)/main.c,$(wildcard $(SRC_DIR)/*.c))
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Test files
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SRCS))
TEST_TARGET := $(BIN_DIR)/runTests

# Google Test library
GTEST_VERSION := release-1.11.0
GTEST_URL := https://github.com/google/googletest/archive/$(GTEST_VERSION).tar.gz
GTEST_DIR := ./googletest
GTEST_SRCS := $(GTEST_DIR)/googletest/src/gtest-all.cc
GTEST_OBJS := $(OBJ_DIR)/gtest-all.o

# Targets
.PHONY: all clean test help

all: $(BIN_DIR)/main

$(BIN_DIR)/main: $(OBJS) $(OBJ_DIR)/main.o | $(BIN_DIR)
		$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

test: googletest $(TEST_TARGET)
		$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS) $(OBJS) $(GTEST_OBJS) | $(BIN_DIR)
		$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(GTEST_OBJS): $(GTEST_SRCS)
		$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/googletest -c $(GTEST_SRCS) -o $@

$(GTEST_DIR):
		powershell -Command "Invoke-WebRequest -Uri '$(GTEST_URL)' -OutFile 'gtest.tar.gz'"
		tar -xzf gtest.tar.gz
		powershell -Command "Move-Item -Path googletest-$(GTEST_VERSION) -Destination $(GTEST_DIR)"
		powershell -Command "Remove-Item -Path 'gtest.tar.gz' -Force"

googletest: $(GTEST_DIR)

$(OBJ_DIR):
		powershell -Command "New-Item -ItemType Directory -Force -Path $@"

$(BIN_DIR):
		powershell -Command "New-Item -ItemType Directory -Force -Path $@"

clean:
		powershell -Command "Remove-Item -Recurse -Force $(BUILD_DIR)"
		powershell -Command "Remove-Item -Recurse -Force $(GTEST_DIR)"

help:
		@echo "Available targets:"
		@echo "  all		  - Build the main executable"
		@echo "  test		 - Build and run the unit tests"
		@echo "  clean		- Clean the build artifacts and Google Test library"
		@echo "  help		 - Display this help message"
