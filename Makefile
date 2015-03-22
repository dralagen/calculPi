MPICXX=mpic++
DEBUG=no
CXXFLAGS=--std=c++11 -fopenmp
ifeq (${DEBUG},yes)
	#debug
	CXXFLAGS+=-O0 -g
else
	#release
	CXXFLAGS+=-O2
endif

COMMON_SOURCES=
COMMON_OBJECTS= $(COMMON_SOURCES:.cpp=.o)

all: pi pi-mpi

pi: calculPi.cpp $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $< $(COMMON_OBJECTS)

pi-mpi: calculPi_mpi.cpp $(COMMON_OBJECTS)
	$(MPICXX) $(CXXFLAGS) -o $@ $< $(COMMON_OBJECTS)


.PHONY: clean mrproper

clean:
	-rm pi pi-mpi $(COMMON_OBJECTS)

