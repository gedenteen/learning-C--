1. The C++ language was based on the C language. The original purpose of creating C++ is to add object-oriented programming to C.
2. Characteristics of C++:
- multi-paradigm
- efficient (there are no additional costs for automatic memory release, etc)
- lower-level, compared to other OOP languages; the programmer can access system resources
- compiled
- statically typed (fixed memory is allocated for variables and functions)
3. Paradigms allowed in C++:
- procedure programming (code "in C style")
- object-oriented programming (classes, inheritance, virtual functions, etc)
- generalizied programming (function and class templates)
- functional programming (functors, unnamed functions, closures)
- generative programming (metaprogramming on templates)
4. One of the fundamental ideas of the C and C++ languages is the absence of implicit overhead that is present in other higher-level programming languages.
5. The programmer choosed the level of abstraction on which to write each individual part of the program. It is possible to implement perfomance-critical sections of the program very efficiently.
6. Efficiency makes C++ the main language for developing applications with computer graphics (for example, videogames).
7. The C++, like C, allows work directly with computer resources. Allows write low-level system applications.
8. There is no automatic memory managment. The need to take care of freeing up memory.
9. С++ is a compiled language. Compilation is the conversion of program text in programming language into machine code.
- There are no overhead costs when executing the program
- When compiling, you can catch some errors
- It is a required to compile for each platform separately (Windows 64-bit and 32-bit, Linux, Mac OS, etc)
10. C++ is a statically typed language. Each entity in program (variable, function, etc) has its own type, and this type determined at the time of compilation. This is necessary in order to calcualte the amount of memory that each variable in the program will occupy and determine which function will be called in each specific place (function overload). All this is determined at the time of compilation and is "sewn" into the compiled program. There are no types in the machine code anymore - there is work going on with byte sequences.