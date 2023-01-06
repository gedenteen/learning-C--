# Programs

## 01_characterByCharacterInput

Character by character input via std::cin.get()

## 02_quadraticEquation

A program for solving quadratic equations of the form `a*x^2 + b*x + c = 0`. The program receives three integers as input: `a`, `b` and `c`, respectively. The program output is roots of the equation separated by a space.

## 03_macrosMax

Macros `MAX(x, y, r)` for find maximum number between `x` and `y`, `r` = maximum number.

## 04_myStrcat

Implementation of strcat() for char arrays. Using pointers.

## 05_myStrstr

Implementation of strstr() for char arrays. Using pointers.

## 06_swapViaReferences

Fucntion swap() with using references.

## 07_myGetline

Implementation of getline(). Using dynamic memory.

## 08_myString

Class String. Fields: array of chars, size of this array. Methods: constructors, destructor, append other String to this String. 

## 09_getPrivateFields

Implementation of the method for obtaining private class fields. The method is to create a copy of the class but with public fields. They have the same memory offsets for the fields. To get private fields, an object of a "private" class is brought to an object of a "public" class.

## 10_copyingAndAssigningObjects

This program copies and assigns objects of the class. Dynamic memory is allocated in the constructor of this class. If you use a copy constructor that simply copies the contents of memory (such a constructor creates a compiler by default), an error will occur - dynamic memory will be released several times when the program ends. The same problem with the assignment operator (=). I wrote the copy constructor and the = operator, which are called when copying and assigning objects, they work correctly with memory.

## 11_overloadingOperators

Example with overloading operators +, -, *=