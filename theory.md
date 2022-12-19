# Language characteristics

- The C++ language was based on the C language. The original purpose of creating C++ is to add object-oriented programming to C.
- Characteristics of C++:
	- multi-paradigm
	- efficient (there are no additional costs for automatic memory release, etc)
	- lower-level, compared to other OOP languages; the programmer can access system resources
	- compiled
	- statically typed (fixed memory is allocated for variables and functions)
- Paradigms allowed in C++:
	- procedure programming (code "in C style")
	- object-oriented programming (classes, inheritance, virtual functions, etc)
	- generalizied programming (function and class templates)
	- functional programming (functors, unnamed functions, closures)
	- generative programming (metaprogramming on templates)
- One of the fundamental ideas of the C and C++ languages is the absence of implicit overhead that is present in other higher-level programming languages.
- The programmer choosed the level of abstraction on which to write each individual part of the program. It is possible to implement perfomance-critical sections of the program very efficiently.
- Efficiency makes C++ the main language for developing applications with computer graphics (for example, videogames).
- The C++, like C, allows work directly with computer resources. Allows write low-level system applications.
- There is no automatic memory managment. The need to take care of freeing up memory.
- С++ is a compiled language. Compilation is the conversion of program text in programming language into machine code.
	- There are no overhead costs when executing the program
	- When compiling, you can catch some errors
	- It is a required to compile for each platform separately (Windows 64-bit and 32-bit, Linux, Mac OS, etc)
- C++ is a statically typed language. Each entity in program (variable, function, etc) has its own type, and this type determined at the time of compilation. This is necessary in order to calcualte the amount of memory that each variable in the program will occupy and determine which function will be called in each specific place (function overload). All this is determined at the time of compilation and is "sewn" into the compiled program. There are no types in the machine code anymore - there is work going on with byte sequences.

# Code structure
- In C++, you can split programs into multiple files. Source code files have the extension .cpp, sometimes .C. Header files have an extension .hpp or .h. This is done for:
	- It is more convenient to work with small files
	- Splitting into files structures the code
	- Allows multiple programmers to develo an application at the same time
	- When recompiling, only modified files are compiled
- To prevent the contents of the header file from being added several times, the following construction is used:
```
#ifndef <file_name>
#define <file_name>
<header file contents>
#endif
```

# How a C++ program turns into an executable file

0. Processing by the **preprocessor**. The preprocessor language is a special programming language built into C++. The preprocessor works with C++ code as with text. The commands of the preprocessor language are called **directives**, all directives begin with the # sign. 
0. **Compilation**. The compiler receives C++ code as input after processing by the preprocessor. Each code file is compiled separately and independently from other code files. Only files with code (i.e. \*.cpp) are compiled. At the output of the compiler, an “object file” is obtained from each file with the code — a binary file with compiled code (with the extension .o or .obj). 
0. **Linking**. At this stage, all object files are combined into one executable (or library) file. There is a substitution of addresses of functions in
the places of their call. For each object file, a table of all the functions that are defined in it is built.

# Syntax
-  The **#include** directive allows you to connect header files to code files.
#include <foo.h> — library header file,
#include "bar.h" — local header file.
The preprocessor replaces the #include "bar.h" directive with the contents of the bar.h file.
- The **extern** keyword allows you to tell the compiler that a variable only needs to be declared, and there is no need to allocate memory for it - memory for it must be allocated elsewhere (perhaps even in another file). Example:
```
extern int a;
```
