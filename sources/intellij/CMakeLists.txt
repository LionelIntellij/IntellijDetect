

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp )
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
include_directories( ${CMAKE_SOURCE_DIR}/include/interface )

add_executable(IntellijApp ${SOURCES}
                           ${HEADERS}) 

target_link_libraries(IntellijApp
                      Interface)
		      #Object
		      #Picture
		      #Food )
