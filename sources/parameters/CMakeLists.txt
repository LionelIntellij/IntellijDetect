

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(Parameter ${SOURCES} 
                      ${HEADERS})

target_link_libraries(Parameter 
                      interface
                      Qt5::Widgets)



