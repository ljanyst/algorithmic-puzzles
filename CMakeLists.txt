project(centipede)

cmake_minimum_required(VERSION 3.5)

macro(add_puzzle name)
  add_executable(${name} ${name}.cc)
endmacro()

add_subdirectory(01-arrays)
