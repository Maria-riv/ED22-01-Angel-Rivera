cmake_minimum_required(VERSION 3.0.0)
project(TallerConteoPersonas VERSION 0.1.0)

include(CTest)
enable_testing()

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

include_directories("src")

add_executable(TallerConteoPersonas src/main.cpp src/logic/LinkedList.cpp src/logic/Persona.cpp src/logic/Nodo.cpp src/logic/CentroidTracker.cpp)

target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
