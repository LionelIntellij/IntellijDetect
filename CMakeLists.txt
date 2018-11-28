set(CMAKE_VERSION 2.8.12.2)
cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(IntellijDetect)

set(CMAKE_MODULE_PATH ${PROJET_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})


# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


# Widgets finds its own dependencies.
#find_package(FindQt5.cmake)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
file(GLOB SOURCES "main.cpp"
                  "interface/*.cpp"
                  "object/*.cpp"
                  "food/*.cpp"
                  "sensor/*.cpp"
                  "utils/*.cpp"
                  "person/*.cpp"
                  "parameters/*.cpp"
                  "detection/*.cpp"
		  "picture/*.cpp"
    )

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -fexceptions")



add_executable(IntellijDetect ${UI_FILES}
                              ${SOURCES})


target_include_directories(IntellijDetect PRIVATE
	            ${PROJECT_SOURCE_DIR}/interface
                    ${PROJECT_SOURCE_DIR}/parameters
                    ${PROJECT_SOURCE_DIR}/object
                    ${PROJECT_SOURCE_DIR}/utils
                    ${PROJECT_SOURCE_DIR}/person
                    ${PROJECT_SOURCE_DIR}/food
                    ${PROJECT_SOURCE_DIR}/sensor
                    ${PROJECT_SOURCE_DIR}/detection
                    ${PROJECT_SOURCE_DIR}/picture
		    )

target_link_libraries(IntellijDetect
	Qt5::Widgets
	Qt5::Gui
	Qt5::Core)
