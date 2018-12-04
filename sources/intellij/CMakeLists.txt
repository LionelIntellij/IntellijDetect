

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp )

include_directories( ${CMAKE_SOURCE_DIR}/include/interface )

add_executable(IntellijApp ${SOURCES}) 

target_link_libraries(IntellijApp 
                      Interface)
		      #Object
		      #Picture
		      #Food )
