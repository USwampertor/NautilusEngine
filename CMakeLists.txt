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
include_directories(UTILITIES_INCLUDE ./nauEngine/nauUtilities/include/)
#include_directories(UTILITIES_SOURCE ./nauEngine/nauUtilities/src/)

set(UTILITIES_SOURCES 
    ./nauEngine/nauUtilities/src/nauPlatformMath.cpp
    ./nauEngine/nauUtilities/src/nauAABB.cpp
    ./nauEngine/nauUtilities/src/nauBox2d.cpp
    ./nauEngine/nauUtilities/src/nauDataStream.cpp
    ./nauEngine/nauUtilities/src/nauFrustrum.cpp
    ./nauEngine/nauUtilities/src/nauMatrix4.cpp
    ./nauEngine/nauUtilities/src/nauMatrix3.cpp
    ./nauEngine/nauUtilities/src/nauOOBB.cpp
    ./nauEngine/nauUtilities/src/nauPlane.cpp
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

#creates an executable which can be used to run in travis
add_library(Utilities SHARED ${UTILITIES_SOURCES})

################################################################################
# EXECUTABLE CREATION
################################################################################
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

#Project Name
project(GTESTUtilities)

#included libraries
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

target_link_libraries(UtilitiesTest Utilities ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries(UtilitiesTest gtestUtilities ${CMAKE_THREAD_LIBS_INIT})

target_compile_options(UtilitiesTest PUBLIC $<$<CXX_COMPILER_ID:Clang>:-std=c++14>)
target_link_libraries(UtilitiesTest $<$<AND:$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Intel>>,$<NOT:$<PLATFORM_ID:Windows>>>:-lstdc++fs>
                                    $<$<AND:$<CXX_COMPILER_ID:Clang>,$<NOT:$<OR:$<PLATFORM_ID:Windows>,$<PLATFORM_ID:MinGW>>>>:-lc++experimental>)


