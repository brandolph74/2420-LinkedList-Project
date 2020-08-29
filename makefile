EXE = bin/test_driver
CC = g++
OPTIONS = -std=c++11
DEBUG = -g
MEMCHECK = valgrind --tool=memcheck

all:$(EXE)
.PHONY: all run test memcheck clean

run:$(EXE)
	@echo "Press enter to run test driver"
	@read DUMMY
	@-$(EXE)
	@echo "Press enter to run memcheck"
	@read DUMMY
	$(MEMCHECK) $(EXE)

test: $(EXE)
	$(EXE)

memcheck: $(EXE)
	$(MEMCHECK) $(EXE)

clean:
	mkdir -p obj
	mkdir -p bin
	rm obj/*
	rm bin/*

$(EXE):obj/DynamicStringTest.o obj/DynamicString.o
	mkdir -p bin
	$(CC) $(OPTIONS) $(DEBUG) -o $(EXE) obj/DynamicStringTest.o obj/DynamicString.o

obj/DynamicStringTest.o:src/DynamicStringTest.cpp inc/DynamicString.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/DynamicStringTest.o -c  -I inc/ src/DynamicStringTest.cpp

obj/DynamicString.o:src/DynamicString.cpp inc/DynamicString.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/DynamicString.o -c  -I inc/ src/DynamicString.cpp
