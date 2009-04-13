echo off

REM first start qmake to create makefile
qmake QtCha2PEntry.pro -spec win32-g++ -r 

REM make
mingw32-make.exe all
