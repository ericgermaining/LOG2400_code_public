# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -pedantic -std=c++17 -Wall -Wextra -Werror -ggdb3

# Target executable
TARGET = PizzaTestDrive

# Source files
SOURCES = PizzaTestDrive.cpp \
          Pizza.cpp PizzaStore.cpp NYPizzaStore.cpp ChicagoPizzaStore.cpp \
          NYStyleCheesePizza.cpp NYStyleClamPizza.cpp \
          NYStylePepperoniPizza.cpp NYStyleVeggiePizza.cpp \
          ChicagoStyleCheesePizza.cpp ChicagoStyleClamPizza.cpp \
          ChicagoStylePepperoniPizza.cpp ChicagoStyleVeggiePizza.cpp \

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
