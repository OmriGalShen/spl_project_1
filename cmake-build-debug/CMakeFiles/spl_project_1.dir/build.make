# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/spl211/Downloads/clion-2020.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/spl211/Downloads/clion-2020.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/spl211/CLionProjects/spl_project_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/spl211/CLionProjects/spl_project_1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/spl_project_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/spl_project_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/spl_project_1.dir/flags.make

CMakeFiles/spl_project_1.dir/src/classes/agents/Agent.cpp.o: CMakeFiles/spl_project_1.dir/flags.make
CMakeFiles/spl_project_1.dir/src/classes/agents/Agent.cpp.o: ../src/classes/agents/Agent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/spl_project_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/spl_project_1.dir/src/classes/agents/Agent.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl_project_1.dir/src/classes/agents/Agent.cpp.o -c /home/spl211/CLionProjects/spl_project_1/src/classes/agents/Agent.cpp

CMakeFiles/spl_project_1.dir/src/classes/agents/Agent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl_project_1.dir/src/classes/agents/Agent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/spl_project_1/src/classes/agents/Agent.cpp > CMakeFiles/spl_project_1.dir/src/classes/agents/Agent.cpp.i

CMakeFiles/spl_project_1.dir/src/classes/agents/Agent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl_project_1.dir/src/classes/agents/Agent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/spl_project_1/src/classes/agents/Agent.cpp -o CMakeFiles/spl_project_1.dir/src/classes/agents/Agent.cpp.s

CMakeFiles/spl_project_1.dir/src/classes/agents/ContactTracer.cpp.o: CMakeFiles/spl_project_1.dir/flags.make
CMakeFiles/spl_project_1.dir/src/classes/agents/ContactTracer.cpp.o: ../src/classes/agents/ContactTracer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/spl_project_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/spl_project_1.dir/src/classes/agents/ContactTracer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl_project_1.dir/src/classes/agents/ContactTracer.cpp.o -c /home/spl211/CLionProjects/spl_project_1/src/classes/agents/ContactTracer.cpp

CMakeFiles/spl_project_1.dir/src/classes/agents/ContactTracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl_project_1.dir/src/classes/agents/ContactTracer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/spl_project_1/src/classes/agents/ContactTracer.cpp > CMakeFiles/spl_project_1.dir/src/classes/agents/ContactTracer.cpp.i

CMakeFiles/spl_project_1.dir/src/classes/agents/ContactTracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl_project_1.dir/src/classes/agents/ContactTracer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/spl_project_1/src/classes/agents/ContactTracer.cpp -o CMakeFiles/spl_project_1.dir/src/classes/agents/ContactTracer.cpp.s

CMakeFiles/spl_project_1.dir/src/classes/agents/Virus.cpp.o: CMakeFiles/spl_project_1.dir/flags.make
CMakeFiles/spl_project_1.dir/src/classes/agents/Virus.cpp.o: ../src/classes/agents/Virus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/spl_project_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/spl_project_1.dir/src/classes/agents/Virus.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl_project_1.dir/src/classes/agents/Virus.cpp.o -c /home/spl211/CLionProjects/spl_project_1/src/classes/agents/Virus.cpp

CMakeFiles/spl_project_1.dir/src/classes/agents/Virus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl_project_1.dir/src/classes/agents/Virus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/spl_project_1/src/classes/agents/Virus.cpp > CMakeFiles/spl_project_1.dir/src/classes/agents/Virus.cpp.i

CMakeFiles/spl_project_1.dir/src/classes/agents/Virus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl_project_1.dir/src/classes/agents/Virus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/spl_project_1/src/classes/agents/Virus.cpp -o CMakeFiles/spl_project_1.dir/src/classes/agents/Virus.cpp.s

CMakeFiles/spl_project_1.dir/src/classes/trees/CycleTree.cpp.o: CMakeFiles/spl_project_1.dir/flags.make
CMakeFiles/spl_project_1.dir/src/classes/trees/CycleTree.cpp.o: ../src/classes/trees/CycleTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/spl_project_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/spl_project_1.dir/src/classes/trees/CycleTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl_project_1.dir/src/classes/trees/CycleTree.cpp.o -c /home/spl211/CLionProjects/spl_project_1/src/classes/trees/CycleTree.cpp

CMakeFiles/spl_project_1.dir/src/classes/trees/CycleTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl_project_1.dir/src/classes/trees/CycleTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/spl_project_1/src/classes/trees/CycleTree.cpp > CMakeFiles/spl_project_1.dir/src/classes/trees/CycleTree.cpp.i

