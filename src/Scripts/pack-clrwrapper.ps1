$version="1.0.0"

$searchPath = [System.Environment]::GetEnvironmentVariable("Path")
# Copy-Item ../../mq4/MtApi.ex4 ./build/MtApi.ex4 -Force
# [Environment]::SetEnvironmentVariable("Path", "$searchPath;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\16.0\Bin")
[Environment]::SetEnvironmentVariable("Path", "$searchPath;C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\MSBuild\Current\Bin;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\16.0\Bin;E:\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin")
#cmd.exe /c "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\Common7\\Tools\\VsMSBuildCmd.bat"
Write-Output "building clrwrapper..."
msbuild ../P23.MetaTrader4.Manager.ClrWrapper.Core/P23.MetaTrader4.Manager.ClrWrapper.Core.vcxproj -target:clean -target:restore -target:build -p:configuration=Release -p:platform=win32
Write-Output "build clrwrapper nuget package..."
./nuget.exe pack .\clrwrapper.nuspec -Version $version

Write-Output "pushing clrwrapper package"
./nuget.exe push P23.MetaTrader4.Manager.ClrWrapper.Core.$version.nupkg -source mohun -source mohun2 -configfile nuget.config -ApiKey dummy

