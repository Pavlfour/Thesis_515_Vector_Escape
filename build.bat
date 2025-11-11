@echo off
echo.
echo Building Vector Escape...
echo ---------------------------------------------
cd /d "%~dp0"
mingw32-make rebuild
REM Check if the build succeeded

if %errorlevel% neq 0 (
    echo Build failed!
    pause
    exit /b %errorlevel%
)

echo.
echo Build completed successfully!
echo ---------------------------------------------
echo Executable: "%~dp0VectorEscape.exe"
VectorEscape.exe
pause
