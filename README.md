If you like to build on your windows machine, just run the batch file (i automated the process).
I used the toolchain MinGW-w64 x86_64, UCRT runtime, POSIX threading model, SEH exceptions, version 15.2.0 (added path to environment variables)
on my windows 11 machine for a statically linking executable.
The version of SFML is 3.0.0 and i added 2 extra static libraries for the linker in the lib subfolder for the static linking
- `libjpeg.a`
- `libopenal.a`

You can find the modified version: https://github.com/Pavlfour/SFML_Windows_Template/tree/main/Dependencies

## 🎥 Demo
- https://www.youtube.com/watch?v=kEjlSsu5dec

## Class diagram in Visual Paradigm (function parameters not included for simplicity)

<img width="4902" height="3039" alt="Class Diagram" src="https://github.com/user-attachments/assets/4dd87a8b-a468-4718-be95-883f94f59daa" />
