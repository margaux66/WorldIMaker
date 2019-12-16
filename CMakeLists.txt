cmake_minimum_required(VERSION 3.0)

project(WorldIMaker)

add_definitions(-std=c++11 -I/usr/local/include)

set(EXECUTABLE_NAME WorldIMaker)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

##set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

##pc fac
if(UPEMLV)
    set(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)
endif(UPEMLV)

#OpenGL
message("Looking for OpenGL...")
find_package(OpenGL REQUIRED)
if(${OpenGL_FOUND})
    message(STATUS "lib OpenGL found")
    message(STATUS "  version " ${OpenGL_VERSION_STRING})
    message(STATUS "  include " ${OpenGL_INCLUDE_DIR})
endif()

#GLEW
message("Looking for GLEW...")
find_package(GLEW REQUIRED)
if(${GLEW_FOUND})
    message(STATUS "lib GLEW found")
    message(STATUS "  version " ${OpenGL_VERSION_STRING})
    message(STATUS "  include " ${OpenGL_INCLUDE_DIR})
endif()

#find_package(SDL REQUIRED)
find_package(SDL2 REQUIRED)
#linux
if(${SDL2_FOUND})
    message(STATUS "lib SDL2 found")
    message(STATUS "  version " ${SDL2_VERSION_STRING})
    message(STATUS "  include " ${SDL2_INCLUDE_DIR})
endif()

# # include doxygen
# message("Looking for doxygen...")
# find_package(Doxygen
#              REQUIRED dot
#              OPTIONAL_COMPONENTS mscgen dia)
# if(${DOXYGEN_FOUND})
#     message(STATUS "lib EIGEN3 found")
#     message(STATUS "  version " ${EIGEN3_VERSION_STRING})
#     message(STATUS "  include " ${EIGEN3_INCLUDE_DIR})
# endif()

# compilation flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2 -lSDL2 -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")

include_directories(${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} glimac/include third-party/include)
#lib/imgui/include
set(ALL_LIBRARIES ${SDL2_LIBRARIES} glimac ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})
#imgui

# Add the glimac library
add_subdirectory(glimac)
# Add the imgui library
#add_subdirectory(lib/imgui)
# Add doxygen
# add_subdirectory(doc)
# file(GLOB_RECURSE HEADER_FILES src/include/*) # get all headers
# file(GLOB_RECURSE SRC_FILES src/*.cpp) # get all sources files

add_executable(${EXECUTABLE_NAME} ${SRC_FILES}) # add the executable

target_link_libraries(${EXECUTABLE_NAME} ${ALL_LIBRARIES})
#file(COPY shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Pour gérer un bug a la fac, a supprimer sur machine perso:
#set(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)
