CXX = g++
CXXFLAGS =-std=c++17 -Wall 
SRC = brouillon1.cpp test.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = test

all: $(EXEC)	

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean: 
	rm -f $(OBJ) $(EXEC)



