
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(Object ${SOURCES} 
                      ${HEADERS})

target_link_libraries(Object 
                      interface
                      Qt5::Widgets)



