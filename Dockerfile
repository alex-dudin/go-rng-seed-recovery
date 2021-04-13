FROM ubuntu:20.04

RUN apt-get update \
 && apt-get upgrade -y \
 && apt-get install -y --no-install-recommends \
    gcc-10 g++-10 make pkg-config ca-certificates curl git wget zip unzip \
 && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 30 \
 && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 30 \
 && update-alternatives --install /usr/bin/cc cc /usr/bin/gcc 30 \
 && update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++ 30

RUN wget -q https://github.com/Kitware/CMake/releases/download/v3.19.6/cmake-3.19.6-Linux-x86_64.sh \
 && sh cmake-3.19.6-Linux-x86_64.sh --skip-license --prefix=/usr/local \
 && rm cmake-3.19.6-Linux-x86_64.sh

RUN git clone https://github.com/microsoft/vcpkg \
 && /vcpkg/bootstrap-vcpkg.sh -disableMetrics

COPY . /app/src

WORKDIR /app/build

RUN cmake -S /app/src -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=Release \
 && make
 
CMD set -x \
 && /app/build/go-rng-seed-recovery-test \
 && /app/build/go-rng-seed-recovery-benchmark \
 && /app/build/go-rng-seed-recovery-example
