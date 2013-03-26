@echo off
:main

gen

Task
Task_true

fc output.txt output_true.txt > nul
if errorlevel 1 goto error

:next
echo ok
goto main

:error
echo failed check