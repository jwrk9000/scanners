@echo off
set outputFile="%USERPROFILE%\Desktop\outputxxx.txt"
ipconfig /all >> %outputFile%
net start >> %outputFile%
tasklist /v >> %outputFile%
net user >> %outputFile%
net localgroup administrators >> %outputFile%
netstat -ano >> %outputFile%
net use >> %outputFile%
net view >> %outputFile%
net view /domain >> %outputFile%
net group /domain >> %outputFile%
net group "domain users" /domain >> %outputFile%
net group "domain admins" /domain >> %outputFile%
net group "domain controllers" /domain >> %outputFile%
net group "exchange domain servers" /domain >> %outputFile%
net group "exchange servers" /domain >> %outputFile%
net group "domain computers" /domain >> %outputFile%
