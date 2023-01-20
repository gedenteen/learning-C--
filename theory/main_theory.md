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
- A **call stack** is a data segment used to store local variables and temporary values. In it, you can refer to any cell. The stack is allocated when the program starts. Functions store their local variables on the stack. When the function exits, the corresponding stack area is declared free. Intermediate values that occur when calculating complex expressions are also stored on the stack.

# How a C++ program turns into an executable file

1. Processing by the **preprocessor**. The preprocessor language is a special programming language built into C++. The preprocessor works with C++ code as with text. The commands of the preprocessor language are called **directives**, all directives begin with the # sign. 
1. **Compilation**. The compiler receives C++ code as input after processing by the preprocessor. Each code file is compiled separately and independently from other code files. Only files with code (i.e. \*.cpp) are compiled. At the output of the compiler, an “object file” is obtained from each file with the code — a binary file with compiled code (with the extension .o or .obj). 
1. **Linking**. At this stage, all object files are combined into one executable (or library) file. There is a substitution of addresses of functions in
the places of their call. For each object file, a table of all the functions that are defined in it is built.

# Syntax

Note: this section does NOT provide basic information about C++ syntax.

-  The **#include** directive allows you to connect header files to code files.
#include <foo.h> — library header file,
#include "bar.h" — local header file.
The preprocessor replaces the #include "bar.h" directive with the contents of the bar.h file.
- The **extern** keyword allows you to tell the compiler that a variable only needs to be declared, and there is no need to allocate memory for it - memory for it must be allocated elsewhere (perhaps even in another file). Example:
```
extern int a;
```
- The operators (+, -, \*, /, %) for built-in C++ types always operate on the same argument types. If the arguments are of different types, then type conversion (promotion) occurs. **Type casting** is used to change the type of a variable. Example:
```
int a = 20;
int b = 50;
double c = (double)a / b;
```
- A **pointer** is a variable that stores the address of a memory location. Pointers have a specific type.
```
int i = 3; //value
int *p = &i; //pointer
```
- To change a variable in another function, you need to pass this variable by address. Example:
```
foo(num); //by value
foo(&num); //by address
```
- An array is a set of elements of the same type located in memory one after another, which are accessed by an index. `p[k]` is equivalent to `*(p + k)`.
- When passing an array to a function, a pointer to an array is passed (the array is not copied).
- A **reference (or alias)** is a type of variable in C++ that works as an alias of another object or value. Example:
```
void swap (int & a , int & b) {
	int t = b;
	b = a;
	a = t;
}
int main () {
	int k = 10 , m = 20;
	swap (k , m);
	cout << k << ’ ’ << m << endl; // 20 10
	return 0;
}
```
- The reference cannot be uninitialized. The reference does not have a null value. You cannot change the reference itself after initialization. Yon cannot get the address of reference or reference to the refrence. You cannot create arrays of references. There is no arithmetic for references.
- References in C++ are used not only to pass mutable parameters to functions, but also to pass large parameters that are expensive to copy.
- If we want to avoid unnecessary copying when passing parameters, but do not want to allow the parameter to be changed inside the function, it should be passed by constant reference:
```
int foo(string const &s) { /* the value of s cannot be changed */ }
```
- The C++ language provides two sets of operators for memory allocation:
`new` and `delete` — for single values,
`new []` and `delete []` — for arrays.
The version of the delete operator must correspond to the version of the new operator.
```
// allocating memory for one int with a value of 5
int * m = new int (5);
delete m; // freeing memory
// creating an array of values of type int
m = new int [1000];
delete [] m; // freeing memory
```
- The **const** keyword allows define typed constants. The word "const" makes the type to the left of it ummutable.
- You can define both a constant pointer and a pointer to a constant:
```
int a = 10;
const int * p1 = &a; // pointer to a constant
int const * p2 = &a; // pointer to a constant
*p1 = 20; // error
p2 = 0; // ok

int * const p3 = &a; // constant pointer
*p3 = 30; //ok
p3 = 0; //error

// constant pointer to the constant
int const * const p4 = &a;
*p4 = 30; // error
p4 = 0; // error
```

## Other info

In C++ using **short-circuit evaluation** - the second logical operator is executed or evaluated only if the first logical operator is not sufficient to determine the value of the expression. Thus, after the result of the expression becomes obvious, its calculation stops. Example:
```
int a = 0;
int b = 5;
( a != 0) && ( b = b / a ); // only the left operand will be executed
( a == 0) || ( b = b / a ); // only the left operand will be executed
```