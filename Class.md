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
> Destructors should not have any parameters. 

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

## Operator overloading
C++ also allows us to overload operators to make the language more versatile and OOP. 

Operator overloading are declares as below: 
```c++
operator'op'(argument_list)
...
operator+(argument_list)
operator/(argument_list)
```
> You can only overload existing operators in c++ and can not overload a new operator. 

Here is an example of operator overloading:
```c++
// Time.h
class Time
{
private: 
    int hours;
    int minutes;
public:
    Time operator+(const Time & other) const
    Time operator-(const Time & other) const
}

// Time.cpp
Time Time::operator+(const Time & other) const
{
    Time sum;
    sum.minutes = this->minutes + other.minutes;
    sum.hours = this->hours + other.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

totalTime = startTime + endTime; // Calls Time::operator+(const Time & other)
```

#### Unary Operator Overloading
You can also overload unary operators like `-number`. Unary operator `-` usually flips the sign of the number. 
```c++
Vector operator-() const;

Vector Vector::operator-() const 
{
    return Vector(-x, -y);
}

flippedVector = -vectorValue; // Calls Vector::operator-()
```

## Friend
Usually, only public/private interfaces of a class could access and private variables. However, because this restriction is sometimes too harsh, c++ provides `friend` interface that can access the private variables of a class. 

There are three different types of friend interface:
- Friend method
- Friend class
- Friend member class

When you make a method a friend of a class, that method gains same access rights as other interfaces of the class. 

### Friend and Operator Overloading
Let's look at a common operator overloading.
```c++
class Vector
{
    double x;
    double y;
}

Vector Vector::operator*(double m)
{
    return Vector(x * m, y * m);
}

Vector vector(1.1, 2.2);
vector * 2; // Successful call to vector.operator*(2); 
2 * vector; // ?? Fail
```

Because a operator overloading member method is restricted to the class itself, it can create ambiguities like above. To solve this, we can use non-member method. 
```c++
Vector operator*(double m, const Vector & vector);
// Calls...
newVector = operator*(2, vector);
newVector = 2 * vector; 
```

However, the above method does not have the access to private variables `x` and `y` of `Vector` class. We can make this a friend method of the `Vector` class to allow it. 
```c++
class Vector
{
    ...
    friend Time operator*(double m, const Vector & vector);
}

Time operator*(double m, const Vector & vector) 
{
    return Vector(vector.x * m, vector.y * m);
}
```
- This method is declared inside `Vector`, but it is not a member method. 
- Even though it is not a member method, this friend method has equal access right as member methods. 

## Type Casting
### Implcit Constructor Casting
In c++, there is a special implicit type casting that can be done in a constructor like this:
```c++
Weight::Weight(double kilos);

Weight weight = 34.3; // Double successfully casted into Weight.
```

However, if you have multiple constructors with default values, this behavior of implicit type casting may create ambiguity. To prevent this, you can do this:
```c++
explicit Weight(double kilos);

weight = 34.3; // Fail

weight = Weight(34.3); // Explicit casting success
weight = (Weight) 34.3; // Explicit casting success
```

### Class Conversion Function
In the above section, we saw how primitive types were able to be casted into a class. In c++, we can also cast class instances to other types like this:
```c++
Weight weight(34.3);
double total = weight;
```

Conversion Functions are user-defined explicit type castin defined like below: 
```c++
operator typeName();
```

> Conversion functions should be the class's method, not have any return type or parameter. 

```c++
class Weight
{
public:
    operator double() const;
}

Weight::operator double() const 
{
    return Double(value);
}
```

#### Type Ambiguity
If you have multiple conversion functions defined inside a class, you may com across type ambiguity problems. 
```c++
class Weight
{
    operator double() const;
    operator int() const;
}

Weight weight(1.0);
long value = weight; // Both double and int can be casted to long!
```

To solve this, you can make conversion functions explicit and prevent implicit type castings.
```c++
class Weight 
{
    explicit operator int() const;
    explicit operator double() const;
}
```

> Use of conversion function should be considered heavily. They can be very dangerous when used improperly. 