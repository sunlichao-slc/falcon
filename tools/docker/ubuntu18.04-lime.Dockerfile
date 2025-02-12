### the dependencies image
FROM ubuntu:18.04 as dependencies

LABEL maintainer="Yuncheng Wu <lemonwyc@gmail.com>"

RUN apt-get update && apt-get upgrade -y && \
        apt-get install -y --no-install-recommends \
        build-essential \
        libprotobuf-c0-dev \
        libprotobuf-dev \
        protobuf-compiler \
        python \
        python3 \
        python3-pip \
        libgoogle-glog-dev \
        libgtest-dev \
        pkg-config \
        wget \
        automake \
        ca-certificates \
        gdb \
        git \
        unzip \
        libjsoncpp-dev \
        liblog4cpp5-dev \
        libssl-dev \
        libtool \
        && \
        pip3 install requests && \
        apt-get clean && \
        rm -rf /var/lib/apt/lists/*

# Install
RUN dpkg-reconfigure dash

# Upgrade cmake version to 3.19.7
RUN mkdir /root/temp && \
    cd ~/temp && \
    wget https://cmake.org/files/v3.19/cmake-3.19.7.tar.gz && \
    tar -xzvf cmake-3.19.7.tar.gz && \
    cd cmake-3.19.7/ && \
    ./bootstrap && \
    make -j$(nproc) && \
    make install && \
    hash -r && \
    cmake --version

# Install glog library
WORKDIR /root/temp
RUN git clone https://github.com/google/glog.git && \
    cd glog && \
    cmake -H. -Bbuild -G "Unix Makefiles" && \
    cmake --build build

# Ln gtest library
RUN cd /usr/src/googletest/googletest && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    cp libgtest* /usr/lib/ && \
    cd .. && \
    rm -rf build && \
    mkdir /usr/local/lib/googletest && \
    ln -s /usr/lib/libgtest.a /usr/local/lib/googletest/libgtest.a && \
    ln -s /usr/lib/libgtest_main.a /usr/local/lib/googletest/libgtest_main.a

# Install Go 1.14
WORKDIR /root/temp/
RUN wget -q https://golang.org/dl/go1.14.13.linux-amd64.tar.gz -O go114.tar.gz && \
    tar xzf go114.tar.gz -C /usr/local

# Replace protoc version
WORKDIR /root/temp/
RUN git clone -b 'v3.14.0' --single-branch --depth 1 https://github.com/protocolbuffers/protobuf.git && \
    cd protobuf && \
    git submodule update --init --recursive && \
    ./autogen.sh && \
    ./configure && \
    make && \
    make check && \
    make install && \
    ldconfig && \
    protoc --version && \
    # the following add the protoc path to cmake config
    cd cmake && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && make install


### the build image that download the code and build
FROM ubuntu:18.04 as build

COPY --from=dependencies /usr/local /usr/local
COPY --from=dependencies /usr/bin /usr/bin
COPY --from=dependencies /usr/lib /usr/lib

RUN apt-get update && apt-get upgrade -y && \
        apt-get install -y --no-install-recommends \
        git \
        sqlite3 \
        curl \
        sudo \
        unzip \
        vim \
        wget \
        zip \
        ssh \
        libgmp-dev \
        libboost-dev \
        libboost-all-dev \
        libboost-system-dev \
        libboost-thread-dev \
        libcurl4-openssl-dev \
        build-essential \
        ca-certificates \
        gdb \
        git \
        unzip \
        libjsoncpp-dev \
        liblog4cpp5-dev \
        libssl-dev \
        libtool \
        m4 \
        texinfo \
        yasm \
        automake \
        libsodium-dev \
        libcrypto++-dev \
        libcrypto++-doc \
        libcrypto++-utils \
        autoconf \
        pkg-config \
        python \
        python3 \
        python3-pip \
        libgoogle-glog-dev \
        libgtest-dev \
        && \
        pip3 install requests && \
        apt-get clean && \
        rm -rf /var/lib/apt/lists/*

#Accept input argument
ARG SSH_PRIVATE_KEY

#Pass the content of the private key into the container
RUN mkdir /root/.ssh/
RUN echo "${SSH_PRIVATE_KEY}" > /root/.ssh/id_rsa

#Github requires a private key with strict permission settings
RUN chmod 600 /root/.ssh/id_rsa

#Add Github to known hosts
RUN touch /root/.ssh/known_hosts
RUN ssh-keyscan github.com >> /root/.ssh/known_hosts
RUN git config --global http.sslVerify false

# Clone Falcon and init submodules
RUN echo "update the falcon repository"
WORKDIR /opt
RUN ls -lht && \
    git clone git@github.com:lemonviv/falcon.git && \
    cd falcon && \
    git checkout lime && \
    cd third_party/ && \
    git submodule update --init --recursive

# Install third_party threshold partially homomorphic encryption library
WORKDIR /opt/falcon
RUN cd third_party/libhcs && \
    cmake . && \
    make && \
    make install

# Install third_party MP-SPDZ library
WORKDIR /opt/falcon
RUN cd third_party/MP-SPDZ && \
    mv CONFIG.mine.prod CONFIG.mine && \
    mv Math/Setup.h.prod Math/Setup.h && \
    make mpir && \
    bash fast-make.sh && \
    Scripts/setup-clients.sh 3 && \
    ./compile.py Programs/Source/logistic_regression.mpc && \
    ./compile.py Programs/Source/linear_regression.mpc && \
    ./compile.py Programs/Source/lime.mpc && \
    ./compile.py Programs/Source/vfl_decision_tree.mpc && \
    ln -s /opt/falcon/third_party/MP-SPDZ/local/lib/libmpir* /usr/local/lib/

# Install served library
WORKDIR /opt/falcon
RUN cd third_party/served && \
    mkdir cmake.build && \
    cd cmake.build && \
    cmake ../ && \
    make && \
    make install

# generate protobuf messages
WORKDIR /opt/falcon
RUN cd /opt/falcon/src/executor/include/proto && \
    SRC_DIR=v0/ && \
    DST_DIR=../message && \
    protoc -I=$SRC_DIR --cpp_out=$DST_DIR $SRC_DIR/*.proto

# build the falcon executor
WORKDIR /opt/falcon
RUN git pull
RUN export PATH="$PATH:$HOME/.local/bin" && \
    mkdir build && \
    cmake -Bbuild -H. && \
    cd build/ && \
    make


### the final release image
FROM ubuntu:18.04 as release

# copy data from the build image
COPY --from=build /opt/falcon /opt/falcon
COPY --from=build /usr/local /usr/local
COPY --from=build /usr/bin /usr/bin
COPY --from=build /usr/lib /usr/lib
COPY --from=build /root/.ssh /root/.ssh

COPY cmd_lime.sh /opt/falcon/

RUN apt-get update && apt-get upgrade -y && \
        apt-get install -y --no-install-recommends \
        git \
        build-essential \
        ca-certificates \
        libboost-dev \
        libboost-all-dev \
        libboost-system-dev \
        libboost-thread-dev \
        libgoogle-glog-dev \
        libgtest-dev \
        libsodium-dev \
        libcurl4-openssl-dev \
        libssl-dev \
        sudo && \
        apt-get clean && \
        rm -rf /var/lib/apt/lists/*

# Set environment variables.
ENV GOROOT /usr/local/go
ENV GOPATH /gopath
ENV PATH $GOROOT/bin:$GOPATH/bin:$PATH
ENV PATH /root/.local/bin:$PATH

WORKDIR /opt/falcon/src/falcon_platform
RUN bash make_platform.sh

WORKDIR /opt/falcon/third_party/MP-SPDZ
RUN c_rehash Player-Data/

# need to copy the experiment folder in the docker folder before copy
ADD experiments/ /opt/falcon/

# Define working directory.
WORKDIR /opt/falcon
RUN echo "re-build third-party mp-spdz"
COPY cmd_lime.sh /opt/falcon/
COPY cmd_lime_parallel.sh /opt/falcon/
# make third party MP-SPDZ
RUN cd third_party/MP-SPDZ && \
    bash fast-make.sh

WORKDIR /opt/falcon
RUN git pull origin lime && bash make.sh
CMD ["bash", "cmd_lime.sh"]