CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

project(cpp-wasm)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_executable(${PROJECT_NAME} main.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:-g>
)

target_link_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:-g>
)

# Setting the suffix to .js makes emscripten emmit the necessary
# .js initialisation code which loads the WebAssembly Module
set_target_properties(${PROJECT_NAME} PROPERTIES
    SUFFIX ".js"
)

