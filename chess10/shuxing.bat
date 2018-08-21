@echo off
set rr="HKEY_CURRENT_USER\Console\C:_Users_huangfeibang_Desktop_chess_chess10_playchess.exe"
reg add %rr% /v "WindowPosition" /t REG_DWORD /d 0x00000000 /f>nul
reg add %rr% /v "WindowSize" /t REG_DWORD /d 0x00140037 /f>nul
reg add %rr% /v "ScreenBufferSize" /t REG_DWORD /d 0x00200038 /f>nul
reg add %rr% /v "FullScreen" /t REG_DWORD /d 0x00000001 /f>nul
reg add %rr% /v "FontFamily" /t REG_DWORD /d 0x00000036 /f>nul
reg add %rr% /v "FontSize" /t REG_DWORD /d 0x00480000 /f>nul
reg add %rr% /v "QuickEdit" /t REG_DWORD /d 0x00000000 /f>nul
start playchess.exe