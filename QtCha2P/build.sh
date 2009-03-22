#!/usr/bin/env bash

# first execute qmake to create makefiles
qmake QtCha2P.pro -spec linux-g++ -r 

# now make
make all

# generate documentation
doxygen doxyconfig
