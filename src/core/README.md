@dir src/core
# Overview of code layout

Important components:


| module | function |
|--------|----------|
| `core/matrix_interpret.c`| The main keyboard logic module. This module is responsible for merging the matrices received from RF and Wired devices and generating the key press and release events based on the matrix state. |
| `core/rf.c` | wireless stuff |
| `core/matrix_scanner.c` | The module responsible for debouncing and generating key matrix packets. |
