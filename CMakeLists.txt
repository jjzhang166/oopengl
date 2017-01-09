cmake_minimum_required(VERSION 3.6)
project(x11_opengl)

find_package(X11 REQUIRED)
find_package(opengl REQUIRED)

message(STATUS "*******X11_FOUND******* = ${X11_FOUND}")
message(STATUS "****X11_INCLUDE_DIR**** = ${X11_INCLUDE_DIR}")
message(STATUS "*****X11_LIBRARIES***** = ${X11_LIBRARIES}")
message(STATUS "***X11_LIBRARIES_DIR*** = ${X11_LIBRARY_DIR}")

include_directories(${X11_INCLUDE_DIR})

link_directories(${X11_LIBRARY_DIR})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        XGlWindow.cpp
        MainWindow.cpp
)

set(CMAKE_INCLUDE_CURRENT_DIR  ON)

add_executable(x11_opengl ${SOURCE_FILES})

target_link_libraries(x11_opengl ${X11_LIBRARIES} GL GLU)