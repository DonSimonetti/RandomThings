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

add_samp_plugin(RandomThings amxplugin.cpp library.cpp mdf.def sampgdk.c sampgdk.h pwnutils.h pwnutils.cpp GameMode.h GameMode.cpp Map.h Map.cpp MapsList.h MapsList.cpp)
