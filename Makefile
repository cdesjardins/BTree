CC=g++
CFLAGS=-c -Wall -g 
LDFLAGS=
SOURCES= main.cpp
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=treenode


all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o $(EXECUTABLE)
