#!/usr/bin/env bash

# first execute qmake to create makefiles
qmake QtCha2PEntry.pro -spec linux-g++ -r 

# now make
make all

