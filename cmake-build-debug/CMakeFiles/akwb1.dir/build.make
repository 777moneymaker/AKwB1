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
CMAKE_COMMAND = /home/moneymaker/Downloads/CLion-2019.2.4/clion-2019.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/moneymaker/Downloads/CLion-2019.2.4/clion-2019.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/moneymaker/Desktop/akwb1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/moneymaker/Desktop/akwb1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/akwb1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/akwb1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/akwb1.dir/flags.make

CMakeFiles/akwb1.dir/Libraries/Graph.cpp.o: CMakeFiles/akwb1.dir/flags.make
CMakeFiles/akwb1.dir/Libraries/Graph.cpp.o: ../Libraries/Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moneymaker/Desktop/akwb1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/akwb1.dir/Libraries/Graph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/akwb1.dir/Libraries/Graph.cpp.o -c /home/moneymaker/Desktop/akwb1/Libraries/Graph.cpp

CMakeFiles/akwb1.dir/Libraries/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/akwb1.dir/Libraries/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moneymaker/Desktop/akwb1/Libraries/Graph.cpp > CMakeFiles/akwb1.dir/Libraries/Graph.cpp.i

CMakeFiles/akwb1.dir/Libraries/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/akwb1.dir/Libraries/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moneymaker/Desktop/akwb1/Libraries/Graph.cpp -o CMakeFiles/akwb1.dir/Libraries/Graph.cpp.s

CMakeFiles/akwb1.dir/main.cpp.o: CMakeFiles/akwb1.dir/flags.make
CMakeFiles/akwb1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moneymaker/Desktop/akwb1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/akwb1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/akwb1.dir/main.cpp.o -c /home/moneymaker/Desktop/akwb1/main.cpp

CMakeFiles/akwb1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/akwb1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moneymaker/Desktop/akwb1/main.cpp > CMakeFiles/akwb1.dir/main.cpp.i

CMakeFiles/akwb1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/akwb1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moneymaker/Desktop/akwb1/main.cpp -o CMakeFiles/akwb1.dir/main.cpp.s

# Object files for target akwb1
akwb1_OBJECTS = \
"CMakeFiles/akwb1.dir/Libraries/Graph.cpp.o" \
"CMakeFiles/akwb1.dir/main.cpp.o"

# External object files for target akwb1
akwb1_EXTERNAL_OBJECTS =

akwb1: CMakeFiles/akwb1.dir/Libraries/Graph.cpp.o
akwb1: CMakeFiles/akwb1.dir/main.cpp.o
akwb1: CMakeFiles/akwb1.dir/build.make
akwb1: CMakeFiles/akwb1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/moneymaker/Desktop/akwb1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable akwb1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/akwb1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/akwb1.dir/build: akwb1

.PHONY : CMakeFiles/akwb1.dir/build

CMakeFiles/akwb1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/akwb1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/akwb1.dir/clean

CMakeFiles/akwb1.dir/depend:
	cd /home/moneymaker/Desktop/akwb1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moneymaker/Desktop/akwb1 /home/moneymaker/Desktop/akwb1 /home/moneymaker/Desktop/akwb1/cmake-build-debug /home/moneymaker/Desktop/akwb1/cmake-build-debug /home/moneymaker/Desktop/akwb1/cmake-build-debug/CMakeFiles/akwb1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/akwb1.dir/depend

