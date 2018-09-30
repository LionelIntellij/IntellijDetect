### minimum version of cmake
set( CMAKE_VERSION 2.8.12.2 )
cmake_minimum_required( VERSION ${CMAKE_VERSION} )
message( "-- Minimum required version of CMake is ${CMAKE_VERSION}" )

### name of the project
set( PROJECT_NAME intellig)
project( ${PROJECT_NAME} )
message( "-- Project name is ${PROJECT_NAME}" )

### Appends the cmake path to MAKE_MODULE_PATH variable.
set( CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
message( "-- CMake module path is ${CMAKE_MODULE_PATH}" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3 -Wall -Wextra -DSQLITE_THREADSAFE=1 -fexceptions" )

#### Add python libraryl
message( "-- Looking for Python package..." )
find_package( PythonLibs 2.6 REQUIRED )

### file(GLOB...) allows for wildcard additions:
file( GLOB SOURCES "zbar/*.c" "zbar/processor/*.c" "zbar/decoder/*.c"
        "zbar/processor/*.c" "zbar/video/*.c" "zbar/qrcode/*.c" "zbar/window/*.c" )
include_directories( ${PROJECT_SOURCE_DIR}/include )

### name of the binary
set( TARGET_NAME DetectZbar)
add_library( ${TARGET_NAME} OBJECT ${SOURCES})



### shared libraries need PIC
set_property( TARGET ${TARGET_NAME} PROPERTY POSITION_INDEPENDENT_CODE 1 )

### Bring the headers
target_include_directories(${TARGET_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/zbar/
                           PRIVATE ${PROJECT_SOURCE_DIR}/zbar/processor/
                           PRIVATE ${PROJECT_SOURCE_DIR}/zbar/video/
                           PRIVATE ${PROJECT_SOURCE_DIR}/zbar/decoder/
                           PRIVATE ${PROJECT_SOURCE_DIR}/zbar/qrcode/)

### Generate the shared library from the sources
set( TARGET_NAME_SHARED ${TARGET_NAME}-shared )
add_library( ${TARGET_NAME_SHARED} SHARED $<TARGET_OBJECTS:${TARGET_NAME}> )
set_target_properties( ${TARGET_NAME_SHARED} PROPERTIES OUTPUT_NAME ${TARGET_NAME} CLEAN_DIRECT_OUTPUT 1 )

### Generate the static library from the sources
set( TARGET_NAME_STATIC ${TARGET_NAME}-static )
add_library( ${TARGET_NAME_STATIC} STATIC $<TARGET_OBJECTS:${TARGET_NAME}> )
set_target_properties( ${TARGET_NAME_STATIC} PROPERTIES OUTPUT_NAME ${TARGET_NAME} CLEAN_DIRECT_OUTPUT 1 )

### Link libraries
set( ALL_LIBARIES ${KLIB} ${PYTHON_LIBRARIES} )
target_link_libraries( ${TARGET_NAME_SHARED} ${ALL_LIBARIES} )
target_link_libraries( ${TARGET_NAME_STATIC} ${ALL_LIBARIES} )
