set(CMAKE_VERSION 2.8.12.2)
cmake_minimum_required(VERSION ${CMAKE_VERSION})
message("-- Minimum required version of CMake is ${CMAKE_VERSION}")

### name of the project
set(PROJECT_NAME openbarcode-bin)
project(${PROJECT_NAME})
message("-- Project name is ${PROJECT_NAME}")

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
message("-- CMake module path is ${CMAKE_MODULE_PATH}")

file( GLOB SOURCES "barcode/*.cpp")

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -DSQLITE_THREADSAFE=1 -fexceptions")
### External library KListupDBHandler, add GLOBAL if the imported library is located in directories above the current.


link_directories(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}  PRIVATE ${PROJECT_SOURCE_DIR}/barcode/ PUBLIC ${PROJECT_SOURCE_DIR}/opencv4/)

target_link_libraries(${PROJECT_NAME} opencv_core opencv_imgproc opencv_imgcodecs)

install(TARGETS ${TARGET_NAME} DESTINATION ${PROJECT_SOURCE_DIR}/bin)
#### Generate the shared library from the sources
#set( TARGET_NAME_SHARED ${TARGET_NAME}-shared )
#add_library( ${TARGET_NAME_SHARED} SHARED $<TARGET_OBJECTS:${TARGET_NAME}> )
#set_target_properties( ${TARGET_NAME_SHARED} PROPERTIES OUTPUT_NAME ${TARGET_NAME} CLEAN_DIRECT_OUTPUT 1 )
#
#### Generate the static library from the sources
#set( TARGET_NAME_STATIC ${TARGET_NAME}-static )
#add_library( ${TARGET_NAME_STATIC} STATIC $<TARGET_OBJECTS:${TARGET_NAME}> )
#set_target_properties( ${TARGET_NAME_STATIC} PROPERTIES OUTPUT_NAME ${TARGET_NAME} CLEAN_DIRECT_OUTPUT 1 )
#
#### Link libraries
#set( ALL_LIBARIES ${KLIB} ${PYTHON_LIBRARIES} )
#target_link_libraries( ${TARGET_NAME_SHARED} ${ALL_LIBARIES} )
#target_link_libraries( ${TARGET_NAME_STATIC} ${ALL_LIBARIES} )
