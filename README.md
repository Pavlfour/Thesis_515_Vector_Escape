If you like to build on your windows machine, just run the batch file (i automated the process).
I used the toolchain MinGW-w64 x86_64, UCRT runtime, POSIX threading model, SEH exceptions, version 15.2.0 (added the bin path to environment variables)
on my windows 11 machine for a statically linked executable.
The version of SFML is 3.0.0 and i added 2 extra static libraries for the linker in the lib subfolder for the static linking:
- `libjpeg.a`
- `libopenal.a`

You can find the modified version: https://github.com/Pavlfour/SFML_Windows_Template/tree/main/Dependencies

The SFML-3.0.0 folder should be in the same folder where you git clone the project (Thesis_515_Vector_Escape folder) in order for the Makefile to work.

---

## 🎥 Demo
- https://www.youtube.com/watch?v=kEjlSsu5dec

---

## 📊 Class diagram in Visual Paradigm (function parameters and type not included for simplicity)

<img width="6536" height="4052" alt="Class Diagram1" src="https://github.com/user-attachments/assets/d7023bb3-36ce-45ce-8f63-838522d11d24" />
