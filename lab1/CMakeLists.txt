cmake_minimum_required(VERSION 3.10)
project(taxiManagementSystem)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC")

include_directories(include)

add_library(database SHARED src/database.cpp)
add_library(employee SHARED src/employee.cpp)
add_library(taxi SHARED src/taxi.cpp)

add_executable(taxiManagementSystem src/userInterface.cpp)
target_link_libraries(taxiManagementSystem taxi employee database)