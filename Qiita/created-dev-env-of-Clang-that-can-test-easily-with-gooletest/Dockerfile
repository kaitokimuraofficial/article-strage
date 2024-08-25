FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    curl \
    git \
    tar \
    vim \
    && rm -rf /var/lib/apt/lists/*

RUN curl -L https://github.com/Kitware/CMake/releases/download/v3.30.2/cmake-3.30.2-linux-aarch64.tar.gz -o cmake.tar.gz \
    && tar -zxvf cmake.tar.gz --strip-components=1 -C /usr/local \
    && rm cmake.tar.gz

RUN cmake --version

WORKDIR /my_project

COPY ./tests tests
COPY ./src src
WORKDIR /my_project/tests

RUN cmake -S . -B build

RUN cmake --build build

RUN cd build && ctest --output-on-failure

