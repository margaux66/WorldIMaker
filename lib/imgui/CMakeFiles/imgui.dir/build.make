# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker

# Include any dependencies generated for this target.
include lib/imgui/CMakeFiles/imgui.dir/depend.make

# Include the progress variables for this target.
include lib/imgui/CMakeFiles/imgui.dir/progress.make

# Include the compile flags for this target's objects.
include lib/imgui/CMakeFiles/imgui.dir/flags.make

lib/imgui/CMakeFiles/imgui.dir/src/imgui.cpp.o: lib/imgui/CMakeFiles/imgui.dir/flags.make
lib/imgui/CMakeFiles/imgui.dir/src/imgui.cpp.o: lib/imgui/src/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/imgui/CMakeFiles/imgui.dir/src/imgui.cpp.o"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/src/imgui.cpp.o -c /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui.cpp

lib/imgui/CMakeFiles/imgui.dir/src/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/src/imgui.cpp.i"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui.cpp > CMakeFiles/imgui.dir/src/imgui.cpp.i

lib/imgui/CMakeFiles/imgui.dir/src/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/src/imgui.cpp.s"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui.cpp -o CMakeFiles/imgui.dir/src/imgui.cpp.s

lib/imgui/CMakeFiles/imgui.dir/src/imgui_demo.cpp.o: lib/imgui/CMakeFiles/imgui.dir/flags.make
lib/imgui/CMakeFiles/imgui.dir/src/imgui_demo.cpp.o: lib/imgui/src/imgui_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/imgui/CMakeFiles/imgui.dir/src/imgui_demo.cpp.o"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/src/imgui_demo.cpp.o -c /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_demo.cpp

lib/imgui/CMakeFiles/imgui.dir/src/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/src/imgui_demo.cpp.i"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_demo.cpp > CMakeFiles/imgui.dir/src/imgui_demo.cpp.i

lib/imgui/CMakeFiles/imgui.dir/src/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/src/imgui_demo.cpp.s"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_demo.cpp -o CMakeFiles/imgui.dir/src/imgui_demo.cpp.s

lib/imgui/CMakeFiles/imgui.dir/src/imgui_draw.cpp.o: lib/imgui/CMakeFiles/imgui.dir/flags.make
lib/imgui/CMakeFiles/imgui.dir/src/imgui_draw.cpp.o: lib/imgui/src/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object lib/imgui/CMakeFiles/imgui.dir/src/imgui_draw.cpp.o"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/src/imgui_draw.cpp.o -c /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_draw.cpp

lib/imgui/CMakeFiles/imgui.dir/src/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/src/imgui_draw.cpp.i"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_draw.cpp > CMakeFiles/imgui.dir/src/imgui_draw.cpp.i

lib/imgui/CMakeFiles/imgui.dir/src/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/src/imgui_draw.cpp.s"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_draw.cpp -o CMakeFiles/imgui.dir/src/imgui_draw.cpp.s

lib/imgui/CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.o: lib/imgui/CMakeFiles/imgui.dir/flags.make
lib/imgui/CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.o: lib/imgui/src/imgui_impl_opengl3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object lib/imgui/CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.o"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.o -c /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_impl_opengl3.cpp

lib/imgui/CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.i"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_impl_opengl3.cpp > CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.i

lib/imgui/CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.s"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_impl_opengl3.cpp -o CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.s

lib/imgui/CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.o: lib/imgui/CMakeFiles/imgui.dir/flags.make
lib/imgui/CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.o: lib/imgui/src/imgui_impl_sdl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object lib/imgui/CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.o"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.o -c /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_impl_sdl.cpp

lib/imgui/CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.i"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_impl_sdl.cpp > CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.i

lib/imgui/CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.s"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_impl_sdl.cpp -o CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.s

lib/imgui/CMakeFiles/imgui.dir/src/imgui_stdlib.cpp.o: lib/imgui/CMakeFiles/imgui.dir/flags.make
lib/imgui/CMakeFiles/imgui.dir/src/imgui_stdlib.cpp.o: lib/imgui/src/imgui_stdlib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object lib/imgui/CMakeFiles/imgui.dir/src/imgui_stdlib.cpp.o"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/src/imgui_stdlib.cpp.o -c /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_stdlib.cpp

