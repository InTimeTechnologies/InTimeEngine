@echo off

set outputDir="D:\source\vs_repos\InTimeEngine\InTimeEngine\shader_out"
if exist "%outputDir%" (
    cd /d %outputDir%
    for /F "delims=" %%i in ('dir /b') do (
        rmdir "%%i" /s/q || del "%%i" /s/q
    )
)
