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
        REM echo Compiling vertex shader: %%F
        REM "%glslc%" "%%F" -o "%outputDir%\%%~nF.spv"
        set "extensionMatched=true"
    ) else if /i "!extension!"==".frag" (
        REM echo Compiling shader: %%F
        REM "%glslc%" "%%F" -o "%outputDir%\%%~nF.spv"
        set "extensionMatched=true"
    ) else if /i "!extension!"==".geom" (
        REM Compiling shader: %%F
        REM "%glslc%" "%%F" -o "%outputDir%\%%~nF.spv"
        set "extensionMatched=true"
    ) else if /i "!extension!"==".tesc" (
        REM Compiling control shader: %%F
        REM "%glslc%" "%%F" -o "%outputDir%\%%~nF.spv"
        set "extensionMatched=true"
    ) else if /i "!extension!"==".tese" (
        REM Compiling shader: %%F
        REM "%glslc%" "%%F" -o "%outputDir%\%%~nF.spv"
        set "extensionMatched=true"
    ) else if /i "!extension!"==".comp" (
        REM Compiling shader: %%F
        REM "%glslc%" "%%F" -o "%outputDir%\%%~nF.spv"
        set "extensionMatched=true"
    ) else if /i "!extension!"==".rgen" (
        REM Compiling generation shader: %%F
        REM "%glslc%" "%%F" -o "%outputDir%\%%~nF.spv"
        set "extensionMatched=true"
    ) else if /i "!extension!"==".rahit" (
        REM Compiling ray hit  shader: %%F
        REM "%glslc%" "%%F" -o "%outputDir%\%%~nF.spv"
        set "extensionMatched=true"
    ) else if /i "!extension!"==".rchit" (
        REM Compiling ray c hit shader: %%F
        REM "%glslc%" "%%F" -o "%outputDir%\%%~nF.spv"
        set "extensionMatched=true"
    ) else if /i "!extension!"==".rmiss" (
        REM Compiling ray miss shader: %%F
        REM "%glslc%" "%%F" -o "%outputDir%\%%~nF.spv"
        set "extensionMatched=true"
    ) else if /i "!extension!"==".shader" (
        REM Compiling shader: %%F
        REM "%glslc%" "%%F" -o "%outputDir%\%%~nF.spv"
        set "extensionMatched=true"
    ) else if /i "!extension!"==".glsl" (
        REM Compiling glsl shader: %%F
        REM "%glslc%" "%%F" -o "%outputDir%\%%~nF.spv"
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
        "%glslc%" "!filePath!" -o "!outputDir!\!localPath!"
    )
)

echo Compilation completed.
pause
exit
