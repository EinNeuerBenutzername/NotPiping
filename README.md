# NotPiping
cross-program communication, not piping

## General
This is a tiny experiment I made. The goal is to establish the communication between two programs without piping whatsoever. They communicate through a file on the disk named `data.dmp`, which is **opened by two programs simultaneously**. I am worried that this is an undefined behavior.
The data is updated with `rewind()` and `fflush()`.
There is no OS-dependency except for the `Sleep()` function that I called in `rcv.c` in order to minimize CPU usage.
The only standard libraries used are `<stdio.h>`, `<wchar.h>` and `<stdlib.h>`. 

## Status
Not exactly stable. Requires more testing on non-Windows platforms.
I have tested it on multiple Windows machines and it behaved surprisingly well.
