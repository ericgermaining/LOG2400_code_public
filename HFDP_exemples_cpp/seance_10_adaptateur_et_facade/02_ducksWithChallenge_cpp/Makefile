# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -pedantic -std=c++17 -Wall -Wextra -Werror -ggdb3

# Target executable
TARGET_DUCK = DuckTestDrive
TARGET_TURKEY = TurkeyTestDrive

# Source files
SOURCES_DUCK = DuckTestDrive.cpp \
               MallardDuck.cpp WildTurkey.cpp TurkeyAdapter.cpp \
               DroneAdapter.cpp SuperDrone.cpp

SOURCES_TURKEY = TurkeyTestDrive.cpp \
                 MallardDuck.cpp WildTurkey.cpp DuckAdapter.cpp

# Object files
OBJECTS_DUCK = $(SOURCES_DUCK:.cpp=.o)
OBJECTS_TURKEY = $(SOURCES_TURKEY:.cpp=.o)

# Default target
all: $(TARGET_DUCK) $(TARGET_TURKEY)

# Rule to create the target executable
$(TARGET_DUCK): $(OBJECTS_DUCK)
	$(CXX) $(CXXFLAGS) $(OBJECTS_DUCK) -o $(TARGET_DUCK)
$(TARGET_TURKEY): $(OBJECTS_TURKEY)
	$(CXX) $(CXXFLAGS) $(OBJECTS_TURKEY) -o $(TARGET_TURKEY)

# Rule to create object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
.PHONY : clean
clean:
	rm -f $(TARGET_DUCK) $(TARGET_TURKEY) $(OBJECTS_DUCK) $(OBJECTS_TURKEY)
