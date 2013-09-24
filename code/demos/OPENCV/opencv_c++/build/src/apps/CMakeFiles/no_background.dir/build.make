# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/peko/tfg_git/code/demos/opencv_c++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/peko/tfg_git/code/demos/opencv_c++/build

# Include any dependencies generated for this target.
include src/apps/CMakeFiles/no_background.dir/depend.make

# Include the progress variables for this target.
include src/apps/CMakeFiles/no_background.dir/progress.make

# Include the compile flags for this target's objects.
include src/apps/CMakeFiles/no_background.dir/flags.make

src/apps/CMakeFiles/no_background.dir/no_background.cpp.o: src/apps/CMakeFiles/no_background.dir/flags.make
src/apps/CMakeFiles/no_background.dir/no_background.cpp.o: ../src/apps/no_background.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/peko/tfg_git/code/demos/opencv_c++/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/apps/CMakeFiles/no_background.dir/no_background.cpp.o"
	cd /home/peko/tfg_git/code/demos/opencv_c++/build/src/apps && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/no_background.dir/no_background.cpp.o -c /home/peko/tfg_git/code/demos/opencv_c++/src/apps/no_background.cpp

src/apps/CMakeFiles/no_background.dir/no_background.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/no_background.dir/no_background.cpp.i"
	cd /home/peko/tfg_git/code/demos/opencv_c++/build/src/apps && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/peko/tfg_git/code/demos/opencv_c++/src/apps/no_background.cpp > CMakeFiles/no_background.dir/no_background.cpp.i

src/apps/CMakeFiles/no_background.dir/no_background.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/no_background.dir/no_background.cpp.s"
	cd /home/peko/tfg_git/code/demos/opencv_c++/build/src/apps && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/peko/tfg_git/code/demos/opencv_c++/src/apps/no_background.cpp -o CMakeFiles/no_background.dir/no_background.cpp.s

src/apps/CMakeFiles/no_background.dir/no_background.cpp.o.requires:
.PHONY : src/apps/CMakeFiles/no_background.dir/no_background.cpp.o.requires

src/apps/CMakeFiles/no_background.dir/no_background.cpp.o.provides: src/apps/CMakeFiles/no_background.dir/no_background.cpp.o.requires
	$(MAKE) -f src/apps/CMakeFiles/no_background.dir/build.make src/apps/CMakeFiles/no_background.dir/no_background.cpp.o.provides.build
.PHONY : src/apps/CMakeFiles/no_background.dir/no_background.cpp.o.provides

src/apps/CMakeFiles/no_background.dir/no_background.cpp.o.provides.build: src/apps/CMakeFiles/no_background.dir/no_background.cpp.o

# Object files for target no_background
no_background_OBJECTS = \
"CMakeFiles/no_background.dir/no_background.cpp.o"

# External object files for target no_background
no_background_EXTERNAL_OBJECTS =

../bin/no_background: src/apps/CMakeFiles/no_background.dir/no_background.cpp.o
../bin/no_background: ../lib/libfunctions.a
../bin/no_background: /opt/ros/groovy/lib/libopencv_calib3d.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_contrib.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_core.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_features2d.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_flann.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_gpu.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_highgui.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_imgproc.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_legacy.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_ml.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_nonfree.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_objdetect.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_photo.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_stitching.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_ts.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_video.so
../bin/no_background: /opt/ros/groovy/lib/libopencv_videostab.so
../bin/no_background: src/apps/CMakeFiles/no_background.dir/build.make
../bin/no_background: src/apps/CMakeFiles/no_background.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../bin/no_background"
	cd /home/peko/tfg_git/code/demos/opencv_c++/build/src/apps && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/no_background.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/apps/CMakeFiles/no_background.dir/build: ../bin/no_background
.PHONY : src/apps/CMakeFiles/no_background.dir/build

src/apps/CMakeFiles/no_background.dir/requires: src/apps/CMakeFiles/no_background.dir/no_background.cpp.o.requires
.PHONY : src/apps/CMakeFiles/no_background.dir/requires

src/apps/CMakeFiles/no_background.dir/clean:
	cd /home/peko/tfg_git/code/demos/opencv_c++/build/src/apps && $(CMAKE_COMMAND) -P CMakeFiles/no_background.dir/cmake_clean.cmake
.PHONY : src/apps/CMakeFiles/no_background.dir/clean

src/apps/CMakeFiles/no_background.dir/depend:
	cd /home/peko/tfg_git/code/demos/opencv_c++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/peko/tfg_git/code/demos/opencv_c++ /home/peko/tfg_git/code/demos/opencv_c++/src/apps /home/peko/tfg_git/code/demos/opencv_c++/build /home/peko/tfg_git/code/demos/opencv_c++/build/src/apps /home/peko/tfg_git/code/demos/opencv_c++/build/src/apps/CMakeFiles/no_background.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/apps/CMakeFiles/no_background.dir/depend
