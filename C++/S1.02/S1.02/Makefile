
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Ofast
SRC = benchmark.cpp creattab.cpp quicksort_det.cpp quicksort_rand.cpp sortinsertion.cpp stablesort.cpp trie_selection.cpp trie_sort.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = test

all: $(EXEC)	

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ) $(EXEC)
