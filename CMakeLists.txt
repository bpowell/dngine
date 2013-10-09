CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
PROJECT (dngine)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")

#Commented out for SDL2 switch.
##Need to fix to look for SDL2 libs
#FIND_PACKAGE(SDL2 REQUIRED)
#FIND_PACKAGE(SDL2_image REQUIRED)
#
#IF(NOT SDL2_FOUND)
#	MESSAGE(FATAL ERROR "SDL Not Found")
#ENDIF(NOT SDL2_FOUND)
SET(SDL_LIBS SDL2 SDL2_image boost_system)

SET(DNGINE_SOURCE_DIR ${dngine_SOURCE_DIR}/src)
SET(DNGINE_RELEASE_DIR ${dngine_SOURCE_DIR}/release)
SET(DNGINE_HEADERS_DIR ${DNGINE_SOURCE_DIR}/include)
SET(CMAKE_INSTALL_PREFIX ${DNGINE_RELEASE_DIR})
FILE(GLOB HEADERS ${DNGINE_HEADERS_DIR}/*.h)

INCLUDE_DIRECTORIES(${DNGINE_HEADERS_DIR} /usr/local/lib/SDL2) #/usr/local/lib/SDL2 is where checkinstall puts includes
FILE(GLOB DNGINE_SRC ${DNGINE_SOURCE_DIR}/*.cpp)
ADD_LIBRARY(dngine ${DNGINE_SRC})

#Added "/usr/local/lib" to /etc/ld.so.conf
##Ran sudo ldconfig
##Used to static link to SDL2 libs
ADD_EXECUTABLE(test_sprite test/sprite)
TARGET_LINK_LIBRARIES(test_sprite dngine ${SDL_LIBS})
ADD_EXECUTABLE(test_screen test/screen)
TARGET_LINK_LIBRARIES(test_screen dngine ${SDL_LIBS})
ADD_EXECUTABLE(test_game test/game)
TARGET_LINK_LIBRARIES(test_game dngine ${SDL_LIBS})
ADD_EXECUTABLE(test_map test/map)
TARGET_LINK_LIBRARIES(test_map dngine ${SDL_LIBS})
ADD_EXECUTABLE(test_spritesheet test/spritesheet)
TARGET_LINK_LIBRARIES(test_spritesheet dngine ${SDL_LIBS})

SET(TEST_EXE
	${dngine_BINARY_DIR}/test_sprite
	${dngine_BINARY_DIR}/test_screen
	${dngine_BINARY_DIR}/test_game
	${dngine_BINARY_DIR}/test_map
)

INSTALL(FILES ${HEADERS} DESTINATION include)
INSTALL(FILES ${TEST_EXE} DESTINATION test)
INSTALL(TARGETS dngine 
	ARCHIVE DESTINATION lib
)
