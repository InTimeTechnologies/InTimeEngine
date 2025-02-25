@echo off
setlocal enabledelayedexpansion

set outputDir="D:\source\vs_repos\InTimeEngine\InTimeEngine\shader_out"
if exist "%outputDir%" (
    cd /d %outputDir%
    REM Process each file in the directory
    for /R %%F in (*) do (
        set "extension=%%~xF"
        set "extensionMatched="

        REM Check if the file has valid extension (spv, vert, frag, geom, etc.)
        if /i "!extension!"==".vert" (
            set "extensionMatched=true"
        ) else if /i "!extension!"==".frag" (
            set "extensionMatched=true"
        ) else if /i "!extension!"==".geom" (
            set "extensionMatched=true"
        ) else if /i "!extension!"==".tesc" (
            set "extensionMatched=true"
        ) else if /i "!extension!"==".tese" (
            set "extensionMatched=true"
        ) else if /i "!extension!"==".comp" (
            set "extensionMatched=true"
        ) else if /i "!extension!"==".rgen" (
            set "extensionMatched=true"
        ) else if /i "!extension!"==".rahit" (
            set "extensionMatched=true"
        ) else if /i "!extension!"==".rchit" (
            set "extensionMatched=true"
        ) else if /i "!extension!"==".rmiss" (
            set "extensionMatched=true"
        ) else if /i "!extension!"==".shader" (
            set "extensionMatched=true"
        ) else if /i "!extension!"==".glsl" (
            set "extensionMatched=true"
        ) else if /i "!extension!"==".spv" (
            set "extensionMatched=true"
        ) else (
            echo Skipping: %%F
        )

        if defined extensionMatched (
            echo deleting "!%%F!"
            del %%F
        )
    )
)

echo shader binaries clean complete.
exit
