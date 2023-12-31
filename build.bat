@echo off 

@REM cls && node .\JS\_build.js && node .\JS\_run.js

cmake --build .\build --target all -j5 && .\build\Bee2D.exe