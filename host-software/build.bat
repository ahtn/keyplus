:: Need `pip3 install pyinstaller`

:: Need to set this to the python3 Scripts directory where pyinstaller.exe is
set pyscripts=%USERPROFILE%\local\Python36-32\Scripts\

%pyscripts%\pyinstaller -w --onefile --add-data="hidapi.dll;." --icon keyplus.ico keyplus_flasher.py
