DEBUG=yes
EXEC=pi
CXXFLAGS=--std=c++11 -fopenmp
LDFLAGS=-fopenmp
ifeq (${DEBUG},yes)
	#debug
	CXXFLAGS+=-O0 -g
else
	#release
	CXXFLAGS+=-O2
endif

SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)
ifeq ($(DEBUG),no)
	rm -rf *.o
endif

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)


.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

