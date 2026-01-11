cmake_minimum_required(VERSION 3.28.3)

# -- Basic Const Initialization
set(CMAKE_CXX_STANDARD 20)
set(INCLUDE_DIRECTORY "include/" "include/tendrillion")
set(SOURCE_DIRECTORY "src/")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(minecrap_2_game_master)

# -- Fetch Content Initialization
include(FetchContent)
set(FETCHCONTENT_QUIET ON)
function(fetch_content_get name repository)
    message(${PROJECT_NAME} " -> fetching Resource: " ${name})
    FetchContent_Declare(${name} GIT_REPOSITORY ${repository})
    FetchContent_MakeAvailable(${name})
    message(${name} " Fetching Finished.")
endfunction()

# -- What platform are we on?
if (WIN32)
    add_compile_definitions(WIN32)
    message(STATUS "Building for WINDOWS environment...")
else ()
    add_compile_definitions(UNIX)
    message(STATUS "Building for UNIX/LINUX environment...")
endif ()

# -- Include directories.
include_directories(${INCLUDE_DIRECTORY})
include_directories(${SOURCE_DIRECTORY})

# -- Fetch content.
fetch_content_get(raylib https://github.com/raysan5/raylib.git)
fetch_content_get(nlohmann_json https://github.com/nlohmann/json.git)

# -- Hell no i don't want to define every source and header file on my own.
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "include/*.h")

# -- Link em' up!
link_libraries(raylib nlohmann_json::nlohmann_json)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${INCLUDE_DIRECTORY})
file(COPY "assets" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})