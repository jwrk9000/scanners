Get-Service -Name MpsSvc | Format-Table -AutoSize


Get-Service -Name wuauserv | Format-Table -AutoSize


(Get-ItemProperty -Path 'HKLM:\Software\Microsoft\Windows\CurrentVersion\Policies\System').EnableLUA


Get-MpPreference | Format-List


Get-MpComputerStatus | Format-List


Get-NetFirewallProfile | Format-Table -AutoSize


Get-NetFirewallProfile | Select-Object Name, Enabled | Format-Table -AutoSize


$firewallStatus = Get-NetFirewallProfile | Select-Object -ExpandProperty Enabled
Write-Host "Windows Firewall Status: $firewallStatus"


Get-ComputerInfo | Format-List


Get-DnsClientServerAddress | Format-List


Get-NetIPAddress | Format-Table -Property InterfaceAlias, IPAddress, PrefixLength, AddressFamily -AutoSize


Get-NetTCPConnection | Format-Table -Property LocalAddress, LocalPort, RemoteAddress, RemotePort, State -AutoSize


Get-NetRoute | Format-Table -Property DestinationPrefix, InterfaceAlias, NextHop, RouteMetric -AutoSize


Get-NetFirewallProfile | Format-Table -Property Name, Enabled -AutoSize


Get-ChildItem Env: | Format-Table -Property Name, Value -AutoSize






Read-Host -Prompt "Press Enter to exit"