cmake_minimum_required(VERSION 3.16)
project(T)

set(CMAKE_CXX_STANDARD 17)

add_executable(T src/main.cpp)
target_link_libraries(T ${OpenCV_LIBS})

set(OpenCV_DIR "$ENV{HOME}/package/opencv_4.12.0/install/lib/cmake/opencv4")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
