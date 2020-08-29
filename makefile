EXE = bin/LinkedListTest
CC = g++
OPTIONS = -std=c++11
DEBUG = -g
MEMCHECK = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

all:$(EXE)
.PHONY: all run test memcheck clean

run:$(EXE)
	@echo "Press enter to run the test driver"
	@read DUMMY
	$(EXE)
	@echo "Press enter to memcheck the test driver"
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
	rmdir obj
	rmdir bin

$(EXE):obj/LinkedListTest.o obj/MemberDO.o
	mkdir -p bin
	$(CC) $(OPTIONS) $(DEBUG) -o $(EXE) obj/LinkedListTest.o obj/MemberDO.o

obj/LinkedListTest.o:src/LinkedListTest.cpp inc/LinkedList.h inc/MemberDO.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/LinkedListTest.o -c  -I inc/ src/LinkedListTest.cpp

obj/MemberDO.o:src/MemberDO.cpp inc/MemberDO.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/MemberDO.o -c  -I inc/ src/MemberDO.cpp
