CC = gcc
OFILES = main.o sprite.o
CFLAGS = -lSDL2
LDFLAGS = 

all: $(OFILES)
	$(CC) $(OFILES) -o game $(CFLAGS)

clean:
	$(RM) *.o