# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/curtis/hw4/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/curtis/hw4/build

# Include any dependencies generated for this target.
include hw4/CMakeFiles/hw4.dir/depend.make

# Include the progress variables for this target.
include hw4/CMakeFiles/hw4.dir/progress.make

# Include the compile flags for this target's objects.
include hw4/CMakeFiles/hw4.dir/flags.make

hw4/CMakeFiles/hw4.dir/hw4.cpp.o: hw4/CMakeFiles/hw4.dir/flags.make
hw4/CMakeFiles/hw4.dir/hw4.cpp.o: /home/curtis/hw4/src/hw4/hw4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/curtis/hw4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object hw4/CMakeFiles/hw4.dir/hw4.cpp.o"
	cd /home/curtis/hw4/build/hw4 && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw4.dir/hw4.cpp.o -c /home/curtis/hw4/src/hw4/hw4.cpp

hw4/CMakeFiles/hw4.dir/hw4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw4.dir/hw4.cpp.i"
	cd /home/curtis/hw4/build/hw4 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/curtis/hw4/src/hw4/hw4.cpp > CMakeFiles/hw4.dir/hw4.cpp.i

hw4/CMakeFiles/hw4.dir/hw4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw4.dir/hw4.cpp.s"
	cd /home/curtis/hw4/build/hw4 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/curtis/hw4/src/hw4/hw4.cpp -o CMakeFiles/hw4.dir/hw4.cpp.s

hw4/CMakeFiles/hw4.dir/hw4.cpp.o.requires:

.PHONY : hw4/CMakeFiles/hw4.dir/hw4.cpp.o.requires

hw4/CMakeFiles/hw4.dir/hw4.cpp.o.provides: hw4/CMakeFiles/hw4.dir/hw4.cpp.o.requires
	$(MAKE) -f hw4/CMakeFiles/hw4.dir/build.make hw4/CMakeFiles/hw4.dir/hw4.cpp.o.provides.build
.PHONY : hw4/CMakeFiles/hw4.dir/hw4.cpp.o.provides

hw4/CMakeFiles/hw4.dir/hw4.cpp.o.provides.build: hw4/CMakeFiles/hw4.dir/hw4.cpp.o


# Object files for target hw4
hw4_OBJECTS = \
"CMakeFiles/hw4.dir/hw4.cpp.o"

# External object files for target hw4
hw4_EXTERNAL_OBJECTS =

/home/curtis/hw4/devel/lib/hw4/hw4: hw4/CMakeFiles/hw4.dir/hw4.cpp.o
/home/curtis/hw4/devel/lib/hw4/hw4: hw4/CMakeFiles/hw4.dir/build.make
/home/curtis/hw4/devel/lib/hw4/hw4: /opt/ros/kinetic/lib/libroscpp.so
/home/curtis/hw4/devel/lib/hw4/hw4: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/curtis/hw4/devel/lib/hw4/hw4: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/curtis/hw4/devel/lib/hw4/hw4: /opt/ros/kinetic/lib/librosconsole.so
/home/curtis/hw4/devel/lib/hw4/hw4: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/curtis/hw4/devel/lib/hw4/hw4: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/curtis/hw4/devel/lib/hw4/hw4: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/curtis/hw4/devel/lib/hw4/hw4: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/curtis/hw4/devel/lib/hw4/hw4: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/curtis/hw4/devel/lib/hw4/hw4: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/curtis/hw4/devel/lib/hw4/hw4: /opt/ros/kinetic/lib/librostime.so
/home/curtis/hw4/devel/lib/hw4/hw4: /opt/ros/kinetic/lib/libcpp_common.so
/home/curtis/hw4/devel/lib/hw4/hw4: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/curtis/hw4/devel/lib/hw4/hw4: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/curtis/hw4/devel/lib/hw4/hw4: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/curtis/hw4/devel/lib/hw4/hw4: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/curtis/hw4/devel/lib/hw4/hw4: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/curtis/hw4/devel/lib/hw4/hw4: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/curtis/hw4/devel/lib/hw4/hw4: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/curtis/hw4/devel/lib/hw4/hw4: hw4/CMakeFiles/hw4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/curtis/hw4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/curtis/hw4/devel/lib/hw4/hw4"
	cd /home/curtis/hw4/build/hw4 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
hw4/CMakeFiles/hw4.dir/build: /home/curtis/hw4/devel/lib/hw4/hw4

.PHONY : hw4/CMakeFiles/hw4.dir/build

hw4/CMakeFiles/hw4.dir/requires: hw4/CMakeFiles/hw4.dir/hw4.cpp.o.requires

.PHONY : hw4/CMakeFiles/hw4.dir/requires

hw4/CMakeFiles/hw4.dir/clean:
	cd /home/curtis/hw4/build/hw4 && $(CMAKE_COMMAND) -P CMakeFiles/hw4.dir/cmake_clean.cmake
.PHONY : hw4/CMakeFiles/hw4.dir/clean

hw4/CMakeFiles/hw4.dir/depend:
	cd /home/curtis/hw4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/curtis/hw4/src /home/curtis/hw4/src/hw4 /home/curtis/hw4/build /home/curtis/hw4/build/hw4 /home/curtis/hw4/build/hw4/CMakeFiles/hw4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : hw4/CMakeFiles/hw4.dir/depend

