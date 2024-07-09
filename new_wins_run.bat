@echo off
cmd /c chcp 65001
set filename=main
"C:\MinGW\bin\g++.exe" -fdiagnostics-color=always -g "./%filename%.cpp" -o "./%filename%.exe"
start "點擊enter結束視窗" /WAIT cmd /c "cmd /c chcp 65001 && start "by jukao" /B "./%filename%.exe" && set /p a="""