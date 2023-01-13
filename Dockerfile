FROM ubuntu:latest

RUN apt-get update --allow-insecure-repositories

RUN apt-get install -y python3 python3-pip ninja-build build-essential cmake clang

RUN pip3 install conan

RUN conan init