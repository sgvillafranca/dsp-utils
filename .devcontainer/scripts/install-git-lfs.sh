#! /usr/bin/env bash
# This script is intended to install git lfs
# Copyright 2020 Centro Tecnolóxico de Telecomunicacións de Galicia (Gradiant)

if ! [ $(id -u) = 0 ]; then
    echo "The script need to be run as root." >&2
    exit 1
fi

curl -s https://packagecloud.io/install/repositories/github/git-lfs/script.deb.sh | sudo bash
apt-get install git-lfs
git lfs install