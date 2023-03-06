TARGET = test

CC = g++
CFLAGS = -g -fsanitize=address

SRC_DIR = ../Src/

SRC = 	./SquareSolverTest.cpp				\
	  	$(SRC_DIR)Solvers.cpp				\
		$(SRC_DIR)Interactors.cpp

$(TARGET) :
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean :
	rm -f *.o $(TARGET)
