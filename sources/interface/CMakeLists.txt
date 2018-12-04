

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h) 
#file(GLOB EXTERNAL_HEADERS ${CMAKE_SOURCE_DIR}/include/interface/*.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
	            ${CMAKE_SOURCE_DIR}/include/utils/
	            ${CMAKE_SOURCE_DIR}/include/interface/)

add_library(Interface SHARED ${SOURCES}
	                     ${HEADERS} )
                        

target_link_libraries(Interface
                      Qt5::Widgets)

#target_include_directories(Interface PRIVATE
#                           ${CMAKE_SOURCE_DIR}/include/utils/ )
