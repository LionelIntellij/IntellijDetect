file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/include/person/*.h)

include_directories(${CMAKE_SOURCE_DIR}/include/person
        ${CMAKE_SOURCE_DIR}/include/interface
        ${CMAKE_SOURCE_DIR}/include/image
        ${CMAKE_SOURCE_DIR}/include/utils)

add_library(Person SHARED
        ${SOURCES}
        ${HEADERS}
        ${CMAKE_SOURCE_DIR}/include/image/InputImage.h
        ${CMAKE_SOURCE_DIR}/include/interface/ImageWidget.h
        ${CMAKE_SOURCE_DIR}/include/utils/UtilsFilePath.h
        ${CMAKE_SOURCE_DIR}/include/interface/TableWidget.h)


target_link_libraries(Person
        Image
        Qt5::Widgets
        Qt5::Core
        opencv_core
        opencv_objdetect
        opencv_imgproc
        opencv_imgcodecs
        opencv_highgui)




