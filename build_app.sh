#!/bin/bash
(cd languages; python3 build.py)
git clone --branch v1.6.0 https://github.com/nayuki/QR-Code-generator.git
cd QR-Code-generator/cpp
make clean
make all
cd -
cp QR-Code-generator/cpp/QrCode.o ./qrcode.o
cp QR-Code-generator/cpp/QrCode.hpp ./qrcode.hpp
qmake
make
