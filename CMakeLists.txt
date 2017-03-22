cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE Debug)
set(sources main.c
	array.c)
set(headers array.h)
add_executable(array_test 
	${sources}
	${headers})
