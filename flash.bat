echo off
rem cls

set project_name=can_buttons_L431KBU6
set project_dir=%cd%
echo project_dir=%project_dir%
set artefact_hex=%project_dir%\build\%project_name%.hex
set FlashTool="C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility\ST-LINK_CLI.exe"
rem set Device=STM32F401xD/E ID=0x433 SN=0670FF515250898367093046
rem set Device= SN=222006002A12384D434B4E00
set Device= 
set options= -c %Device% SWD freq=4000  -P %artefact_hex% -V "after_programming" -Log -TVolt
call %FlashTool% %options%
rem Reset System
call %FlashTool% -Rst


rem C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility\ST-LINK_CLI.exe -c SWD UR