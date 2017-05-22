CC = gcc
CFLAGS = -I
DEPS = Blank.h Center.h Coffee_Shop.h Dr_Seuss.h Harry_Potter.h Map.h Menu.h Player.h Space.h Star_Wars.h
OBJ = Coffee_Shop.o main.o Menu.o Player.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exec_: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
