

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h 
                  ${CMAKE_SOURCE_DIR}/include/interface/*.h)
MESSAGE (${CMAKE_SOURCE_DIR}/include/utils/UtilsInterface)
MESSAGE(${HEADERS})

add_library(Interface SHARED ${SOURCES} 
                      ${HEADERS}
                  ${CMAKE_SOURCE_DIR}/include/utils/UtilsInterface.h )
                        

target_link_libraries(Interface
                      Qt5::Widgets)


