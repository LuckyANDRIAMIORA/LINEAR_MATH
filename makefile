CC = gcc
FLAG = -Wall -Wextra -O3 -std=c11

INCLUDES = -Iinclude
SRC = src/vector.c
TEST = test/test.c
BUILD = build/vector_test

all: test

test: $(SRC) $(TEST)
	$(CC) $(FLAG) $(INCLUDES) $(SRC) $(TEST) -o $(BUILD)
 
run: $(BUILD)
	clear
	$(BUILD)

clean:
	rm -f $(BUILD)