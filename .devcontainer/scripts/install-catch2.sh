#! /usr/bin/env bash
# This script is intended to install Catch2 from source
# Copyright 2020 Centro Tecnolóxico de Telecomunicacións de Galicia (Gradiant)

git clone https://github.com/catchorg/Catch2 
cd Catch2
mkdir build && cd build && cmake .. 
make && sudo make install && cd .. && cd .. && rm -r Catch2
