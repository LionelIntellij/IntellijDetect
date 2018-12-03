

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp )
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h )

add_executable(IntellijApp ${SOURCES} 
                           ${HEADERS})

target_link_libraries(IntellijApp 
                      Detection
                      Parameter
                      Interface
                      Object
                      Picture
                      Food )
