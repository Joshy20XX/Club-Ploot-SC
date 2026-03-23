# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ClubPloot_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ClubPloot_autogen.dir\\ParseCache.txt"
  "ClubPloot_autogen"
  )
endif()
