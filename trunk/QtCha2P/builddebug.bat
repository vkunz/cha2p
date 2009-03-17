REM first start qmake to create makefile
qmake QtCha2P.pro -spec win32-g++ -r CONFI+=debug_and_release
REM make
mingw32-make.exe release -w