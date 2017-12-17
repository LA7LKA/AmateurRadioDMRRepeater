@echo off
C:\Keil\C51\BIN\A51.EXE %*
if "%ERRORLEVEL%"=="0" goto no_error
if "%ERRORLEVEL%"=="1" goto no_error
if "%ERRORLEVEL%"=="2" goto error
if "%ERRORLEVEL%"=="3" goto error
:no_error
exit /b 0
:error
exit /b 1
