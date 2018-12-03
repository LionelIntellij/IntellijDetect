
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(Food ${SOURCES} 
                      ${HEADERS})

target_link_libraries(Food 
                      interface
                      Qt5::Widgets)



