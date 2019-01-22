


file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(Person SHARED
                   ${SOURCES}
                   ${HEADERS})

target_link_libraries(Person
                      opencv_core
                      opencv_objdetect
                      opencv_imgproc
                      opencv_imgcodecs
                      opencv_highgui)




