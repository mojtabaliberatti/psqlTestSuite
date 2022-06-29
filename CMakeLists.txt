cmake_minimum_required(VERSION 3.15)

project("Liberatii Test Suite V.1.0.0")

PROJECT(C CXX)

add_subdirectory(src)

set(LBR_SRC ${CMAKE_CURRENT_LIST_DIR})



message("=============================================")
message("System     : ${CMAKE_SYSTEM}(${CMAKE_HOST_SYSTEM_VERSION}/${CMAKE_HOST_SYSTEM_PROCESSOR})")
message("CMake      : ${CMAKE_VERSION}")
message("Generator  : ${CMAKE_GENERATOR}")
message("Compiler   : ${CMAKE_CXX_COMPILER_ID} v${CMAKE_CXX_COMPILER_VERSION}")
