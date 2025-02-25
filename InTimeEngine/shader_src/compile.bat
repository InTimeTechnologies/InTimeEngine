@echo off
setlocal enabledelayedexpansion

set "sourceDir=%~dp0"
set "glslc=%VK_SDK_PATH%\Bin\glslc.exe"
set "outputDir=D:\source\vs_repos\InTimeEngine\InTimeEngine\shader_out"

REM Create output directory if it doesn't exist
if not exist "%outputDir%" mkdir "%outputDir%"

echo source directory:   %sourceDir%
echo compiler directory: %glslc%
echo output directory:   %outputDir%

REM Process each file in the directory
for /R %%F in (*) do (
    set "extension=%%~xF"
    set "extensionMatched="

    REM Check if the file has valid extension (vert, frag, geom, etc.)
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
    ) else (
        echo Skipping: %%F
    )
    
    if defined extensionMatched (
        REM Get the file extension
        set "filePath=%%F"
        set "localPath=!filePath:%sourceDir%=!"
        REM set "fileName=%%~nxF"
        REM set "fileNameWithoutExtension=%%~nF"
        set "parentPath=%%~dpF"
        set "outputDirectoryStructure=!outputDir!\!parentPath:%sourceDir%=!"

        REM echo localPath "!localPath!"
        REM echo outputDir "!outputDir!"
        REM echo parentPath "!parentPath!"

        if not exist "!outputDirectoryStructure!" (
            mkdir "!outputDirectoryStructure!"
        )

        echo compiling "!filePath!" -o "!outputDir!\!localPath!"
        echo ".\%glslc%" "!filePath!" -o "!outputDir!\!localPath!"
        "%glslc%" "!filePath!" -o "!outputDir!\!localPath!.spv"
    )
)

echo Compilation completed.
exit
