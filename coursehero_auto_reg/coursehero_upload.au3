#cs
ControlFocus("打开","","Edit1")
ControlSetText("打开", "", "Edit1", "F:\coursehero_auto_reg\account_registered_on_20180327\generated_files")
ControlClick("打开", "", "Button1")
ControlFocus("打开","","DirectUIHWND2")
Send("^a")
ControlClick("打开", "", "Button1")
MsgBox(64, "Passed Parameters", "/name is " & $CmdLine[1])
#ce
ControlFocus("打开","","Edit1")
ControlSetText("打开", "", "Edit1", $CmdLine[1])
Sleep(2000)
ControlClick("打开", "", "Button1")
sleep(2000)
ControlFocus("打开","","DirectUIHWND2")
Sleep(2000)
Send("^a")
ControlClick("打开", "", "Button1")
MsgBox(64, "Passed Parameters", "/name is " & $CmdLine[1])
