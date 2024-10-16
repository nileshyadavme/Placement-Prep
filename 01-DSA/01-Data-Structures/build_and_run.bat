@echo off
setlocal enabledelayedexpansion

REM Set the source file name (change this to your .cpp file name)
set SOURCE_FILE=TREE_BASICS.cpp

REM Set the output executable name
set OUTPUT_EXE=%SOURCE_FILE%.exe

REM Create build directory if it doesn't exist
if not exist build mkdir build

REM Compile the C++ program
g++ -std=c++11 %SOURCE_FILE% -o build\%OUTPUT_EXE%

REM Check if compilation was successful
if %errorlevel% equ 0 (
    echo Compilation successful. Executable saved in build\%OUTPUT_EXE%
) else (
    echo Compilation failed.
)

REM Run the program
echo Running the program:
build\%OUTPUT_EXE%

pause