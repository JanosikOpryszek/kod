# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/marcin/kod/net/eth

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marcin/kod/net/eth

# Include any dependencies generated for this target.
include CMakeFiles/eth.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/eth.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/eth.dir/flags.make

CMakeFiles/eth.dir/main.cpp.o: CMakeFiles/eth.dir/flags.make
CMakeFiles/eth.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcin/kod/net/eth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/eth.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/eth.dir/main.cpp.o -c /home/marcin/kod/net/eth/main.cpp

CMakeFiles/eth.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/eth.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcin/kod/net/eth/main.cpp > CMakeFiles/eth.dir/main.cpp.i

CMakeFiles/eth.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/eth.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcin/kod/net/eth/main.cpp -o CMakeFiles/eth.dir/main.cpp.s

CMakeFiles/eth.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/eth.dir/main.cpp.o.requires

CMakeFiles/eth.dir/main.cpp.o.provides: CMakeFiles/eth.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/eth.dir/build.make CMakeFiles/eth.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/eth.dir/main.cpp.o.provides

CMakeFiles/eth.dir/main.cpp.o.provides.build: CMakeFiles/eth.dir/main.cpp.o


CMakeFiles/eth.dir/ethernetdriverclient.cpp.o: CMakeFiles/eth.dir/flags.make
CMakeFiles/eth.dir/ethernetdriverclient.cpp.o: ethernetdriverclient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcin/kod/net/eth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/eth.dir/ethernetdriverclient.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/eth.dir/ethernetdriverclient.cpp.o -c /home/marcin/kod/net/eth/ethernetdriverclient.cpp

CMakeFiles/eth.dir/ethernetdriverclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/eth.dir/ethernetdriverclient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcin/kod/net/eth/ethernetdriverclient.cpp > CMakeFiles/eth.dir/ethernetdriverclient.cpp.i

CMakeFiles/eth.dir/ethernetdriverclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/eth.dir/ethernetdriverclient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcin/kod/net/eth/ethernetdriverclient.cpp -o CMakeFiles/eth.dir/ethernetdriverclient.cpp.s

CMakeFiles/eth.dir/ethernetdriverclient.cpp.o.requires:

.PHONY : CMakeFiles/eth.dir/ethernetdriverclient.cpp.o.requires

CMakeFiles/eth.dir/ethernetdriverclient.cpp.o.provides: CMakeFiles/eth.dir/ethernetdriverclient.cpp.o.requires
	$(MAKE) -f CMakeFiles/eth.dir/build.make CMakeFiles/eth.dir/ethernetdriverclient.cpp.o.provides.build
.PHONY : CMakeFiles/eth.dir/ethernetdriverclient.cpp.o.provides

CMakeFiles/eth.dir/ethernetdriverclient.cpp.o.provides.build: CMakeFiles/eth.dir/ethernetdriverclient.cpp.o


CMakeFiles/eth.dir/ethernetdriverserver.cpp.o: CMakeFiles/eth.dir/flags.make
CMakeFiles/eth.dir/ethernetdriverserver.cpp.o: ethernetdriverserver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcin/kod/net/eth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/eth.dir/ethernetdriverserver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/eth.dir/ethernetdriverserver.cpp.o -c /home/marcin/kod/net/eth/ethernetdriverserver.cpp

CMakeFiles/eth.dir/ethernetdriverserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/eth.dir/ethernetdriverserver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcin/kod/net/eth/ethernetdriverserver.cpp > CMakeFiles/eth.dir/ethernetdriverserver.cpp.i

CMakeFiles/eth.dir/ethernetdriverserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/eth.dir/ethernetdriverserver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcin/kod/net/eth/ethernetdriverserver.cpp -o CMakeFiles/eth.dir/ethernetdriverserver.cpp.s

CMakeFiles/eth.dir/ethernetdriverserver.cpp.o.requires:

.PHONY : CMakeFiles/eth.dir/ethernetdriverserver.cpp.o.requires

CMakeFiles/eth.dir/ethernetdriverserver.cpp.o.provides: CMakeFiles/eth.dir/ethernetdriverserver.cpp.o.requires
	$(MAKE) -f CMakeFiles/eth.dir/build.make CMakeFiles/eth.dir/ethernetdriverserver.cpp.o.provides.build
.PHONY : CMakeFiles/eth.dir/ethernetdriverserver.cpp.o.provides

CMakeFiles/eth.dir/ethernetdriverserver.cpp.o.provides.build: CMakeFiles/eth.dir/ethernetdriverserver.cpp.o


# Object files for target eth
eth_OBJECTS = \
"CMakeFiles/eth.dir/main.cpp.o" \
"CMakeFiles/eth.dir/ethernetdriverclient.cpp.o" \
"CMakeFiles/eth.dir/ethernetdriverserver.cpp.o"

# External object files for target eth
eth_EXTERNAL_OBJECTS =

eth: CMakeFiles/eth.dir/main.cpp.o
eth: CMakeFiles/eth.dir/ethernetdriverclient.cpp.o
eth: CMakeFiles/eth.dir/ethernetdriverserver.cpp.o
eth: CMakeFiles/eth.dir/build.make
eth: CMakeFiles/eth.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marcin/kod/net/eth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable eth"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/eth.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/eth.dir/build: eth

.PHONY : CMakeFiles/eth.dir/build

CMakeFiles/eth.dir/requires: CMakeFiles/eth.dir/main.cpp.o.requires
CMakeFiles/eth.dir/requires: CMakeFiles/eth.dir/ethernetdriverclient.cpp.o.requires
CMakeFiles/eth.dir/requires: CMakeFiles/eth.dir/ethernetdriverserver.cpp.o.requires

.PHONY : CMakeFiles/eth.dir/requires

CMakeFiles/eth.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/eth.dir/cmake_clean.cmake
.PHONY : CMakeFiles/eth.dir/clean

CMakeFiles/eth.dir/depend:
	cd /home/marcin/kod/net/eth && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marcin/kod/net/eth /home/marcin/kod/net/eth /home/marcin/kod/net/eth /home/marcin/kod/net/eth /home/marcin/kod/net/eth/CMakeFiles/eth.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/eth.dir/depend
