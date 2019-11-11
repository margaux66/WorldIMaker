cmake_minimum_required(VERSION 3.2 FATAL_ERROR)


# give a name to the project
project(stabilisation)

# specify the system
# see: https://cmake.org/cmake/help/v3.9/manual/cmake-variables.7.html
message("CMAKE_VERSION          : " ${CMAKE_VERSION})
message("CMAKE_SYSTEM_NAME      : " ${CMAKE_SYSTEM_NAME})
message("CMAKE_SYSTEM           : " ${CMAKE_SYSTEM})
message("CMAKE_SYSTEM_PROCESSOR : " ${CMAKE_SYSTEM_PROCESSOR})

# specify the directories
message("CMAKE_BINARY_DIR       : " ${CMAKE_BINARY_DIR})
message("CMAKE_SOURCE_DIR       : " ${CMAKE_SOURCE_DIR})
message("CMAKE_HOME_DIRECTORY   : " ${CMAKE_HOME_DIRECTORY})
message("PROJECT_BINARY_DIR     : " ${PROJECT_BINARY_DIR})
message("PROJECT_SOURCE_DIR     : " ${PROJECT_SOURCE_DIR})


# add a "output" directory in the project binary directory
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/output)

# put the binary files in this directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


# find opencv
message("look for lib opencv ..." )
find_package(OpenCV REQUIRED)
if(${OpenCV_FOUND})
	message(STATUS "lib opencv found")
	message(STATUS "  version     : " ${OpenCV_VERSION})
	message(STATUS "  include dir : " ${OpenCV_INCLUDE_DIRS})
	message(STATUS "  libraries   : ")
	foreach(opencvLibs ${OpenCV_LIBS})
		message("        " ${opencvLibs})
	endforeach()	
endif()

# check opencv version
if(${OpenCV_VERSION} VERSION_LESS 2.0.0)
	message(FATAL_ERROR “OpenCV version is not compatible : ${OpenCV_VERSION}”)
endif()

# lib include path
include_directories(${OpenCV_INCLUDE_DIRS})


# include Eigen
find_package(Eigen3 REQUIRED)
if(${EIGEN3_FOUND})
    message(STATUS "lib EIGEN3 found")
    message(STATUS "  version " ${EIGEN3_VERSION_STRING})
    message(STATUS "  include " ${EIGEN3_INCLUDE_DIR})
else()
    message(FATAL_ERROR "lib EIGEN3 not found")
endif()

# lib include path
include_directories(${EIGEN3_INCLUDE_DIR})


# use at least c++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# compilation flags (should be avoided)
set(CMAKE_CXX_FLAGS "-Wall -O2")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")

# If we have compiler requirements for this library, list them here
#target_compile_features(vectorD 
#    PUBLIC cxx_auto_type
#    PRIVATE cxx_variadic_templates)


# compile
add_executable(stabilisation src/imageStabilization.cpp)

# specify the library lib path
target_link_libraries(stabilisation ${OpenCV_LIBS})



