# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/usercommon/kubsu/Computer-network/prj2_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/usercommon/kubsu/Computer-network/prj2_2

# Include any dependencies generated for this target.
include CMakeFiles/YourLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/YourLib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/YourLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/YourLib.dir/flags.make

CMakeFiles/YourLib.dir/client.cc.o: CMakeFiles/YourLib.dir/flags.make
CMakeFiles/YourLib.dir/client.cc.o: client.cc
CMakeFiles/YourLib.dir/client.cc.o: CMakeFiles/YourLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/usercommon/kubsu/Computer-network/prj2_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/YourLib.dir/client.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/YourLib.dir/client.cc.o -MF CMakeFiles/YourLib.dir/client.cc.o.d -o CMakeFiles/YourLib.dir/client.cc.o -c /home/usercommon/kubsu/Computer-network/prj2_2/client.cc

CMakeFiles/YourLib.dir/client.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/YourLib.dir/client.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usercommon/kubsu/Computer-network/prj2_2/client.cc > CMakeFiles/YourLib.dir/client.cc.i

CMakeFiles/YourLib.dir/client.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/YourLib.dir/client.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usercommon/kubsu/Computer-network/prj2_2/client.cc -o CMakeFiles/YourLib.dir/client.cc.s

CMakeFiles/YourLib.dir/server.cc.o: CMakeFiles/YourLib.dir/flags.make
CMakeFiles/YourLib.dir/server.cc.o: server.cc
CMakeFiles/YourLib.dir/server.cc.o: CMakeFiles/YourLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/usercommon/kubsu/Computer-network/prj2_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/YourLib.dir/server.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/YourLib.dir/server.cc.o -MF CMakeFiles/YourLib.dir/server.cc.o.d -o CMakeFiles/YourLib.dir/server.cc.o -c /home/usercommon/kubsu/Computer-network/prj2_2/server.cc

CMakeFiles/YourLib.dir/server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/YourLib.dir/server.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usercommon/kubsu/Computer-network/prj2_2/server.cc > CMakeFiles/YourLib.dir/server.cc.i

CMakeFiles/YourLib.dir/server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/YourLib.dir/server.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usercommon/kubsu/Computer-network/prj2_2/server.cc -o CMakeFiles/YourLib.dir/server.cc.s

# Object files for target YourLib
YourLib_OBJECTS = \
"CMakeFiles/YourLib.dir/client.cc.o" \
"CMakeFiles/YourLib.dir/server.cc.o"

# External object files for target YourLib
YourLib_EXTERNAL_OBJECTS =

libYourLib.a: CMakeFiles/YourLib.dir/client.cc.o
libYourLib.a: CMakeFiles/YourLib.dir/server.cc.o
libYourLib.a: CMakeFiles/YourLib.dir/build.make
libYourLib.a: CMakeFiles/YourLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/usercommon/kubsu/Computer-network/prj2_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libYourLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/YourLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/YourLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/YourLib.dir/build: libYourLib.a
.PHONY : CMakeFiles/YourLib.dir/build

CMakeFiles/YourLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/YourLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/YourLib.dir/clean

CMakeFiles/YourLib.dir/depend:
	cd /home/usercommon/kubsu/Computer-network/prj2_2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/usercommon/kubsu/Computer-network/prj2_2 /home/usercommon/kubsu/Computer-network/prj2_2 /home/usercommon/kubsu/Computer-network/prj2_2 /home/usercommon/kubsu/Computer-network/prj2_2 /home/usercommon/kubsu/Computer-network/prj2_2/CMakeFiles/YourLib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/YourLib.dir/depend

