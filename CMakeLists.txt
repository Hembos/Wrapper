cmake_minimum_required(VERSION 3.8)

project(Wrapper)

set(SOURCES
        Main.cpp
)

set(HEADERS
        Wrapper.h
		Engine.h
		SomeClass.h
)

add_executable(wrapper ${SOURCES} ${HEADERS})

set_target_properties(
    wrapper PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)