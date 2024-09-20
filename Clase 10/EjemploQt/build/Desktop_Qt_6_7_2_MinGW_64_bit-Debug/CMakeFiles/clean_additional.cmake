# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\EjemploQt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\EjemploQt_autogen.dir\\ParseCache.txt"
  "EjemploQt_autogen"
  )
endif()
