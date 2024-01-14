CXX = g++
CXXFLAGS = -Wall -std=c++14 -Iinclude
TARGET = taxiManagementSystem
OBJ = src/userInterface.o libdatabase.a libemployee.a libtaxi.a

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) src/userInterface.o -L. -ldatabase -lemployee -ltaxi

src/userInterface.o: src/userInterface.cpp include/database.h include/employee.h include/taxi.h
	$(CXX) $(CXXFLAGS) -c src/userInterface.cpp -o src/userInterface.o

libdatabase.a: src/database.o
	ar rcs libdatabase.a src/database.o

src/database.o: src/database.cpp include/database.h include/employee.h
	$(CXX) $(CXXFLAGS) -c src/database.cpp -o src/database.o

libemployee.a: src/employee.o
	ar rcs libemployee.a src/employee.o

src/employee.o: src/employee.cpp include/employee.h
	$(CXX) $(CXXFLAGS) -c src/employee.cpp -o src/employee.o

libtaxi.a: src/taxi.o
	ar rcs libtaxi.a src/taxi.o

src/taxi.o: src/taxi.cpp include/taxi.h
	$(CXX) $(CXXFLAGS) -c src/taxi.cpp -o src/taxi.o

clean:
	rm -f $(TARGET) $(OBJ)