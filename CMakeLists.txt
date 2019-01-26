set(CMAKE_VERSION 2.8.12.2)
cmake_minimum_required(VERSION ${CMAKE_VERSION})

set(CMAKE_MODULE_PATH ${PROJET_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
set(EXTERNAL_PATH $ENV{EXTERNAL_PATH})

project(Intellij)
# Tell CMake to run moc when necessary:

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia)
find_package(Qt5MultimediaWidgets)
find_package(Qt5OpenGL)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -fexceptions")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/bin)


include_directories(${EXTERNAL_PATH}/opencv/include/opencv4)
link_directories(${EXTERNAL_PATH}/opencv/lib)
include_directories(${EXTERNAL_PATH}/caffe/include)
link_directories(${EXTERNAL_PATH}/caffe/lib)




add_subdirectory(sources/person)
add_subdirectory(sources/food)
add_subdirectory(sources/settings)
add_subdirectory(sources/object)
add_subdirectory(sources/interface)
add_subdirectory(sources/intellij)



