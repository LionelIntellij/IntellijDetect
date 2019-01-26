

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/include/settings/*.h)


include_directories( ${CMAKE_SOURCE_DIR}/include/settings
                     ${CMAKE_SOURCE_DIR}/include/interface
		     ${CMAKE_SOURCE_DIR}/include/utils )	

	     
	     
add_library(Settings SHARED
            ${SOURCES}
            ${HEADERS}
	    ${CMAKE_SOURCE_DIR}/include/interface/PictureWidget.h
	    ${CMAKE_SOURCE_DIR}/include/utils/UtilsInterface.h
	    ${CMAKE_SOURCE_DIR}/include/interface/TableWidget.h )


target_link_libraries(Settings 
                      Interface
                      Qt5::Widgets)


