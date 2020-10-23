$version="1.0.0"

Write-Output "packing contracts"
dotnet pack -p:Version=$version --verbosity -c Release -o ./ ../P23.MetaTrader4.Manager.Contracts.Core/P23.MetaTrader4.Manager.Contracts.Core.csproj

./nuget.exe push P23.MetaTrader4.Manager.Contracts.Core.$version.nupkg -source mohun -source mohun2 -configfile nuget.config -ApiKey dummy