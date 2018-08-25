project(SCA2)

cmake_minimum_required(VERSION 3.10)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(AMXConfig)
include(AddSAMPPlugin)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/amx
)

add_definitions(-DSAMPGDK_AMALGAMATION)

add_samp_plugin(SCA2 amxplugin.cpp library.cpp mainscript.h mainscript.cpp mdf.def sampgdk.c sampgdk.h pwnutils.h pwnutils.cpp)
