IDIR = headers
CC = g++
CFLAGS = -I$(IDIR) -g -Wall -lm -lSDL2main -lSDL2 -lSDL2_image
_DEPS = *.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
SOURCE = $(wildcard src/*.cpp)
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCE))
EXECUTABLE = Bdle

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(EXECUTABLE)
	rm -f src/*.o
