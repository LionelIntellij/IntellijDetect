set(CMAKE_VERSION 2.8.12.2)
cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(IntelligDetect)

set(CMAKE_MODULE_PATH ${PROJET_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widgets finds its own dependencies.
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

qt5_wrap_ui(UI_FILES MainWindow.ui)

add_executable(IntelligDetect
    ${UI_FILES}
    MainWindow.cpp
    MainWindow.h
    QCircularBar.h
    QCircularBar.cpp
    main.cpp)

target_link_libraries(IntelligDetect
    Qt5::Widgets
    Qt5::Gui
    Qt5::Core)





