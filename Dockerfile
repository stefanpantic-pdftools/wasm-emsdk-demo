FROM emscripten/emsdk:latest

RUN apt-get update

RUN apt-get install -y python3 python3-pip ninja-build build-essential cmake clang-14 libboost-all-dev

COPY . /wasm

WORKDIR /wasm

RUN conan install . -if ./build && conan build -bf ./build
