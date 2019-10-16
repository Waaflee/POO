CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb


BIN		:= bin
OUT		:= out
SRC		:= src
INCLUDE	:= include
LIB		:= lib
TESTS	:= tests

TEST_MAIN := test-main.cpp

LIBRARIES	:=
EXECUTABLE	:= main
EXECTESTS	:= test-main


all: $(BIN)/$(EXECUTABLE)

tests: $(OUT)/$(EXECTESTS)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

test: clean tests
	clear
	./$(OUT)/$(EXECTESTS) -r compact

test-main.o:
	$(CC) $(CFLAGS) -c


# $(BIN)/$(EXECUTABLE): $(SRC)/*.cpp 
$(BIN)/$(EXECUTABLE): 
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

# $(OUT)/$(EXECTESTS): $(TESTS)/*.cpp
$(OUT)/$(EXECTESTS): $(filter-out $(TESTS)/test-Prompt.cpp, $(wildcard $(TESTS)/*.cpp))
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
	# -rm $(OUT)/*
	-rm $(filter-out $(OUT/test-Prompt), $(wildcard $(OUT)/*))
