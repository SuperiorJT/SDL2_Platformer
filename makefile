CC = gcc -std=c99
OFILES = main.o sprite.o Block.o Collision.o numbers.o Player.o
CFLAGS = -lSDL2
LDFLAGS = 

all: $(OFILES)
	$(CC) $(OFILES) -o game $(CFLAGS)

clean:
	$(RM) *.o