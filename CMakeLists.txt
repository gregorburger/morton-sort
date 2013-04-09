cmake_minimum_required(VERSION 2.6)
set(CMAKE_AUTOMOC TRUE)
project(morton-sort)

find_package(OpenMP REQUIRED)
find_package(Qt4 REQUIRED QtGui QtCore)
find_package(Boost)
include(${QT_USE_FILE})

add_definitions(-DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_OMP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} -Wall -std=c++0x")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${OpenMP_CXX_FLAGS}")

include_directories(${Boost_INCLUDE_DIR} ${QT_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_UI(UI_SRCS mainwindow.ui)

add_executable(morton-sort main.cpp morton.cpp mainwindow.cpp  ${UI_SRCS})
target_link_libraries(morton-sort ${QT_LIBRARIES})
