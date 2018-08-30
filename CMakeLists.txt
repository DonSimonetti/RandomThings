project(RandomThings)

set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.10)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(AMXConfig)
include(AddSAMPPlugin)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/amx
)

add_definitions(-DSAMPGDK_AMALGAMATION)

if(NOT BUILD_REVISION)
    set(BUILD_REVISION 0 CACHE STRING "")
else()
    math(EXPR BUILD_REVISION "${BUILD_REVISION} + 1")
endif()

add_definitions(-DBUILD_REVISION=${BUILD_REVISION})

add_samp_plugin(RandomThings amxplugin.cpp library.cpp mdf.def sampgdk.c sampgdk.h pwnutils.h pwnutils.cpp GameMode.h GameMode.cpp Map.h Map.cpp MapsList.h MapsList.cpp)
