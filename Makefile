MEMGRIND: memgrind
OBJECTS: mymalloc.o memgrind.o
FLAGS: -Wall -Werror -fsanitize=address

$(MEMGRIND): $(OBJECTS)
	gcc $(FLAGS) -o $(TARGET)
memgrind.o: memgrind.c mymalloc.h
	gcc $(FLAGS) -c memgrind.c
mymalloc.o: mymalloc.c mymalloc.h
	gcc $(FLAGS) -c mymalloc.c
clean:
	rm -f $(MEMGRIND) $(OBJECTS)
