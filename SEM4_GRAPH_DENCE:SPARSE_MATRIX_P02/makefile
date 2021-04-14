COMPILER = g++
COMPILER_FLAGS = -O2 -ftrapv -fsanitize=undefined -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wlogical-op -Wmissing-field-initializers -Wcast-qual -Wwrite-strings -lm
LINK = -fsanitize=undefined -o


main: main.o SparseMatrix.o IterableDenseMatrix.o IterableSparseMatrix.o Matrix.o
	$(COMPILER) $^ $(LINK) $@

main.o: main.cpp
	$(COMPILER) $(COMPILER_FLAGS) -c main.cpp

SparseMatrix.o: SparseMatrix.cpp SparseMatrix.hpp
	$(COMPILER) $(COMPILER_FLAGS) -c SparseMatrix.cpp

IterableDenseMatrix.o: IterableDenseMatrix.cpp IterableDenseMatrix.hpp
	$(COMPILER) $(COMPILER_FLAGS) -c IterableDenseMatrix.cpp

IterableSparseMatrix.o: IterableSparseMatrix.cpp IterableSparseMatrix.hpp
	$(COMPILER) $(COMPILER_FLAGS) -c IterableSparseMatrix.cpp

Matrix.o: Matrix.cpp Matrix.hpp
	$(COMPILER) $(COMPILER_FLAGS) -c Matrix.cpp

IterableSquareMatrix.o: IterableSquareMatrix.cpp IterableSquareMatrix.hpp
	$(COMPILER) $(COMPILER_FLAGS) -c IterableSquareMatrix.cpp

clear_gch:
	rm *.gch
	rm main

clear_o:
	rm *.o
	rm main
