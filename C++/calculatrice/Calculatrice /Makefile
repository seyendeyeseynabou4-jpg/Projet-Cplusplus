CXX = g++

# à décommenter si vous utilisez linux ou clang64 toolchain sous msys2
CXXFLAGS = -Wall -Werror -pedantic -std=c++17 # -g -fsanitize=address
LDFLAGS =  -std=c++17 # -fsanitize=address

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
EXEC = calc run-test-postfix run-test-infix

.PHONY: all
.SUFFIXES: .cpp

all: $(EXEC)

run-test-postfix: run-test-postfix.o rpn.o
	$(CXX) $(LDFLAGS) -o $@ $+ $(LBLIBS)

run-test-infix: run-test-infix.o rpn.o
	$(CXX) $(LDFLAGS) -o $@ $+ $(LBLIBS)

calc: calc.o rpn.o
	$(CXX) $(LDFLAGS) -o $@ $+ $(LBLIBS)

%.o: %.cpp cxxopts.hpp
	$(CXX) -o $@ -c $(CXXFLAGS) $<

clean:
	rm -rf $(OBJ) $(EXEC)