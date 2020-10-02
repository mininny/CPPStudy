# Inheritance in c++
C++ provides inheritance in order to allow us to create `derived class` from `base class`.
```c++
class Player
{
    ...
};

class SoccerPlayer: public Player 
{
    ...
};
```

Derived class...:
- includes the member variables from the base class.
- can use the methods from the base class. 
- can add more interface needed for itself.
- must define its own constructor. 

## Access Control
Derived classes can set the access level of the inheritance: `public`, `protected`, `private`.

Derived class cannot access the `private` variables of the base class. 

- Public derivation includes the `public` interfaces of the base class as a `public` interface.

### Protected
While `protected` keyword is similar to `private` under normal circumstances, it is uniquely important in inheritance. 

For derived classes, `protected` keyword is equivalent to `public` keyword, only inside the class's scope. 
```c++
class SuperClass 
{
protected:
    int var;
}

class SubClass: public SuperClass 
{ ... }

void SubClass::doSomething() 
{
    cout << var; // Direct Access to `var`.
}
```

> While it is safer to use `private` access modifier, `protected` can increase convenience and remove the need for extra code. 

## Initializer
Because the derived class can't initialize private variables, it must call the constructor of the base class. 
```c++
SoccerPlayer::SoccerPlayer(char * name, unsigned int age, ...): Player(name, age)
{ ... }
```

Above code calls the base class's constructor in the member initializer list of the derived class. 

> If this is not called, the compiler will use the default constructor for the initialization of the base class. 

## Type Casting
Subclasses can be automatically downcasted to its base class.
```c++
SubClass class1;
SuperClass & class2 = class1; // Allowed.
SuperClass * class3 = class1; // Allowed.
```

However, the substituted variables can only call the interfaces of `SuperClass`.

The opposite is not possible by default:
```c++
SuperClass class1;
SubClass & class2 = class1; // Error!
```

However, you can define a constructor for the SubClass in order to allow such behavior. 

## Virtual
By default, the compiler looks at the type of a variable in order to determine which function to call. 
```c++
SuperClass * class1 = new SuperClass;
SuperClass * class2 = new SubClass;
class1->doSomething(); // Calls SuperClass::doSomething
class2->doSomething(); // Calls SuperClass::doSomething
```

To prevent this and allow for proper polymorphism, you can use `virtual` keyword.
```c++
class SuperClass
{
...
    virtual void doSomething();
}
```

`virtual` keyword tells the compiler to look at the actual type of the variable to determine which method to call. 
```c++
SuperClass * class1 = new SuperClass;
SuperClass * class2 = new SubClass;
class1->doSomething(); // Calls SuperClass::doSomething
class2->doSomething(); // Calls SubClass::doSomething
```

> This behavior is only valid in pointer or reference types. 

When methods are re-defined in the subclass, it is normal to make them `virtual` in the base class. If virtual methods are not redefined in the subclass, the call to the method calls the default version from the base class. 

### Method Redefinition
When methods are redefined in the derived class, the new method hides the existing method.
```c++
class SuperClass
{
    virtual void doSomething(int);
}
class SubClass
{
    virtual void doSomething();
}

SubClass class1;
class1.doSomething(); // Allowed.
class1.doSomething(3); // Error. doSomething(int) is hidden.
```

Not only does the new method hide the method with the same `method signature`, but it hides the methods with the same `name`. 
- You must match the method signature of the derived and base method to use them together.
- If the original method is overloaded, you must redefine all of the overloaded method from the base class. 

### Covariance
Because the behavior of method redefinition does not take the `return type` into account, we can use such behavior to achieve `Covariance`. 

For example, if the original return type is the base class's type, we can switch it to the derived class's type. 
```c++
class SuperClass
{
    virtual SuperClass & build();
}
class SubClass
{
    virtual SubClass & build(); // Same method signature, different return type: covariance.
}
```

### Virtual Destructor
Using virtual destructor is very important in inheritance.
```c++
virtual ~SuperClass();
```

When derived classes are creates and their destructors are used, `virtual` keyword allows the compiler to choose the correct destructor instead of the base one only. 
```c++
SuperClass * class1 = new SuperClass;
SuperClass * class2 = new SubClass;
delete class1; // Calls ~SuperClass();
delete class2; // Calls ~SubClass();
```

This is especially important if you plan to use the class as a base class, and if the classes involve dynamic variables. 

> When the virtual destructor is called, the derived implementation is executed first, and the base class's implementation is automatically exeucted next. 

### Static / Dynamic binding
For notes on static/dynamic binding, look at study notes [here](https://github.com/mininny/CPPStudy/blob/master/StudyNotes.md#compilation--linking). 

## Overriding
You can override the methods of a base class and redefine them in the derived class.
```c++
void SubClass::doSomething() 
{
    SuperClass::doSomething(); // Calls the base class's default implementation first
    ...
}
```

> Specifying the namespace `SuperClass` is very important as `doSomething()` without the namespace would call the function itself again. 

## Abstract Base Class / Pure Virtual Function
For some scenarios, you may need a base class to group certain characteristics, but not initialize it by itself. 

For example, 
```c++
class BaseEllipse 
{
    double x;
    double y;
    ...
}

class Circle: public BaseEllipse;
class Ellipse: public BaseEllipse;
```

We do not want to directly initialize `BaseEllipse` but use it as a base class for `Circle` and `Ellipse`.

To achieve this, we can make it a `Abstract Base Class` by adding `Pure Virtual Function`.
```c++
class BaseEllipse {
...
virtual double Area() const = 0;
}
```

When a class contains a pure virtual function, you can not create an instance of that class. Class with a pure virtual function only serves as a abstract base class. 

However, you can still provide implementations for these pure virtual functions.
```c++
class BaseEllipse {
...
virtual double Area() const = 0; // Marks the class abstract.
}

double BaseEllipse::Area() const // Base Implementation
{
    return x * y;
}
```

## Dynamic Memory Usage
When you need to allocate new memory in a derived class, you must appropriately override the base class's method to correctly handle the memory uage. 

Below is an example of how you can appropriate implement substitute operator in a subclass. 
```c++
SubClass & SubClass::operator=(const SubClass & sc)
{
    SuperClass::operator=(sc); // Prepares the base class
    ... // Do what's necessary for this derived class.
}
```

## Friend Usage
You must also properly "override" friend methods as there is no specific scope for friend methods. 
```c++
std::ostream & operator<<(std::ostream & os, const SuperClass & sc)
{
    os << sc.content << std::endl;
    return os;
}
std::ostream & operator<<(std::ostream & os, const SubClass & sc)
{
    os << (const SuperClass &) sc; // Force casting for operator<<(ostream &, const SuperClass &)
    os << sc.moreContent << std::endl;
    return os;
}
```