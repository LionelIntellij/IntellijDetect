

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(Interface ${SOURCES} 
                      ${HEADERS})

target_link_libraries(Interface
                      Qt5::Widgets)