CMakeFiles/spl_project_1.dir/src/classes/trees/CycleTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl_project_1.dir/src/classes/trees/CycleTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/spl_project_1/src/classes/trees/CycleTree.cpp -o CMakeFiles/spl_project_1.dir/src/classes/trees/CycleTree.cpp.s

CMakeFiles/spl_project_1.dir/src/classes/trees/MaxRankTree.cpp.o: CMakeFiles/spl_project_1.dir/flags.make
CMakeFiles/spl_project_1.dir/src/classes/trees/MaxRankTree.cpp.o: ../src/classes/trees/MaxRankTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/spl_project_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/spl_project_1.dir/src/classes/trees/MaxRankTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl_project_1.dir/src/classes/trees/MaxRankTree.cpp.o -c /home/spl211/CLionProjects/spl_project_1/src/classes/trees/MaxRankTree.cpp

CMakeFiles/spl_project_1.dir/src/classes/trees/MaxRankTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl_project_1.dir/src/classes/trees/MaxRankTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/spl_project_1/src/classes/trees/MaxRankTree.cpp > CMakeFiles/spl_project_1.dir/src/classes/trees/MaxRankTree.cpp.i

CMakeFiles/spl_project_1.dir/src/classes/trees/MaxRankTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl_project_1.dir/src/classes/trees/MaxRankTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/spl_project_1/src/classes/trees/MaxRankTree.cpp -o CMakeFiles/spl_project_1.dir/src/classes/trees/MaxRankTree.cpp.s

CMakeFiles/spl_project_1.dir/src/classes/trees/RootTree.cpp.o: CMakeFiles/spl_project_1.dir/flags.make
CMakeFiles/spl_project_1.dir/src/classes/trees/RootTree.cpp.o: ../src/classes/trees/RootTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/spl_project_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/spl_project_1.dir/src/classes/trees/RootTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl_project_1.dir/src/classes/trees/RootTree.cpp.o -c /home/spl211/CLionProjects/spl_project_1/src/classes/trees/RootTree.cpp

CMakeFiles/spl_project_1.dir/src/classes/trees/RootTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl_project_1.dir/src/classes/trees/RootTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/spl_project_1/src/classes/trees/RootTree.cpp > CMakeFiles/spl_project_1.dir/src/classes/trees/RootTree.cpp.i

CMakeFiles/spl_project_1.dir/src/classes/trees/RootTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl_project_1.dir/src/classes/trees/RootTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/spl_project_1/src/classes/trees/RootTree.cpp -o CMakeFiles/spl_project_1.dir/src/classes/trees/RootTree.cpp.s

CMakeFiles/spl_project_1.dir/src/classes/trees/Tree.cpp.o: CMakeFiles/spl_project_1.dir/flags.make
CMakeFiles/spl_project_1.dir/src/classes/trees/Tree.cpp.o: ../src/classes/trees/Tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/spl_project_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/spl_project_1.dir/src/classes/trees/Tree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl_project_1.dir/src/classes/trees/Tree.cpp.o -c /home/spl211/CLionProjects/spl_project_1/src/classes/trees/Tree.cpp

CMakeFiles/spl_project_1.dir/src/classes/trees/Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl_project_1.dir/src/classes/trees/Tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/spl_project_1/src/classes/trees/Tree.cpp > CMakeFiles/spl_project_1.dir/src/classes/trees/Tree.cpp.i

CMakeFiles/spl_project_1.dir/src/classes/trees/Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl_project_1.dir/src/classes/trees/Tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/spl_project_1/src/classes/trees/Tree.cpp -o CMakeFiles/spl_project_1.dir/src/classes/trees/Tree.cpp.s

CMakeFiles/spl_project_1.dir/src/classes/Graph.cpp.o: CMakeFiles/spl_project_1.dir/flags.make
CMakeFiles/spl_project_1.dir/src/classes/Graph.cpp.o: ../src/classes/Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/spl_project_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/spl_project_1.dir/src/classes/Graph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl_project_1.dir/src/classes/Graph.cpp.o -c /home/spl211/CLionProjects/spl_project_1/src/classes/Graph.cpp

CMakeFiles/spl_project_1.dir/src/classes/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl_project_1.dir/src/classes/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/spl_project_1/src/classes/Graph.cpp > CMakeFiles/spl_project_1.dir/src/classes/Graph.cpp.i

CMakeFiles/spl_project_1.dir/src/classes/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl_project_1.dir/src/classes/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/spl_project_1/src/classes/Graph.cpp -o CMakeFiles/spl_project_1.dir/src/classes/Graph.cpp.s

