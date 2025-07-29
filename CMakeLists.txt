cmake_minimum_required(VERSION 3.15)
project(septem_maria)

find_package(raylib 3.0 REQUIRED) # Requires at least version 3.0

set(CMAKE_C_STANDARD 11) # Requires C11 standard

set(GAME_INCLUDE inc)
set(GAME_SOURCE 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/input.c"
)

add_executable(${PROJECT_NAME} ${GAME_SOURCE})

target_include_directories(${PROJECT_NAME} PRIVATE ${GAME_INCLUDE})
target_link_libraries(${PROJECT_NAME} raylib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
