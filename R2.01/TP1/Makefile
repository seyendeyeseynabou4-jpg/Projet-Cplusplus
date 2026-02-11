# CXX = g++
# CXXFLAGS = -Wall -std=c++11

# EXEC = calculatrice.exe
# SRC = Polynome.cpp calculatrice.cpp
# OBJ = $(SRC:.cpp=.o)

# all: $(EXEC)

# $(EXEC): $(OBJ)
# 	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@
# clean:
# 	rm -f $(OBJ) $(EXEC)


CXX = g++
CXXFLAGS = -g -Wall -O0
LIBS = -lXext -lX11 #sous Linux
# LIBS = -lgdi32  Pour windows
EXEC=Polynome.exe

$(EXEC): Polynome.o calculatrice.o 
	$(CXX) -o $@ $^ $(LIBS)
Polynome.o: Polynome.cpp Polynome.hpp 
	$(CXX) $(CXXFLAGS) -c $<

calculatrice.o : calculatrice.cpp Polynome.hpp 
	$(CXX) $(CXXFLAGS) -c $<

clean: 
	rm -f *o $(EXEC)