@echo off
cmd /c chcp 65001
set filename=main
"C:\MinGW\bin\g++.exe" -fdiagnostics-color=always -g "./%filename%.cpp" -o "./%filename%.exe"
start "" /WAIT /B "./%filename%.exe"