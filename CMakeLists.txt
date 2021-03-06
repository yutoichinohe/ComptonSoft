####### CMakeLists.txt for Compton Soft

cmake_minimum_required(VERSION 2.8)

### Initial definition of cmake variables
set(CMAKE_INSTALL_PREFIX $ENV{HOME} CACHE PATH "install prefix")
set(CMAKE_BUILD_TYPE Release CACHE STRING "build type")
set(CMAKE_CXX_FLAGS_DEBUG "-g -W -Wall" CACHE STRING "CXX_FLAGS for debug")
set(CMAKE_C_FLAGS_DEBUG "-g -W -Wall" CACHE STRING "C_FLAGS for debug")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -W -Wall" CACHE STRING "CXX_FLAGS for release")
set(CMAKE_C_FLAGS_RELEASE "-O3 -W -Wall" CACHE STRING "C_FLAGS for release")

### Definition of project
project(ComptonSoft)
set(CMAKE_MODULE_PATH ${ComptonSoft_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

message("-- Install destination prefix: ${CMAKE_INSTALL_PREFIX}")

### options
## interface options
option(CS_USE_RUBY "enable Ruby binding" ON)
option(CS_USE_EXE "enable standalone executables" OFF)
## library options
option(CS_USE_GDML "enable GDML" ON)
option(CS_USE_FITSIO "enable FITS IO" OFF)
option(CS_USE_SIMX "enable SimX compatible simulation" OFF)
option(CS_USE_VIS "enable visualization with OpenGL" OFF)
option(CS_USE_VIS_QT "enable visualization with Qt" OFF)
option(CS_USE_ROOT "enable ROOT analysis framework" ON)
option(CS_USE_SYSTEM_CLHEP "use system-clhep" OFF)
## install options
option(CS_INSTALL_HEADERS "install all header files" ON)
option(CS_INSTALL_CMAKE_FILES "install all cmake files" ON)
## shortcut options
option(CS_AHSIM_BASIC "enable libraries for ASTRO-H simulations" OFF)
option(CS_ALL "enable all library options" OFF)

if(CS_ALL)
  set(CS_USE_GDML ON)
  set(CS_USE_FITSIO ON)
  set(CS_USE_SIMX ON)
  set(CS_USE_VIS_QT ON)
  set(CS_USE_ROOT ON)
endif(CS_ALL)

if(CS_AHSIM_BASIC)
  set(CS_USE_SIMX ON)
  set(CS_USE_ROOT OFF)
endif(CS_AHSIM_BASIC)

set(USE_RUBY ${CS_USE_RUBY})
set(USE_EXE ${CS_USE_EXE})
set(INSTALL_HEADERS ${CS_INSTALL_HEADERS})
set(INSTALL_CMAKE_FILES ${CS_INSTALL_CMAKE_FILES})
set(ANLG4_USE_GDML ${CS_USE_GDML})
set(ANLG4_USE_VIS ${CS_USE_VIS})
set(ANLG4_USE_VIS_QT ${CS_USE_VIS_QT})

### include definitions
include(def_cs)

### subdirectories
add_subdirectory(anlgeant4)
add_subdirectory(source)

if(USE_EXE)
  add_subdirectory(executables)
endif(USE_EXE)

if(USE_RUBY)
  add_subdirectory(ruby)
  add_subdirectory(scripts)
endif(USE_RUBY)

add_subdirectory(cmake)

### END
