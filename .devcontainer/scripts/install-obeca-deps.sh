#!/usr/bin/env bash
# This script is intended to install OBECA depenecies
# Copyright 2022 Centro Tecnolóxico de Telecomunicacións de Galicia (Gradiant)

# 1. Install actual dependencies
sudo apt update
sudo apt install ssh g++ git libboost-atomic-dev libboost-thread-dev libboost-system-dev libboost-date-time-dev libboost-regex-dev libboost-filesystem-dev libboost-random-dev libboost-chrono-dev libboost-serialization-dev libwebsocketpp-dev openssl libssl-dev ninja-build libspdlog-dev libmbedtls-dev libboost-all-dev libconfig++-dev libsctp-dev libfftw3-dev vim libcpprest-dev libusb-1.0-0-dev net-tools smcroute python-psutil python3-pip clang-tidy gpsd gpsd-clients libgps-dev libgmime-3.0-dev libtinyxml2-dev libtinyxml2-6a -y
sudo snap install cmake --classic
sudo pip3 install cpplint

# 2. Install SDR Drivers
sudo apt install libsoapysdr-dev soapysdr-tools -y
# - Soapy
cd ~
git clone https://github.com/myriadrf/LimeSuite.git
cd LimeSuite/
git checkout 28031bfcffe1e8fa393c7db88d4fe370fb4c67ea
mkdir buildir
cd buildir
cmake -G Ninja ..
ninja
sudo ninja install
sudo ldconfig
# - BladeRF
sudo apt install soapysdr-module-bladerf -y
sudo bladeRF-install-firmware
# - HackRF
sudo apt install hackrf soapysdr-module-hackrf -y
# Troubleshooting
sudo apt remove liblimesuite20.01-1 -y
sudo apt remove soapysdr0.7-module-remote -y