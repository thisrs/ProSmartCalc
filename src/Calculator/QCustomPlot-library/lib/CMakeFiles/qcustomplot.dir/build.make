# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src

# Include any dependencies generated for this target.
include QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/compiler_depend.make

# Include the progress variables for this target.
include QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/progress.make

# Include the compile flags for this target's objects.
include QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/flags.make

QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.o: QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/flags.make
QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.o: QCustomPlot-library/lib/qcustomplot_autogen/mocs_compilation.cpp
QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.o: QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.o"
	cd /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.o -MF CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.o -c /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib/qcustomplot_autogen/mocs_compilation.cpp

QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.i"
	cd /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib/qcustomplot_autogen/mocs_compilation.cpp > CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.i

QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.s"
	cd /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib/qcustomplot_autogen/mocs_compilation.cpp -o CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.s

QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot.cpp.o: QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/flags.make
QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot.cpp.o: QCustomPlot-library/lib/qcustomplot.cpp
QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot.cpp.o: QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot.cpp.o"
	cd /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot.cpp.o -MF CMakeFiles/qcustomplot.dir/qcustomplot.cpp.o.d -o CMakeFiles/qcustomplot.dir/qcustomplot.cpp.o -c /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib/qcustomplot.cpp

QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qcustomplot.dir/qcustomplot.cpp.i"
	cd /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib/qcustomplot.cpp > CMakeFiles/qcustomplot.dir/qcustomplot.cpp.i

QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qcustomplot.dir/qcustomplot.cpp.s"
	cd /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib/qcustomplot.cpp -o CMakeFiles/qcustomplot.dir/qcustomplot.cpp.s

# Object files for target qcustomplot
qcustomplot_OBJECTS = \
"CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/qcustomplot.dir/qcustomplot.cpp.o"

# External object files for target qcustomplot
qcustomplot_EXTERNAL_OBJECTS =

build/output/amd64/Debug/lib/libqcustomplot.2.1.1.dylib: QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot_autogen/mocs_compilation.cpp.o
build/output/amd64/Debug/lib/libqcustomplot.2.1.1.dylib: QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/qcustomplot.cpp.o
build/output/amd64/Debug/lib/libqcustomplot.2.1.1.dylib: QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/build.make
build/output/amd64/Debug/lib/libqcustomplot.2.1.1.dylib: /Users/admin/Qt/6.3.1/macos/lib/QtPrintSupport.framework/Versions/A/QtPrintSupport
build/output/amd64/Debug/lib/libqcustomplot.2.1.1.dylib: /Users/admin/Qt/6.3.1/macos/lib/QtWidgets.framework/Versions/A/QtWidgets
build/output/amd64/Debug/lib/libqcustomplot.2.1.1.dylib: /Users/admin/Qt/6.3.1/macos/lib/QtGui.framework/Versions/A/QtGui
build/output/amd64/Debug/lib/libqcustomplot.2.1.1.dylib: /Users/admin/Qt/6.3.1/macos/lib/QtCore.framework/Versions/A/QtCore
build/output/amd64/Debug/lib/libqcustomplot.2.1.1.dylib: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.3.sdk/usr/lib/libcups.tbd
build/output/amd64/Debug/lib/libqcustomplot.2.1.1.dylib: QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../../build/output/amd64/Debug/lib/libqcustomplot.dylib"
	cd /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qcustomplot.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib && $(CMAKE_COMMAND) -E cmake_symlink_library ../../build/output/amd64/Debug/lib/libqcustomplot.2.1.1.dylib ../../build/output/amd64/Debug/lib/libqcustomplot.2.dylib ../../build/output/amd64/Debug/lib/libqcustomplot.dylib

build/output/amd64/Debug/lib/libqcustomplot.2.dylib: build/output/amd64/Debug/lib/libqcustomplot.2.1.1.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate build/output/amd64/Debug/lib/libqcustomplot.2.dylib

build/output/amd64/Debug/lib/libqcustomplot.dylib: build/output/amd64/Debug/lib/libqcustomplot.2.1.1.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate build/output/amd64/Debug/lib/libqcustomplot.dylib

# Rule to build all files generated by this target.
QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/build: build/output/amd64/Debug/lib/libqcustomplot.dylib
.PHONY : QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/build

QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/clean:
	cd /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib && $(CMAKE_COMMAND) -P CMakeFiles/qcustomplot.dir/cmake_clean.cmake
.PHONY : QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/clean

QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/depend:
	cd /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib /Users/admin/S21/CPP3_SmartCalc_v2.0-0/src/QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : QCustomPlot-library/lib/CMakeFiles/qcustomplot.dir/depend

