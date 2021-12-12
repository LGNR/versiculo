cmake_minimum_required(VERSION 3.18)

project(versiculo)
include_directories(rapidxml/)

set(SOURCES main.cpp rapidxml/rapidxml.hpp rapidxml/rapidxml_print.hpp)

add_executable(versiculo ${SOURCES})
target_compile_options(versiculo PRIVATE -Wall)
