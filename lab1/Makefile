
CXX = g++
CXXFLAGS = -Wall -std=c++14
GTEST_FLAGS = -lgtest -lgtest_main -pthread
TARGET = taxiManagementSystem
TEST_TARGET = tests
OBJ = userInterface.o database.o employee.o taxi.o
TEST_OBJ = tests.o database.o employee.o taxi.o

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

userInterface.o: userInterface.cpp database.h employee.h taxi.h
	$(CXX) $(CXXFLAGS) -c userInterface.cpp

database.o: database.cpp database.h employee.h
	$(CXX) $(CXXFLAGS) -c database.cpp

employee.o: employee.cpp employee.h
	$(CXX) $(CXXFLAGS) -c employee.cpp

taxi.o: taxi.cpp taxi.h
	$(CXX) $(CXXFLAGS) -c taxi.cpp

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJ) $(TEST_OBJ)