lib/imgui/CMakeFiles/imgui.dir/src/imgui_stdlib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/src/imgui_stdlib.cpp.i"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_stdlib.cpp > CMakeFiles/imgui.dir/src/imgui_stdlib.cpp.i

lib/imgui/CMakeFiles/imgui.dir/src/imgui_stdlib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/src/imgui_stdlib.cpp.s"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_stdlib.cpp -o CMakeFiles/imgui.dir/src/imgui_stdlib.cpp.s

lib/imgui/CMakeFiles/imgui.dir/src/imgui_widgets.cpp.o: lib/imgui/CMakeFiles/imgui.dir/flags.make
lib/imgui/CMakeFiles/imgui.dir/src/imgui_widgets.cpp.o: lib/imgui/src/imgui_widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object lib/imgui/CMakeFiles/imgui.dir/src/imgui_widgets.cpp.o"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/src/imgui_widgets.cpp.o -c /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_widgets.cpp

lib/imgui/CMakeFiles/imgui.dir/src/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/src/imgui_widgets.cpp.i"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_widgets.cpp > CMakeFiles/imgui.dir/src/imgui_widgets.cpp.i

lib/imgui/CMakeFiles/imgui.dir/src/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/src/imgui_widgets.cpp.s"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/src/imgui_widgets.cpp -o CMakeFiles/imgui.dir/src/imgui_widgets.cpp.s

# Object files for target imgui
imgui_OBJECTS = \
"CMakeFiles/imgui.dir/src/imgui.cpp.o" \
"CMakeFiles/imgui.dir/src/imgui_demo.cpp.o" \
"CMakeFiles/imgui.dir/src/imgui_draw.cpp.o" \
"CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.o" \
"CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.o" \
"CMakeFiles/imgui.dir/src/imgui_stdlib.cpp.o" \
"CMakeFiles/imgui.dir/src/imgui_widgets.cpp.o"

# External object files for target imgui
imgui_EXTERNAL_OBJECTS =

lib/libimgui.a: lib/imgui/CMakeFiles/imgui.dir/src/imgui.cpp.o
lib/libimgui.a: lib/imgui/CMakeFiles/imgui.dir/src/imgui_demo.cpp.o
lib/libimgui.a: lib/imgui/CMakeFiles/imgui.dir/src/imgui_draw.cpp.o
lib/libimgui.a: lib/imgui/CMakeFiles/imgui.dir/src/imgui_impl_opengl3.cpp.o
lib/libimgui.a: lib/imgui/CMakeFiles/imgui.dir/src/imgui_impl_sdl.cpp.o
lib/libimgui.a: lib/imgui/CMakeFiles/imgui.dir/src/imgui_stdlib.cpp.o
lib/libimgui.a: lib/imgui/CMakeFiles/imgui.dir/src/imgui_widgets.cpp.o
lib/libimgui.a: lib/imgui/CMakeFiles/imgui.dir/build.make
lib/libimgui.a: lib/imgui/CMakeFiles/imgui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library ../libimgui.a"
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && $(CMAKE_COMMAND) -P CMakeFiles/imgui.dir/cmake_clean_target.cmake
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imgui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/imgui/CMakeFiles/imgui.dir/build: lib/libimgui.a

.PHONY : lib/imgui/CMakeFiles/imgui.dir/build

lib/imgui/CMakeFiles/imgui.dir/clean:
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui && $(CMAKE_COMMAND) -P CMakeFiles/imgui.dir/cmake_clean.cmake
.PHONY : lib/imgui/CMakeFiles/imgui.dir/clean

lib/imgui/CMakeFiles/imgui.dir/depend:
	cd /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui /Users/margaux/Desktop/IMAC/S3/Voldemort/WorldIMaker/WorldIMaker/lib/imgui/CMakeFiles/imgui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/imgui/CMakeFiles/imgui.dir/depend

