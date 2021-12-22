CXX=g++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES = mh

all: ${BINARIES}

mh: main.o
	${CXX} $^ -o MonteHallSim

clean:
	/bin/rm -f ${BINARIES} *.o *.out
