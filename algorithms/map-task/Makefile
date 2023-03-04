CC := g++
CFLAGS := -std=c++11 -Wall -pedantic
SOURCES := map.cpp

ifeq (${OS},Windows_NT)
	TARGET := map.exe
	RM := del
else
	TARGET := map
	RM := rm
endif

all:
	$(CC) ${CFLAGS} -o ${TARGET} ${SOURCES}

clean:
	${RM} ${TARGET}

run: all
	(${TARGET} | python graph.py) | (python dict.py | python graph.py)
