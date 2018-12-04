set(CMAKE_VERSION 2.8.12.2)
cmake_minimum_required(VERSION ${CMAKE_VERSION})

set(CMAKE_MODULE_PATH ${PROJET_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})


# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widgets finds its own dependencies.
#find_package(FindQt5.cmake)
#find_package(Qt5Core REQUIRED)
#find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -fexceptions")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/bin)


add_subdirectory(sources/search)
add_subdirectory(sources/person)
add_subdirectory(sources/food)
add_subdirectory(sources/interface)
add_subdirectory(sources/picture)
add_subdirectory(sources/sensor)
add_subdirectory(sources/intellij)



