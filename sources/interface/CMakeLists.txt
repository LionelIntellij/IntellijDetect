file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/include/interface/*.h)
file(GLOB EXTERNAL_HEADERS ${CMAKE_SOURCE_DIR}/include/utils/*.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
	            	${CMAKE_SOURCE_DIR}/include/utils
	            	${CMAKE_SOURCE_DIR}/include/interface
		    		${CMAKE_SOURCE_DIR}/include/food
		    		${CMAKE_SOURCE_DIR}/include/object
		    		${CMAKE_SOURCE_DIR}/include/person )


add_library(Interface SHARED ${SOURCES} 
                             ${HEADERS}
                             ${EXTERNAL_HEADERS})



target_link_libraries(Interface Qt5::Multimedia
		      		Qt5::MultimediaWidgets
				Qt5::Widgets
				Qt5::Core
                	      	Qt5::Gui)

