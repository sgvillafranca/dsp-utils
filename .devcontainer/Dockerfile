# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.166.1/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version: debian-10, debian-9, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# Avoid warnings by switching to noninteractive
RUN export DEBIAN_FRONTEND=noninteractive && sudo apt-get update -qq && sudo apt-get upgrade -y -qq 

# Install Dependencies:
# Cookiecutter
RUN sudo apt-get update \
    && sudo apt-get -y install python3-pip && cmake && pip3 install cookiecutter
# Catch2
RUN git clone https://github.com/catchorg/Catch2  \
&& cd Catch2 \
&& mkdir build && cd build && cmake .. \ 
&& make && sudo make install && cd .. && cd .. && rm -r Catch2
# Install OPENBLAS & LAPACK
RUN sudo apt-get -y install libopenblas-dev liblapack-dev libarpack2-dev libsuperlu-dev
# Install Armadillo
RUN wget http://sourceforge.net/projects/arma/files/armadillo-9.800.4.tar.xz \
    && tar -xvf armadillo-9.800.4.tar.xz \
    && cd armadillo-9.800.4 \
    && ./configure && make && sudo make install \
    && cd .. && rm -r armadillo-9.800.4*
# Install FFTW
RUN sudo apt install libfftw3-dev -y
# GCC10
RUN sudo apt-get install -y -qq gcc-10 g++-10

# Set Timezone 
RUN sudo rm -rf /etc/localtime 
RUN sudo ln -s /usr/share/zoneinfo/Europe/Madrid /etc/localtime


