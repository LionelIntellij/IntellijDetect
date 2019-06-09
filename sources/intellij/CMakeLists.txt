

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp )
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB EXTERNAL_HEADERS ${CMAKE_SOURCE_DIR}/include/utils/UtilsFilePath.h)

include_directories( ${CMAKE_SOURCE_DIR}/include/interface )
include_directories( ${CMAKE_SOURCE_DIR}/include/person )
include_directories( ${CMAKE_SOURCE_DIR}/include/object )
include_directories( ${CMAKE_SOURCE_DIR}/include/food )
include_directories( ${CMAKE_SOURCE_DIR}/include/settings )
include_directories( ${CMAKE_SOURCE_DIR}/include/utils )

add_executable(IntellijApp ${SOURCES}
                           ${HEADERS}
					${EXTERNAL_HEADERS} )

target_link_libraries(IntellijApp Interface
				  Person 
				  Food
				  Settings 
				  Object)
