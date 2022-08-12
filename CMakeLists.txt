cmake_minimum_required (VERSION 3.10)

project (AStar)

SET(CMAKE_CXX_COMPILER "/usr/bin/g++")

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set( SRC_LIST
	 ${PROJECT_SOURCE_DIR}/src/AStar.cpp
	 ${PROJECT_SOURCE_DIR}/src/main.cpp
	 ${PROJECT_SOURCE_DIR}/src/Map.cpp)

add_executable(AStar ${SRC_LIST})