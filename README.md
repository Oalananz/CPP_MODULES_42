# CPP_MODULES_42

A collection of the 42 School **C++ Modules** projects, focused on building solid C++ fundamentals through small, progressive exercises. The repository is organized by module and built using standard 42-style Makefiles.

## Tech stack
- **C++** (~95%)
- **Makefile** (~5%)

## What you’ll practice
Depending on the modules included, topics typically cover:
- C++ basics (I/O, namespaces, classes, member functions)
- Constructors/destructors, copy/assignment (Canonical Orthodox Form)
- Encapsulation, access specifiers, and class design
- Operator overloading
- Inheritance and composition
- Polymorphism (virtual functions), abstract classes, interfaces
- Exceptions and error handling
- Templates and generic programming
- STL containers/iterators/algorithms

## Repository layout
Typical structure (adjust to match your repo):
- `cpp00/`, `cpp01/`, ... — one folder per module
- Each module contains `ex00/`, `ex01/`, ... exercises
- Each exercise includes a `Makefile` and the corresponding source/header files

## Build
From an exercise directory:

```bash
make
```

Common targets:
```bash
make clean
make fclean
make re
```

## Run
After building, run the produced executable (name depends on the exercise):

```bash
./<executable_name>
```
