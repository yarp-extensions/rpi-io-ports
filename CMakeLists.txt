cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(rpi-io-ports CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# place binaries and libraries according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

set(BOOST_COMPONENTS)
list(APPEND BOOST_COMPONENTS thread
        date_time
        filesystem
        system
        chrono
        program_options
        unit_test_framework
        locale)

find_package(Boost 1.60 REQUIRED COMPONENTS ${BOOST_COMPONENTS})
set( Boost_USE_STATIC_LIBS ON CACHE STRING "ON or OFF" )


message( STATUS "Configuring Raspberry pi ports on Linux" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -pthread -fprofile-arcs -ftest-coverage" )

# we use this to get code coverage
#if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
 #   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
#endif()

add_executable(rpi-io-ports
        main.cpp
        inc/RaspberryPiPorts.h
        src/RaspberryPiPorts.cpp
        )
target_include_directories( rpi-io-ports PUBLIC /usr/local/include/appbase)

target_link_libraries( rpi-io-ports ${Boost_LIBRARIES} appbase)


include(cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_BINARY_DIR}/googletest
)

enable_testing()
add_subdirectory(test)