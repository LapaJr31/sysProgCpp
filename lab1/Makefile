# Makefile for Taxi Management System without main.cpp

CXX = g++
CXXFLAGS = -Wall -std=c++14
GTEST_FLAGS = -lgtest -lgtest_main -pthread
TARGET = taxiManagementSystem
TEST_TARGET = tests
OBJ = userInterface.o database.o employee.o taxi.o
TEST_OBJ = tests.o database.o employee.o taxi.o

# Linking all object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compiling UserInterface.cpp (contains main())
userInterface.o: userInterface.cpp database.h employee.h taxi.h
	$(CXX) $(CXXFLAGS) -c userInterface.cpp

# Compiling Database.cpp
database.o: database.cpp database.h employee.h
	$(CXX) $(CXXFLAGS) -c database.cpp

# Compiling Employee.cpp
employee.o: employee.cpp employee.h
	$(CXX) $(CXXFLAGS) -c employee.cpp

# Compiling Taxi.cpp
taxi.o: taxi.cpp taxi.h
	$(CXX) $(CXXFLAGS) -c taxi.cpp

# Compiling Tests.cpp
tests.o: tests.cpp database.h employee.h taxi.h
	$(CXX) $(CXXFLAGS) -c tests.cpp

# Linking all object files to create the test executable
$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $(GTEST_FLAGS) -o $(TEST_TARGET) $(TEST_OBJ)

# Run tests
run_tests: $(TEST_TARGET)
	./$(TEST_TARGET)

# Clean up
clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJ) $(TEST_OBJ)

.PHONY: clean run_tests