# Boilerplate CMake Code ##############################
cmake_minimum_required(VERSION 3.14)
project(ChantsAdventure VERSION 0.0.0)

# C++ Standard 14 at the least is required for gtest
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add any subdirectories, the order is important. Library must be created first before the exe
add_subdirectory(src) # .cpp
add_subdirectory(app) # location of main
add_subdirectory(inc) # .h and .hpp
# End Biolerplate ####################################

############ START GTEST ##############################
include(FetchContent)

# Declare googletest dependency
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1  # Use the latest stable version of Google Test
)

# Ensure googletest is available
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add subdirectory for tests
add_subdirectory(tests)
