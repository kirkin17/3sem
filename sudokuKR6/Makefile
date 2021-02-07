CC=g++
CFLAGS=-c -g -Wall -O3 -pthread
LDFLAGS=
SOURCES=main.cpp Generator.cpp Solver.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lncursesw

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o