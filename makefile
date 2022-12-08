  # the compiler: gcc for C program, define as g++ for C++
  CC = gcc

  # compiler flags:
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -Wall

  # the build target executable:
  TARGET = connections

  # objects
  OBJ = main.o my_mat.o 

  all: $(TARGET)

  $(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

  main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c  main.c

  my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c  my_mat.c

.PHONY: clean all

  clean:
	rm -f *.o *.a $(TARGET)