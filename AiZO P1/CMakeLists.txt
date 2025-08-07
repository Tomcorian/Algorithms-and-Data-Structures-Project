cmake_minimum_required(VERSION 3.10)
project(AiZO P1)

set(CMAKE_CXX_STANDARD 11)

add_executable(AiZO P1
	main.cpp
	Menu.cpp
	HeapSort.cpp
	Benchmark.cpp
	FileTest.cpp
	FileHandler.cpp
	Timer.cpp
)