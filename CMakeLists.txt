cmake_minimum_required(VERSION 3.0.0)
project(ED22-01-Angel-Rivera VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(ED22-01-Angel-Rivera src/main.cpp)
include_directories(src)

target_link_libraries(ED22-01-Angel-Rivera ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
