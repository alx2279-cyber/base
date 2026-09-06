@echo off
setlocal

set "VS_PATH=C:\Program Files\Microsoft Visual Studio\2022\Community"
call "%VS_PATH%\VC\Auxiliary\Build\vcvars64.bat"

set "INCLUDES=/I.\ /I.\src /I.\src\render /I.\src\imgui"
set "SOURCES=main.cpp .\src\render\*.cpp .\src\imgui\*.cpp"
set "LIBS=d3d11.lib dwmapi.lib"
set "CFLAGS=/EHsc /O2 /MT"

echo Compiling AI Cheat Base...
cl %CFLAGS% %INCLUDES% %SOURCES% %LIBS% /Fe:CheatBase.exe

if %errorlevel% neq 0 (
    echo Compilation failed!
    pause
    exit /b %errorlevel%
)

echo Success! CheatBase.exe created.
pause
