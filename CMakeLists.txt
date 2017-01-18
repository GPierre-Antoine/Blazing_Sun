cmake_minimum_required(VERSION 3.6)
set(PROJECT_NAME Blazing_Sun)

project(${PROJECT_NAME})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Module")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall --pedantic -Wno-comment -Werror")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCE src/*.cpp include/*.h include/*.hpp)

set(SOURCE_FILES main.cpp ${SOURCE})



set(EXECUTABLE_NAME ${PROJECT_NAME})


add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
SET_TARGET_PROPERTIES(Blazing_Sun PROPERTIES LINKER_LANGUAGE CXX)

set(SFML_ROOT C:/lib/SFML-2.3.2)
find_package(SFML 2 REQUIRED audio graphics network window system)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif(SFML_FOUND)