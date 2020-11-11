CFLAGS=-I. -g -O2
DEPS =  gpio_hal.h trigger.h  
OBJ = gpio_hal.o main.o trigger.o

%.o: %.c %.h $(DEPS) Makefile
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ) test
