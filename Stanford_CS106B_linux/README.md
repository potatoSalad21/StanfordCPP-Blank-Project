## CS106B Stanford C++ Library Setup for Linux

This guide helps you set up the **Stanford C++ Library** for CS106B on Linux and compile your projects using a Makefile.

### 1. Clone the Stanford C++ Library Repository
To get started, clone the Stanford C++ Library repository:
```sh
git clone https://github.com/Badonix/Stanford_CS106B_linux
```

### 2. Replace `Fiso` with Your File Name
Before using the Makefile, **replace all occurrences of `Fiso` with your actual C++ file name**.

### 3. How to Use the Makefile
To compile and link everything using a Makefile, simply run:
```sh
make
```
Now there should be an executable named after your file (ex. `./Fiso`)

### Explanation of the Makefile
- `PROGRAM = Fiso` → Defines the output executable name.
- `OBJECTS = Fiso.o` → Lists object files required for compilation.
- `CPPOPTIONS = -IStanfordCPPLib -fvisibility-inlines-hidden` → Sets include paths and visibility options.
- `LDOPTIONS = -L.` → Specifies the directory where libraries are searched.
- `LIB = -lStanfordCPPLib` → Links the compiled Stanford C++ Library.
- `all: $(PROGRAM)` → The default rule, builds the program.
- `$(PROGRAM): $(OBJECTS)` → Links the object file to create the final executable.
- `$(OBJECTS): Fiso.cpp Makefile libStanfordCPPLib.a` → Compiles `Fiso.cpp` into an object file.
- `libStanfordCPPLib.a:` → Ensures the library is built before compilation.
- `clean:` → Removes compiled files to allow a fresh rebuild.
