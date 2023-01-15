CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

project(js-symbol-map)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_executable(${PROJECT_NAME} js_symbol_map.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE
    "SHELL:-s DISABLE_EXCEPTION_CATCHING=0"
    $<$<CONFIG:Debug>:-gsource-map>
)

target_link_options(${PROJECT_NAME} PRIVATE
    "SHELL:-s ALLOW_MEMORY_GROWTH=1"
    "SHELL:-s DISABLE_EXCEPTION_CATCHING=0"
    "SHELL:-s ENVIRONMENT=web"
    "SHELL:-s FETCH=1"
    "SHELL:-s LZ4=1"
    "SHELL:-s NO_EXIT_RUNTIME=1"
    "SHELL:-s WARN_ON_UNDEFINED_SYMBOLS=1"
    "SHELL:-s DYNAMIC_EXECUTION=0"
    $<$<CONFIG:Debug>:-gsource-map>
    -lembind
)

# Setting the suffix to .js makes emscripten emmit the necessary
# .js initialisation code which loads the WebAssembly Module
set_target_properties(${PROJECT_NAME} PROPERTIES
    SUFFIX ".js"
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/js-symbol-map.js
              ${CMAKE_CURRENT_BINARY_DIR}/js-symbol-map.wasm
              ${CMAKE_CURRENT_BINARY_DIR}/js-symbol-map.wasm.map
        DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/)
