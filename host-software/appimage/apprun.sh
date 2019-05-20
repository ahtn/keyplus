#!/bin/bash

export APPDIR="$(dirname "$(readlink -f "$0")")"
export PATH="$APPDIR/usr/bin/:$PATH"
export LD_LIBRARY_PATH="$APPDIR/usr/lib:$APPDIR/usr/lib/x86_64-linux-gnu:$PATH"
export XDG_DATA_DIRS="$APPDIR/usr/share/:/usr/share/:$XDG_DATA_DIRS"
export PYTHONPATH="$APPDIR/ENV/lib/python3.5/site-packages"

# source "$APPDIR/ENV/bin/activate"
python3 "$APPDIR/ENV/bin/keyplus-cli" "$@"
