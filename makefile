GPP=g++
DEBUG_FLAG= -g # can add -g
CFLAGS= --std=c++11 -Wall -Werror -pedantic-errors $(DEBUG_FLAG)
O_FILES_DIR=$(TESTS_DIR)/OFiles

TESTS_INCLUDED_FILE=worldcup23a1.h ./catch.hpp
SOURCES=$(wildcard *.c )
OBJECTS=$(O_FILES_DIR)/$(SOURCES:.c=.o)
EXEC=WorldCupUnitTester

all: $(EXEC)
	./$(EXEC)

$(EXEC): $(OBJECTS)
	$(GPP) $(CFLAGS) $(OBJECTS) -o $(EXEC)

$(OBJECTS): $(SOURCES)
	@mkdir -p $(O_FILES_DIR)
	$(GPP) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(EXEC) $(OBJECTS)