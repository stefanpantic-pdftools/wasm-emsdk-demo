from conans import CMake, ConanFile


class WasmDemoConan(ConanFile):
    name = "wasm-demo"
    version = "1.0.0"
    license = "MIT"
    author = "Stefan Pantic stefan.pantic@smallpdf.com"
    description = "A simple demo showing usage of the Emscripten library"
    topics = ("WASM", "C++", "Emscripten")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    generators = "cmake_find_package"
    exports_sources = "CMakeLists.txt", "main.cpp"

    build_requires = ("emsdk/3.1.29",)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("*.h", dst="include")
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)
