# Building with Wine
These are required to get Keyplus Flasher for Windows building under Linux with Wine and Python 3.

1. Install the Linux dependencies
    - Instructions are in the README of this repository.
2. Install [Wine](https://www.winehq.org/).
    - At the time of writing the current stable release of Wine (3.0) is incompatible with Python 3.5.
      Wine version [3.8-staging](https://wine-staging.com/) was tested to work. 
      See [this bug report](https://bugs.winehq.org/show_bug.cgi?id=38423).
    - The Python installation location in this guide is assumed to be `C:\Python35`.
      This may be different to the default install directory, so adapt the instructions accordingly.
    - If you are running in a headless environment you may need to set up X11 forwarding.
3. Download and run the [Python 3.5.4 installer](https://www.python.org/ftp/python/3.5.4/python-3.5.4.exe) with Wine.
    - ```
      wget https://www.python.org/ftp/python/3.5.4/python-3.5.4.exe
      wine python-3.5.4.exe
      ```
      See the [Using Python on Windows](https://docs.python.org/3/using/windows.html#installing-without-ui)
      docs if you prefer to install without a UI.
    - Python 3.5 is the only version of Python recent enough to be supported by PyQt5 
      and old enough to not be affected by [this Wine bug](https://bugs.winehq.org/show_bug.cgi?id=39437).
    - The 64-bit version of Python is not supported at the moment and does not work.
4. Install the Python dependencies.
    - ```
      wine C:\\Python35\\python.exe -m pip install -U pyinstaller pyqt5
      wine C:\\Python35\\python.exe -m pip install -U --pre keyplus
      ```
5. Build the executable.
    - Run in `/host-software`
      ```
      wine C:\\Python35\\Scripts\\pyinstaller -w --onefile --add-data="hidapi.dll;." --icon keyplus.ico keyplus_flasher.py
      ```
