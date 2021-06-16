## Project Fyle Structure
    
    Project_name/
    |
    |---- CMakeLists.txt
    |---- main.cpp
    |
    |---- include/
    |       |
    |       |---- Project_name
    |               |
    |               |---- public_headers.hh (C++ only)
    |               |---- public_headers.h (C & C++)
    |---- src/
    |       |
    |       |---- private_headers.hh (C++ only)
    |       |---- private_headers.h  (C & C++)
    |       |---- implementation_files.cc
    |       |---- implementation_files.C (if compiler doesn't accept .cc)
    |       |---- inline_definition_files.icc
    |
    |---- libs/
    |       |
    |       |---- A
    |       |
    |       |---- B
    |
    |---- tests/

## Compile the project

```bash I'm A tab
    take build/
    cmake ..
    make --build .
```
