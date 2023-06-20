# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/kesavan/Desktop/sqlite3/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kesavan/Desktop/sqlite3/build

# Include any dependencies generated for this target.
include Database/CMakeFiles/Database.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Database/CMakeFiles/Database.dir/compiler_depend.make

# Include the progress variables for this target.
include Database/CMakeFiles/Database.dir/progress.make

# Include the compile flags for this target's objects.
include Database/CMakeFiles/Database.dir/flags.make

Database/CMakeFiles/Database.dir/database.cpp.o: Database/CMakeFiles/Database.dir/flags.make
Database/CMakeFiles/Database.dir/database.cpp.o: /home/kesavan/Desktop/sqlite3/src/Database/database.cpp
Database/CMakeFiles/Database.dir/database.cpp.o: Database/CMakeFiles/Database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kesavan/Desktop/sqlite3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Database/CMakeFiles/Database.dir/database.cpp.o"
	cd /home/kesavan/Desktop/sqlite3/build/Database && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Database/CMakeFiles/Database.dir/database.cpp.o -MF CMakeFiles/Database.dir/database.cpp.o.d -o CMakeFiles/Database.dir/database.cpp.o -c /home/kesavan/Desktop/sqlite3/src/Database/database.cpp

Database/CMakeFiles/Database.dir/database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Database.dir/database.cpp.i"
	cd /home/kesavan/Desktop/sqlite3/build/Database && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kesavan/Desktop/sqlite3/src/Database/database.cpp > CMakeFiles/Database.dir/database.cpp.i

Database/CMakeFiles/Database.dir/database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Database.dir/database.cpp.s"
	cd /home/kesavan/Desktop/sqlite3/build/Database && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kesavan/Desktop/sqlite3/src/Database/database.cpp -o CMakeFiles/Database.dir/database.cpp.s

# Object files for target Database
Database_OBJECTS = \
"CMakeFiles/Database.dir/database.cpp.o"

# External object files for target Database
Database_EXTERNAL_OBJECTS =

Database/libDatabase.a: Database/CMakeFiles/Database.dir/database.cpp.o
Database/libDatabase.a: Database/CMakeFiles/Database.dir/build.make
Database/libDatabase.a: Database/CMakeFiles/Database.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kesavan/Desktop/sqlite3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libDatabase.a"
	cd /home/kesavan/Desktop/sqlite3/build/Database && $(CMAKE_COMMAND) -P CMakeFiles/Database.dir/cmake_clean_target.cmake
	cd /home/kesavan/Desktop/sqlite3/build/Database && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Database.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Database/CMakeFiles/Database.dir/build: Database/libDatabase.a
.PHONY : Database/CMakeFiles/Database.dir/build

Database/CMakeFiles/Database.dir/clean:
	cd /home/kesavan/Desktop/sqlite3/build/Database && $(CMAKE_COMMAND) -P CMakeFiles/Database.dir/cmake_clean.cmake
.PHONY : Database/CMakeFiles/Database.dir/clean

Database/CMakeFiles/Database.dir/depend:
	cd /home/kesavan/Desktop/sqlite3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kesavan/Desktop/sqlite3/src /home/kesavan/Desktop/sqlite3/src/Database /home/kesavan/Desktop/sqlite3/build /home/kesavan/Desktop/sqlite3/build/Database /home/kesavan/Desktop/sqlite3/build/Database/CMakeFiles/Database.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Database/CMakeFiles/Database.dir/depend

