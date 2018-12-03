

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(Detection ${SOURCES} 
                      ${HEADERS})

target_link_libraries(Detection 
                      interface
                      Qt5::Widgets)




