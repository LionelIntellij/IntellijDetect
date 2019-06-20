file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/include/image/*.h)

include_directories(${CMAKE_SOURCE_DIR}/include/image
        ${CMAKE_SOURCE_DIR}/include/utils)

add_library(Image SHARED
        ${SOURCES}
        ${HEADERS})


target_link_libraries(Image
        Qt5::Widgets
        Qt5::Core
        opencv_core
        opencv_objdetect
        opencv_imgproc
#        opencv_imgcodecs
        opencv_highgui)

