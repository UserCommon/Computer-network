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
CMAKE_SOURCE_DIR = /home/usercommon/kubsu/Computer-network/prj2_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/usercommon/kubsu/Computer-network/prj2_3/out

# Include any dependencies generated for this target.
include CMakeFiles/MessageLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MessageLib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MessageLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MessageLib.dir/flags.make

CMakeFiles/MessageLib.dir/Message.cc.o: CMakeFiles/MessageLib.dir/flags.make
CMakeFiles/MessageLib.dir/Message.cc.o: /home/usercommon/kubsu/Computer-network/prj2_3/Message.cc
CMakeFiles/MessageLib.dir/Message.cc.o: CMakeFiles/MessageLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/usercommon/kubsu/Computer-network/prj2_3/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MessageLib.dir/Message.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MessageLib.dir/Message.cc.o -MF CMakeFiles/MessageLib.dir/Message.cc.o.d -o CMakeFiles/MessageLib.dir/Message.cc.o -c /home/usercommon/kubsu/Computer-network/prj2_3/Message.cc

CMakeFiles/MessageLib.dir/Message.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MessageLib.dir/Message.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usercommon/kubsu/Computer-network/prj2_3/Message.cc > CMakeFiles/MessageLib.dir/Message.cc.i

CMakeFiles/MessageLib.dir/Message.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MessageLib.dir/Message.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usercommon/kubsu/Computer-network/prj2_3/Message.cc -o CMakeFiles/MessageLib.dir/Message.cc.s

# Object files for target MessageLib
MessageLib_OBJECTS = \
"CMakeFiles/MessageLib.dir/Message.cc.o"

# External object files for target MessageLib
MessageLib_EXTERNAL_OBJECTS =

libMessageLib.a: CMakeFiles/MessageLib.dir/Message.cc.o
libMessageLib.a: CMakeFiles/MessageLib.dir/build.make
libMessageLib.a: CMakeFiles/MessageLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/usercommon/kubsu/Computer-network/prj2_3/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMessageLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/MessageLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MessageLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MessageLib.dir/build: libMessageLib.a
.PHONY : CMakeFiles/MessageLib.dir/build

CMakeFiles/MessageLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MessageLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MessageLib.dir/clean

CMakeFiles/MessageLib.dir/depend:
	cd /home/usercommon/kubsu/Computer-network/prj2_3/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/usercommon/kubsu/Computer-network/prj2_3 /home/usercommon/kubsu/Computer-network/prj2_3 /home/usercommon/kubsu/Computer-network/prj2_3/out /home/usercommon/kubsu/Computer-network/prj2_3/out /home/usercommon/kubsu/Computer-network/prj2_3/out/CMakeFiles/MessageLib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MessageLib.dir/depend

