CXX ?= c++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic -Iinclude
BUILD_DIR := build
APP := $(BUILD_DIR)/bank_demo
TEST_BIN := $(BUILD_DIR)/bank_account_tests

.PHONY: all test clean

all: $(APP)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(APP): $(BUILD_DIR) src/main.cpp src/BankAccount.cpp include/BankAccount.h
	$(CXX) $(CXXFLAGS) src/main.cpp src/BankAccount.cpp -o $(APP)

$(TEST_BIN): $(BUILD_DIR) tests/test_bank_account.cpp src/BankAccount.cpp include/BankAccount.h
	$(CXX) $(CXXFLAGS) tests/test_bank_account.cpp src/BankAccount.cpp -o $(TEST_BIN)

test: $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -rf $(BUILD_DIR)
