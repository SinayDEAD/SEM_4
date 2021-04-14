COMPILER = g++
COMPILER_FLAGS = -O2 -ftrapv -fsanitize=undefined -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wlogical-op -Wmissing-field-initializers -Wcast-qual -Wwrite-strings -lm
LINK_COMPILER_FLAGS = -fsanitize=undefined -o


sparse: main.o SparseMatrix.o
	$(COMPILER) $^ $(LINK_COMPILER_FLAGS) $@
main.o: main.cpp
	$(COMPILER) $(COMPILER_FLAGS) -c main.cpp
SparseMatrix.o: SparseMatrix.cpp SparseMatrix.h
	$(COMPILER) $(COMPILER_FLAGS) -c SparseMatrix.cpp

sparsef: mainf.o SparseMatrixf.o
	$(COMPILER) -fsanitize=address $^ $(LINK_COMPILER_FLAGS) $@
mainf.o: main.cpp
	$(COMPILER) -fsanitize=address $(LINK_COMPILER_FLAGS) -c main.cpp
SparseMatrixf.o: SparseMatrix.cpp SparseMatrix.h
	$(COMPILER) -fsanitize=address $(LINK_COMPILER_FLAGS) -c SparseMatrix.cpp

clean:
	rm *.o spm*

