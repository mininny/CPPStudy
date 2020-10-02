## Class Constructor / Destructor
For every instance created by the constructor, the destructor should be called equally. 

By having equal number of call to `new` and `delete`, we can safely manage the memories and prevent any errors in the program. 

There are number of special default methods created by the compiler that you should be aware of: 
- Default constructor created when there are non specified.
- Default destructor created when there are non specified.
- Copy constructor.
- Substitution operator.
- Address-of operator.
- Move constructor.
- Move assignment operator. 

### Copy Constructor
```c++
ClassName(const ClassName &);
```

This is a copy constructor that is called when a `ClassName` instance is allocated to a new instance of `ClassName` like this: 
```c++
ClassName oneCopy = one;
// Equivalent to:
ClassName oneCopy = ClassName(one);
```

This constructor is only called when a variable is being initialized. 

It is also called when the program creates a copied instance of a instance. 
- A new variable is initialized with another variable with the same type.
- Function's parameter with value type: `ClassName parameter`
- Function returning an instance with value type: `ClassName`. (Not pointer or reference)
- Compiler creating a temporary variable. 

> Default copy constructor copies all values of a instance except for the static member. (Shallow copy)

### Substitution Operator
```c++
ClassName & ClassName::operator=(const ClassName &);
```

Substitution Operator is used when a instance is substituted to another instance.
```c++
ClassName oneSubstitute;
oneSubstitute = one;
```

Because the substitution operator only does shallow copy of the variables, variables with pointer type may not be deallocated properly. 

To prevent this, you must explicitly define custom substitution operator and delete and create appropriate variables. 
```c++
String & String::operator=(const String & st)
{
    if (this == &st) 
        return *this;
    
    delete [] str;
    str = new char[len + 1];
    strcpy(str, st.str);
    ...
}
```
