set(UTILITIES_ROOT nauEngine/nauUtilities CACHE STRING "Utilities source root")

include_directories(SYSTEM
    ${PROJECT_SOURCE_DIR}/${UTILITIES_ROOT}
    ${PROJECT_SOURCE_DIR}/${UTILITIES_ROOT}/include/
    )

set(UTILITIES_SOURCES
    ${PROJECT_SOURCE_DIR}/${UTILITIES_ROOT}/src/
    )

foreach(_source ${UTILITIES_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(utilitiesLibrary ${UTILITIES_SOURCES})