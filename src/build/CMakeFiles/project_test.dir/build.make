# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/build

# Include any dependencies generated for this target.
include CMakeFiles/project_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project_test.dir/flags.make

CMakeFiles/project_test.dir/neuron.cpp.o: CMakeFiles/project_test.dir/flags.make
CMakeFiles/project_test.dir/neuron.cpp.o: ../neuron.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project_test.dir/neuron.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project_test.dir/neuron.cpp.o -c /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/neuron.cpp

CMakeFiles/project_test.dir/neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_test.dir/neuron.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/neuron.cpp > CMakeFiles/project_test.dir/neuron.cpp.i

CMakeFiles/project_test.dir/neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_test.dir/neuron.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/neuron.cpp -o CMakeFiles/project_test.dir/neuron.cpp.s

CMakeFiles/project_test.dir/neuron.cpp.o.requires:
.PHONY : CMakeFiles/project_test.dir/neuron.cpp.o.requires

CMakeFiles/project_test.dir/neuron.cpp.o.provides: CMakeFiles/project_test.dir/neuron.cpp.o.requires
	$(MAKE) -f CMakeFiles/project_test.dir/build.make CMakeFiles/project_test.dir/neuron.cpp.o.provides.build
.PHONY : CMakeFiles/project_test.dir/neuron.cpp.o.provides

CMakeFiles/project_test.dir/neuron.cpp.o.provides.build: CMakeFiles/project_test.dir/neuron.cpp.o

CMakeFiles/project_test.dir/network.cpp.o: CMakeFiles/project_test.dir/flags.make
CMakeFiles/project_test.dir/network.cpp.o: ../network.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project_test.dir/network.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project_test.dir/network.cpp.o -c /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/network.cpp

CMakeFiles/project_test.dir/network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_test.dir/network.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/network.cpp > CMakeFiles/project_test.dir/network.cpp.i

CMakeFiles/project_test.dir/network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_test.dir/network.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/network.cpp -o CMakeFiles/project_test.dir/network.cpp.s

CMakeFiles/project_test.dir/network.cpp.o.requires:
.PHONY : CMakeFiles/project_test.dir/network.cpp.o.requires

CMakeFiles/project_test.dir/network.cpp.o.provides: CMakeFiles/project_test.dir/network.cpp.o.requires
	$(MAKE) -f CMakeFiles/project_test.dir/build.make CMakeFiles/project_test.dir/network.cpp.o.provides.build
.PHONY : CMakeFiles/project_test.dir/network.cpp.o.provides

CMakeFiles/project_test.dir/network.cpp.o.provides.build: CMakeFiles/project_test.dir/network.cpp.o

CMakeFiles/project_test.dir/project_test.cpp.o: CMakeFiles/project_test.dir/flags.make
CMakeFiles/project_test.dir/project_test.cpp.o: ../project_test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project_test.dir/project_test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project_test.dir/project_test.cpp.o -c /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/project_test.cpp

CMakeFiles/project_test.dir/project_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_test.dir/project_test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/project_test.cpp > CMakeFiles/project_test.dir/project_test.cpp.i

CMakeFiles/project_test.dir/project_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_test.dir/project_test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/project_test.cpp -o CMakeFiles/project_test.dir/project_test.cpp.s

CMakeFiles/project_test.dir/project_test.cpp.o.requires:
.PHONY : CMakeFiles/project_test.dir/project_test.cpp.o.requires

CMakeFiles/project_test.dir/project_test.cpp.o.provides: CMakeFiles/project_test.dir/project_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/project_test.dir/build.make CMakeFiles/project_test.dir/project_test.cpp.o.provides.build
.PHONY : CMakeFiles/project_test.dir/project_test.cpp.o.provides

CMakeFiles/project_test.dir/project_test.cpp.o.provides.build: CMakeFiles/project_test.dir/project_test.cpp.o

# Object files for target project_test
project_test_OBJECTS = \
"CMakeFiles/project_test.dir/neuron.cpp.o" \
"CMakeFiles/project_test.dir/network.cpp.o" \
"CMakeFiles/project_test.dir/project_test.cpp.o"

# External object files for target project_test
project_test_EXTERNAL_OBJECTS =

project_test: CMakeFiles/project_test.dir/neuron.cpp.o
project_test: CMakeFiles/project_test.dir/network.cpp.o
project_test: CMakeFiles/project_test.dir/project_test.cpp.o
project_test: CMakeFiles/project_test.dir/build.make
project_test: CMakeFiles/project_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable project_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project_test.dir/build: project_test
.PHONY : CMakeFiles/project_test.dir/build

CMakeFiles/project_test.dir/requires: CMakeFiles/project_test.dir/neuron.cpp.o.requires
CMakeFiles/project_test.dir/requires: CMakeFiles/project_test.dir/network.cpp.o.requires
CMakeFiles/project_test.dir/requires: CMakeFiles/project_test.dir/project_test.cpp.o.requires
.PHONY : CMakeFiles/project_test.dir/requires

CMakeFiles/project_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project_test.dir/clean

CMakeFiles/project_test.dir/depend:
	cd /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/build /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/build /home/INTRANET/hmonnet/myfiles/BA3/CS116-2017-heloise-monnet/src/build/CMakeFiles/project_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project_test.dir/depend