CMakeFiles/spl_project_1.dir/src/classes/Session.cpp.o: CMakeFiles/spl_project_1.dir/flags.make
CMakeFiles/spl_project_1.dir/src/classes/Session.cpp.o: ../src/classes/Session.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/spl_project_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/spl_project_1.dir/src/classes/Session.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl_project_1.dir/src/classes/Session.cpp.o -c /home/spl211/CLionProjects/spl_project_1/src/classes/Session.cpp

CMakeFiles/spl_project_1.dir/src/classes/Session.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl_project_1.dir/src/classes/Session.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/spl_project_1/src/classes/Session.cpp > CMakeFiles/spl_project_1.dir/src/classes/Session.cpp.i

CMakeFiles/spl_project_1.dir/src/classes/Session.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl_project_1.dir/src/classes/Session.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/spl_project_1/src/classes/Session.cpp -o CMakeFiles/spl_project_1.dir/src/classes/Session.cpp.s

CMakeFiles/spl_project_1.dir/src/main.cpp.o: CMakeFiles/spl_project_1.dir/flags.make
CMakeFiles/spl_project_1.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/spl_project_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/spl_project_1.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl_project_1.dir/src/main.cpp.o -c /home/spl211/CLionProjects/spl_project_1/src/main.cpp

CMakeFiles/spl_project_1.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl_project_1.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/spl_project_1/src/main.cpp > CMakeFiles/spl_project_1.dir/src/main.cpp.i

CMakeFiles/spl_project_1.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl_project_1.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/spl_project_1/src/main.cpp -o CMakeFiles/spl_project_1.dir/src/main.cpp.s

# Object files for target spl_project_1
spl_project_1_OBJECTS = \
"CMakeFiles/spl_project_1.dir/src/classes/agents/Agent.cpp.o" \
"CMakeFiles/spl_project_1.dir/src/classes/agents/ContactTracer.cpp.o" \
"CMakeFiles/spl_project_1.dir/src/classes/agents/Virus.cpp.o" \
"CMakeFiles/spl_project_1.dir/src/classes/trees/CycleTree.cpp.o" \
"CMakeFiles/spl_project_1.dir/src/classes/trees/MaxRankTree.cpp.o" \
"CMakeFiles/spl_project_1.dir/src/classes/trees/RootTree.cpp.o" \
"CMakeFiles/spl_project_1.dir/src/classes/trees/Tree.cpp.o" \
"CMakeFiles/spl_project_1.dir/src/classes/Graph.cpp.o" \
"CMakeFiles/spl_project_1.dir/src/classes/Session.cpp.o" \
"CMakeFiles/spl_project_1.dir/src/main.cpp.o"

# External object files for target spl_project_1
spl_project_1_EXTERNAL_OBJECTS =

spl_project_1: CMakeFiles/spl_project_1.dir/src/classes/agents/Agent.cpp.o
spl_project_1: CMakeFiles/spl_project_1.dir/src/classes/agents/ContactTracer.cpp.o
spl_project_1: CMakeFiles/spl_project_1.dir/src/classes/agents/Virus.cpp.o
spl_project_1: CMakeFiles/spl_project_1.dir/src/classes/trees/CycleTree.cpp.o
spl_project_1: CMakeFiles/spl_project_1.dir/src/classes/trees/MaxRankTree.cpp.o
spl_project_1: CMakeFiles/spl_project_1.dir/src/classes/trees/RootTree.cpp.o
spl_project_1: CMakeFiles/spl_project_1.dir/src/classes/trees/Tree.cpp.o
spl_project_1: CMakeFiles/spl_project_1.dir/src/classes/Graph.cpp.o
spl_project_1: CMakeFiles/spl_project_1.dir/src/classes/Session.cpp.o
spl_project_1: CMakeFiles/spl_project_1.dir/src/main.cpp.o
spl_project_1: CMakeFiles/spl_project_1.dir/build.make
spl_project_1: CMakeFiles/spl_project_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/spl211/CLionProjects/spl_project_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable spl_project_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spl_project_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/spl_project_1.dir/build: spl_project_1

.PHONY : CMakeFiles/spl_project_1.dir/build

CMakeFiles/spl_project_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spl_project_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spl_project_1.dir/clean

CMakeFiles/spl_project_1.dir/depend:
	cd /home/spl211/CLionProjects/spl_project_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/spl211/CLionProjects/spl_project_1 /home/spl211/CLionProjects/spl_project_1 /home/spl211/CLionProjects/spl_project_1/cmake-build-debug /home/spl211/CLionProjects/spl_project_1/cmake-build-debug /home/spl211/CLionProjects/spl_project_1/cmake-build-debug/CMakeFiles/spl_project_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spl_project_1.dir/depend

