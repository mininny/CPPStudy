## Class
Class is most important part of OOP in C++. Class allows us to better represent real-life scenarios and objects in code, with object-oriented program in mind. 

## Class Declaration
Class is declare like below in c++: 
```c++
class Stock 
{
private: 
    std::string name;
    long shares;
public:
    void buy(long num, double price);
    void sell(long num, double price);
};
```

### Access modifiers
- `private`: interface with `private` modifiers are only accessible through the class's own interface and can not be directly accessed outside of the class. 
    - Exception is a `friend` interface, which can also access the private interfaces of a class.
- `public`: interface with `public` modifiers can be accessed outside of the class. 
> Default access modifier of a class variable is `private`. 

This allows us to encapsulate the data, appropriately hiding and revealing interfaces as we need them. 

## Class Implementation
Class declarations are usually done on a header file, and the implementations of the class methods are usually done in a cpp file. 
```c++
#include "Stock.h"

void Stock::buy(long num, double price)
{
    ...
}

void Stock::sell(long num, double price) 
{
    ...
}
```

### Inline methods
Methods that are implemented inside the class declaration are automatically treated as a inline method. 
```c++
class Stock 
{ 
private:
    ...
    void printBalance() { cout << name << shares; }
}
```

## Constructor & Destructor
Class is not initialized like primitive types. They require special type of constructors in order to create an instance of a class. 

C++ provides Constructor and Destructor in order to allow us to define how the class is initialized and destroyed. 

### Constructor
```c++
// Declaration
Stock(const static & co, long n = 0, double pr = 0.0);

// Implementation
Stock::Stock(const static & co, long n = 0, double pr = 0.0)
{
    ...
}
```

There are few different ways you can call a constructor. 
```c++
Stock apple = Stock("APPL", 250, 150);
Stock tesla{"TSLA", 20, 150};
Stock netflix("NFLX", 50, 450);
```

Constructors can also have default values:
```c++
Stock apple = Stock("APPL"); // Allowed. 
```

#### Default Constructor
Default Constructors are used when you don't want to create a class without any value. 
```c++
Stock appl; // Default constructor called. 
```

You can define a default constructor like this: 
```c++
Stock::Stock() 
{
    ...
}
```

> Default constructors are automatically created if you do not create any constructors. However, if you define a constructor, then you have to explicitly create a default constructor if you want to have one. 

Additionally, if you have a constructor with default variables, if can also be used like a default constructor.
```c++
Stock::Stock(const static & co = "", long n = 0, double pr = 0.0);
```

However, if you provide a default constructor like above, you should not explicitly create a default constructor with `Stock::Stock();`.

#### Exception cases
When a constructor has only one parameter, you can call the constructor like this: 
```c++
Classname object = value;

Stock tesla = "TSLA";
```

### Destructor
If you create an instance using a constructor, then you must properly destroy that instance using a destructor. 

This is especially important if you used `new` to allocate a memory; you should use `delete` in order to deallocate the memory. 
```c++
// Declaration
~Stock();

// Implementation
Stock::~Stock()
{
    ...
}
```
> Destructors do not have any parameters. 

Destructors are usually called by the compiler, and are not supposed to be called explicitly. It is automatically called when the instance escapes the scope it was created at. 

> Like constructors, destructors are automatically created if they are not explicitly done so. 

## This
Inside a class method, there are times we need to access the class instance itself. To do this, we can use `this`. 

`this` is a pointer that points to the class instance itself, and can be used to access class interfaces. 

```c++
const Stock & Stock::bigger(const Stock & other) const
{
    if other.value > this->value { return other; }

    return *this;
}
```
