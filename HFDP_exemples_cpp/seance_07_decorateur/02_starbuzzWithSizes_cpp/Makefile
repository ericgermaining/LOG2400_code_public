# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -pedantic -std=c++17 -Wall -Wextra -Werror -ggdb3

# Target executable
TARGET = StarbuzzCoffee

# Source files
SOURCES = StarbuzzCoffee.cpp \
          DarkRoast.cpp Decaf.cpp Espresso.cpp HouseBlend.cpp \
          Milk.cpp Mocha.cpp Soy.cpp Whip.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to create the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Rule to create object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
.PHONY : clean
clean:
	rm -f $(TARGET) $(OBJECTS)
