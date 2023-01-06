# Object-oriented programming in C++

Object-oriented programming is a programming concept based on the concepts of objects (instances of the class) and classes (description of something in the code). Basic principles:
* encapsulation (the principle of independence of data that is "in the capsule")
* inheritance (the ability to create a child class from another class by inheriting its fields and methods)
* polymorphism (ability to work with child classes via a pointer to the parent class)
* abstraction (highlighting the most significant characteristics of an object)

## Inheritance

Inheritance is a mechanism that allows you to create derived classes by extending existing ones.
```
struct Person {
	string name () const { return name_; }
	int age () const { return age_; }
private :
	string name_ ;
	int age_ ;
};

struct Student : public Person {
	string university () const { return uni_; }
private :
	string uni_ ;
};
```

When creating an object of a child class, the constructor of the parent class is called first, then the constructor of the child class. When deleting an object of a child class, the destructor of the parent class is called first.

The following **casts** are defined for derived classes:
```
Student s ( " Alex " , 21 , " Oxford " );
Person & l = s ; // Student & -> Person &
Person * r = & s ; // Student * -> Person *
```
Therefore, objects of the child class can be assigned to objects of the parent class:
```
Student s ( " Alex " , 21 , " Oxford " );
Person p = s ; // Person("Alex", 21);
```
Only the fields of the parent class are copied.

### Multiple inheritance

Multiple inheritance allows you to inherit the contents of some classes, but this can lead to errors.
```
class USBDevice
{
private:
	long m_id;
public:
	USBDevice(long id) : m_id(id) {}
	long getID() { return m_id; }
};
 
class NetworkDevice
{
private:
	long m_id;
public:
	NetworkDevice(long id) : m_id(id) {}
	long getID() { return m_id; }
};
 
class WirelessAdapter: public USBDevice, public NetworkDevice
{
public:
	WirelessAdapter(long usbId, long networkId) : USBDevice(usbId), NetworkDevice(networkId) {}
};
 
int main()
{
	WirelessAdapter c54G(6334, 292651);
	std::cout << c54G.getID(); // which version of get ID() should be called here?
	return 0;
}
```

## Access Modifiers

- **Public** — access is open to all other classes who see the definition of this class.
- **Protected** — access is open to classes derived from this. That is, derived classes get free access to such properties or methods. All other classes do not have such access.
- **Private** — access is open to the class itself (i.e., member functions of this class) and friends of this class - both functions and classes. However, derived classes do not get access to this data at all. And all other classes do not have such access.

Public and protected methods of the parent class can be called for objects of the descendant class. The descendant class does not have access to the private members of the parent class. The protected modifier is used to determine the private members of the class available to heirs.

## Polymorphism

Polymorphism is the ability to uniformly process different types of data.

### Function overloading

Unlike C, in C++, you can define several functions with the same name but different parameters.
```
double square (double d) { return d * d; }
int square (int i) { return i * i; }
```
Function selection occurs at the time of compilation based on the types of function arguments, this is **static polymorphism**.

### Methods overloading

Overloading is also available for methods. To overload a method from the parent class, specify it in the child class:
```
struct File {
	void write(char const * s);
	...
};

struct FormattedFile : File {
	void write(int i);
	void write(double d);
	using File::write;
	...
};
```

### Methods overriding

Overriding methods is replacing a method in a parent class with a method from a child class. Both methods must have the same signature (name + parameters).
```
struct Person {
	string name () const { return name_ ; }
	...
};

struct Professor : Person {
	string name () const {
		return " Prof . " + Person :: name ();
	}
	...
};
...
	Professor pr("Stroustrup");
	cout << pr.name() << endl; // Prof. Stroustrup
	Person * p = &pr;
	cout << p->name() << endl; // Stroustrup
```

### Virtual methods

A virtual method is a class method that can be overridden in descendant classes so that the specific implementation of the method to call will be determined at runtime (not during the compilation).
```
struct Person {
	virtual string name () const { return name_ ; }
	...
};

struct Professor : Person {
	string name () const {
		return " Prof . " + Person::name ();
	}
	...
};
...
	Professor pr("Stroustrup");
	cout << pr.name() << endl; // Prof. Stroustrup
	Person * p = &pr;
	cout << p->name() << endl; // Prof. Stroustrup
```

The method is selected at the time of execution based on the type of object from which the virtual method is called, this is **dynamic polymorphism**. A **table of virtual methods** is created for each polymorphic class.

### Pure virtual (abstract) methods

An abstract method is a class method for which there is no implementation. When it is called, a compilation error occurs. A class containing abstract methods is also commonly called abstract. An abstract method can be used to override in child classes.
```
struct Person {
	virtual string occupation () const = 0;
	...
};
struct Student : Person {
	string occupation () const { return " student "; }
	...
};
```

## Other info

If the structure or class has no constructors, then the constructor without parameters, the **default constructor**, is generated by the compiler. If at least 1 constructor is defined by the programmer, then there will be no default constructor generation.

"If something looks like a function declaration, then it is a function declaration."
```
struct Point {
	explicit Point ( double x = 0 , double y = 0)
		: x(x), y(y) {}
	double x ;
	double y ;
};
<...>
	Point p1; // definition of variable
	Point p2(); // function declaration
	double k = 5.1;
	Point p3(int(k)); // function declaration
	Point p4((int)k); // definition of variable
```
