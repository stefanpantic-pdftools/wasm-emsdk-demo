# WASM and Emscripten code usage samples

This repository contains code samples for several use cases of the Emscripten framework.

Emscripten contains several facilities which enable seamless integration of native C++ code into JavaScript web applications via WebAssembly. Emscripten includes a compiler (`emcc` and `em++`) which compiles LLVM code into WebAssembly, a library which enables creation and usage of native JavaScript objects directly inside C++ code, as well as facilities for exposing C++ functions to JavaScript via a JNI like interface called Embind. Emscripten also includes `emcmake`, a CMake wrapper which enables full usage of existing CMake build files.

For more info on Emscripten visit [emscripten.org](https://emscripten.org/).

## Samples

The following code samples are included in this repo:
1. [Compile C++ code to WebAssembly](01-cpp-to-wasm)
2. [Run C++ code in a browser window](02-run-cpp-in-browser)
3. [Call C++ code directly from JavaScript code](03-call-cpp-from-js)
4. [Bidirectional communication between C++ and JavaScript](04-bidirectional-communication)
5. [Debug C++/WASM code using symbol maps](05-symbol-maps)
6. [Debug C++/WASM code using DWARF symbols](06-dwarf-symbols)

