cmake_minimum_required(VERSION 3.6)

if(NOT DEFINED PROJECT_NAME)
  set(PROJECT_NAME "DifferentNumbers")
endif()

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(BINARY ${CMAKE_PROJECT_NAME})
set(LIBRARY_NAME ${BINARY}_lib)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.cpp)
file(GLOB_RECURSE HEADERS LIST_DIRECTORIES true *.h)

# Exclude the main file from the library sources
list(FILTER SOURCES EXCLUDE REGEX ".*differentnumbers_main.cpp$")

add_library(${LIBRARY_NAME} STATIC ${SOURCES} ${HEADERS})

# Define the executable
add_executable(${BINARY} differentnumbers_main.cpp)

# Link the library with the executable
target_link_libraries(${BINARY} ${LIBRARY_NAME})