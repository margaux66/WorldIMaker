cmake_minimum_required(VERSION 3.0)

project(WorldIMaker)

add_definitions(-std=c++11)

#put the binary files in this directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../build/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#OpenGL
message("Looking for OpenGL...")
find_package(OpenGL REQUIRED)
if(${OpenGL_FOUND})
    message(STATUS "lib OpenGL found")
    message(STATUS "  version " ${OpenGL_VERSION_STRING})
    message(STATUS "  include " ${OpenGL_INCLUDE_DIRS})
endif()

#GLEW
message("Looking for GLEW...")
find_package(GLEW REQUIRED)
if(${GLEW_FOUND})
    message(STATUS "lib GLEW found")
    message(STATUS "  version " ${GLEW_VERSION_STRING})
    message(STATUS "  include " ${GLEW_LIBRARY})
endif()

#SDL2
message("Looking for SDL2...")
find_package(SDL2 REQUIRED)
if(${SDL2_FOUND})
    message(STATUS "lib SDL2 found")
    message(STATUS "  include " ${SDL2_INCLUDE_DIRS})
endif()

if (APPLE)
    include_directories(/usr/local/include)
    set(GLEW_LIBRARY /usr/local/lib/libGLEW.dylib)
endif (APPLE)

#compilation flags 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2 -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG_init "-g")

include_directories(${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} lib/glimac/include lib/third-party/include)

set(ALL_LIBRARIES ${SDL2_LIBRARIES} glimac ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})

# Add the glimac library
add_subdirectory(lib/glimac)

# Add the third-party library
#add_subdirectory(lib/third-party)

add_subdirectory(doc)

# file(GLOB_RECURSE HEADER_FILES src/include/*) # get all headers
file(GLOB_RECURSE SRC_FILES src/*.cpp) # get all sources files

add_executable(worldIMaker ${SRC_FILES}) # add the executable

target_link_libraries(worldIMaker ${ALL_LIBRARIES})
#file(COPY shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})