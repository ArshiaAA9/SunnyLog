cmake_minimum_required(VERSION 3.16)
project(SunnyLog VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # Critical for clangd

set(LIB_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS "${LIB_SOURCE_DIR}/*.cpp")

add_library(SunnyLog STATIC ${LIB_SOURCES})

target_include_directories(SunnyLog PUBLIC 
    $<BUILD_INTERFACE:${LIB_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

#target_compile_options(SunnyLog PRIVATE -Wall -Wextra)

#install(EXPORT SunnyLogTargets 
#    FILE SunnyEngine.cmake 
#    NAMESPACE SunnyLog:: 
#    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/SunnyLog
#)



#---------------test
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "${LIB_SOURCE_DIR}/*.cpp")

add_executable(test ${TEST_SOURCES})

target_include_directories(
    test PRIVATE
    ${TEST_SOURCES}

)

target_link_libraries(
    test PRIVATE
    SunnyLog
)
