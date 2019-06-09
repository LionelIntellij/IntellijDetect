
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/include/food/*.h)

include_directories( ${CMAKE_SOURCE_DIR}/include/food
                     ${CMAKE_SOURCE_DIR}/include/interface
					 ${CMAKE_SOURCE_DIR}/include/utils )

add_library(Food SHARED
            ${SOURCES}
            ${HEADERS}
	    ${CMAKE_SOURCE_DIR}/include/interface/ImageWidget.h
	    ${CMAKE_SOURCE_DIR}/include/utils/UtilsInterface.h
	    ${CMAKE_SOURCE_DIR}/include/interface/TableWidget.h )


target_link_libraries(Food 
                      Interface
                      Qt5::Widgets)



