# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -pedantic -std=c++17 -Wall -Wextra -Werror -ggdb3

# Target executable
TARGET = PizzaTestDrive

# Source files
SOURCES = BlackOlives.cpp ClamPizza.cpp Garlic.cpp NYPizzaIngredientFactory.cpp PizzaTestDrive.cpp \
          SlicedPepperoni.cpp VeggiePizza.cpp CheesePizza.cpp Eggplant.cpp MarinaraSauce.cpp NYPizzaStore.cpp \
          PepperoniPizza.cpp PlumTomatoSauce.cpp Spinach.cpp ChicagoPizzaIngredientFactory.cpp FreshClams.cpp \
          MozzarellaCheese.cpp Onion.cpp Pizza.cpp RedPepper.cpp ThickCrustDough.cpp ChicagoPizzaStore.cpp \
          FrozenClams.cpp Mushroom.cpp ParmesanCheese.cpp PizzaStore.cpp ReggianoCheese.cpp ThinCrustDough.cpp

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
