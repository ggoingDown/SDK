@echo off

cd %~dp0

copy ..\..\script.ver .
copy ..\..\uboot.boot .
copy ..\..\cfg_tool.bin .
copy ..\..\app.bin .
copy ..\..\br23loader.bin .
copy ..\..\eq_cfg_hw.bin .
copy ..\..\ota_all.bin .
copy ..\..\ota_nor.bin .


..\..\json_to_res.exe json.txt
..\..\md5sum.exe app.bin md5.bin
set /p "themd5=" < "md5.bin"

..\..\isd_download.exe -tonorflash -dev br23 -boot 0x12000 -div8 -wait 300 -uboot uboot.boot -app app.bin  -res tone.cfg cfg_tool.bin eq_cfg_hw.bin config.dat md5.bin 
:: -format all
::-reboot 2500

  

@rem 删除临时文件-format all
if exist *.mp3 del *.mp3 
if exist *.PIX del *.PIX
if exist *.TAB del *.TAB
if exist *.res del *.res
if exist *.sty del *.sty



@rem 生成固件升级文件
copy ota_all.bin ota.bin
..\..\fw_add.exe -noenc -fw jl_isd.fw  -add ota.bin -type 100 -out jl_isd_all.fw
copy ota_nor.bin ota.bin
..\..\fw_add.exe -noenc -fw jl_isd.fw  -add ota.bin -type 100 -out jl_isd_nor.fw
@rem 添加配置脚本的版本信息到 FW 文件中
..\..\fw_add.exe -noenc -fw jl_isd_all.fw -add script.ver -out jl_isd_all.fw
..\..\fw_add.exe -noenc -fw jl_isd_nor.fw -add script.ver -out jl_isd_nor.fw


if exist update_*.ufw del update_*.ufw

..\..\ufw_maker.exe -fw_to_ufw jl_isd_all.fw
..\..\ufw_maker.exe -fw_to_ufw jl_isd_nor.fw
copy jl_isd_all.ufw update_%themd5%.ufw
copy jl_isd_nor.ufw nor_update.ufw
copy jl_isd_all.fw jl_isd.fw
del jl_isd_all.ufw jl_isd_nor.ufw jl_isd_all.fw jl_isd_nor.fw


@REM 生成配置文件升级文件
::ufw_maker.exe -chip AC800X %ADD_KEY% -output config.ufw -res bt_cfg.cfg

::IF EXIST jl_696x.bin del jl_696x.bin 


@rem 常用命令说明
@rem -format vm        //擦除VM 区域
@rem -format cfg       //擦除BT CFG 区域
@rem -format 0x3f0-2   //表示从第 0x3f0 个 sector 开始连续擦除 2 个 sector(第一个参数为16进制或10进制都可，第二个参数必须是10进制)

ping /n 2 127.1>null
IF EXIST null del null
