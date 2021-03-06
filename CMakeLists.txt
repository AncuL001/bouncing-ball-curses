  #meta
cmake_minimum_required(VERSION 3.0.0)
project($ENV{PROJECT_NAME} VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ../bin)

#build routine
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.cxx" "src/*.c")
file(GLOB_RECURSE HEADER_FILES "src/*.h" "src/*.hpp")

add_executable($ENV{PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

set_target_properties($ENV{PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ../bin)

IF (UNIX)
  target_link_libraries(${PROJECT_NAME} m ncurses)

ELSE (WIN32)
  find_path(PDC_INCLUDES curses.h)
  find_library(PDC_LIBS pdcurses REQUIRED)

  target_include_directories(${PROJECT_NAME} PRIVATE 
    ${PDC_INCLUDES}
  )

  target_link_libraries(${PROJECT_NAME} PRIVATE 
    ${PDC_LIBS}
  )
ENDIF (UNIX)