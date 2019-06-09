set(CMAKE_VERSION 3.4)
cmake_minimum_required(VERSION ${CMAKE_VERSION})

set(CMAKE_MODULE_PATH ${PROJET_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
set(EXTERNAL_PATH $ENV{EXTERNAL_PATH})


project(Intellij)
# Tell CMake to run moc when necessary:

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5MultimediaWidgets REQUIRED)

include_directories(${EXTERNAL_PATH}/opencv/include/opencv4)
link_directories(${EXTERNAL_PATH}/opencv/lib)


set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -fPIC -Wextra -fexceptions")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/bin)


add_subdirectory(sources/image)
add_subdirectory(sources/person)
add_subdirectory(sources/food)
add_subdirectory(sources/settings)
add_subdirectory(sources/object)
add_subdirectory(sources/interface)
add_subdirectory(sources/intellij)



