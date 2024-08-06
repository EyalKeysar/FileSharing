@echo off

REM Create and navigate to the build directory
if not exist ..\build (
    mkdir ..\build
)
cd ..\build

REM Run CMake to configure the project
cmake ..

REM Build the project
cmake --build .

REM Check if the build was successful
if %errorlevel% equ 0 (
    echo Build succeeded. Executable is located in the build directory.
) else (
    echo Build failed.
    exit /b %errorlevel%
)
