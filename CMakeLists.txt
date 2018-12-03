################################################################################
# LIBRARY CREATION
################################################################################
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

#Project name
project(UtilitiesLibrary)

#Prerequisites
set(CMAKE_CXX_FLAGS)
SET(COVERAGE OFF CACHE BOOL "Coverage")

#include libraries
include_directories(UTLITIES_INCLUDE ./nauEngine/nauUtilities/include/)


set(UTILITIES_SOURCES 
    ./nauEngine/nauUtilities/src/nauAABB.cpp
    ./nauEngine/nauUtilities/src/nauBox2d.cpp
    ./nauEngine/nauUtilities/src/nauDataStream.cpp
    ./nauEngine/nauUtilities/src/nauFrustrum.cpp
    ./nauEngine/nauUtilities/src/nauMatrix.cpp
    ./nauEngine/nauUtilities/src/nauOOBB.cpp
    ./nauEngine/nauUtilities/src/nauPlane.cpp
    ./nauEngine/nauUtilities/src/nauPlatformMath.cpp
    ./nauEngine/nauUtilities/src/nauQuaternion.cpp
    ./nauEngine/nauUtilities/src/nauRandom.cpp
    ./nauEngine/nauUtilities/src/nauRay.cpp
    ./nauEngine/nauUtilities/src/nauSphere.cpp
    ./nauEngine/nauUtilities/src/nauTriangle.cpp
    ./nauEngine/nauUtilities/src/nauVector2.cpp
    ./nauEngine/nauUtilities/src/nauVector2i.cpp
    ./nauEngine/nauUtilities/src/nauVector3.cpp
    ./nauEngine/nauUtilities/src/nauVector4.cpp
    )


foreach(_source ${UTILITIES_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

#creates an executable which can be used to run in travis
add_library(Utilities ${TARGET_SRC})

################################################################################
# EXECUTABLE CREATION
################################################################################
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

#Project Name
project(GTESTUtilities)

#included libraries
include(Utilities)
include(gtestUtilities.cmake)


#Prerequisites
set(CMAKE_CXX_FLAGS)
SET(COVERAGE OFF CACHE BOOL "Coverage")
find_package (Threads)

#This variables are for setting the minimum and maximun requires for unitTesting
set(UNITTESTING_VERSION_MAJOR 1)
set(UNITTESTING_VERSION_MINOR 0)
set(LEARN_CMAKE_VERSION_PATCH 0)

#sets cmake to debug build
set(CMAKE_BUILD_TYPE Debug)

#Debug Mode
enable_testing()

SET(TARGET_SRC ./nauEngine/nauUtilities_UnitTest/src/main.cpp)

#creates an executable which can be used to run in travis
add_executable(UtilitiesTest ${TARGET_SRC})

target_link_libraries(UtilitiesTest gtestUtilities ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(UtilitiesTest Utilities ${CMAKE_THREAD_LIBS_INIT})


