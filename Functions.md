## Functions

### Function Declaration
```c++
returnType functionName (parameterList);
```
Function declaration allows compiler to know about the function and its declaration before using it. It also corrects the return types of the functions and how they are handled during the compile-time.

In function declarations, you can only declare the types of the parameterList without specifying its names:
```c++
void printList (double, double);
```

### Function Implementation
```c++
returnType functionName (parameterList)
{
    statements;
    return returnType;
}
```
Function Implementations implement the body of the functions declared previously. 

Unlike function declarations, implementations must specify the names of the parameters used. 

### Function Invoke
```c++
returnType var = functionName(parameterList);
```

### Parameters
When an argument is passed into a function as a paremeter, c++ makes a copy of that argument, and the function will work with the copied argument instead of the original one. This allows us to keep the data integrity and work independently with the data. 

This is not the case with pointer type parameters, which can manipulate the original values. 

### Default parameters 
```c++
void printLeft(const char * str, int n = 1);
```
You can use default parameters like this to allow the ommitance of `int n` parameter.

> Default parameters must be filled from the right-side parameters.

## Functions and Arrays
As a parameter, `int arr[]` is equal as `int * arr`. However, you can not do `sizeof` on a pointer to get the size of the array. 

When passing arrays to a function as a parameter, you must also specify the number of elements in the array. 
```c++
int sum_arr(int arr[], int n);
```

Because array is essentially a pointer, you need a boundary for the array before traversing through its values. You cannot use `sizeof` because it would return the `pointer size` of the array.  

### Using array boundary
```c++
int sum_arr(const int * begin, const int * end) 
{
for (pt = begin; pt != end; pt++) //
}
```

## Const Declaration
When using pointers, to protect things from being modified, you can use `const`.
```c++
const type *var;
type * const var;
```

- `const type *var` makes the pointee immutable. By specifying it as a `const`, you can protect the value that the pointer points to from being modified.
- `type * const var` makes the pointer immutable. While you can modify the pointee, you can not change the memory address that the pointer points to. 

> You can also use two `const` like `const type * const var` to make the pointer and the pointee immutable. 

## Strings
Types of C-style strings(`char *`):
- array of `char`
- string wrapped around `""`
- pointer to a string

A valid C-style strings must have a null ending character, so we can traverse through the string until we hit a null character. 

## Structs
Structs are more straight-forward that arrays or pointers. Struct identifiers are just names of the struct unlike names of the array which points to the memory address of the first element.
```c++
struct point 
{
    int x;
    int y;
}

void printPoint(point po)
{
    cout << point.x << point.y;
}
```

While we could pass structs as values, because the size of struct may become too large, pass the pointer to the struct instead. 
```c++
void printPoint(cosnt point * po)
{
    cout << point->x << point->y;
}
```

## Reference Variable
`Reference`  variable allows us to make a `reference` of an another variable. 

```c++
int number;
int & count = number;

// `count` can now be used just like `number`.
```
> & may seem similar to pointer, but reference variables can not change the "pointee", is not changeable upon initiation, and easier to use. 

Reference variables are useful as parameters.

```c++
void foo(int count);
void bar(int & count);
```
Here, `foo` receives the copy of `count`, but `bar` receives the reference to `count`, removing the need to copy the variable to the parameter. 

This may be very beneficial if the parameters are large in size, such as in structs and classes. Also, reference allows functions to mutate the original variables. 

To limit the modification of the original referred variable, you can use `const` like this:
```c++
void foo(const int & count)
{
    count = 3; // Error! count is a const and can not be modified. 
}
```

#### Warning
You should be careful when returing reference variable from a function: 
```c++
item & return_item(item & original)
{
    item copy; // Creates a temporary copy
    copy = original; // Copy the original to the temporary copy
    // Do some work
    return copy; // Return the temporary reference
}
```
This leads to returning a reference to a temporary variable which does not exist outside the scope of the function.

## Function Pointers
In c++, you can create a pointer that points to a function. Just like any other variables, functions have memory address as well, and pointers can point to it. 

For a `function()`, the memory address is `function`.

You must specify the data type of the function in order to refer to its address. 
```c++
double func(int); // Function

double (*pfunc)(int); // Function pointer
pfunc = func;

(*pfunc)(1); // Calls the function, or
pfunc(1); // equivalent
```

Pointer of array of functions is declared like this:
```c++
double (*pfunc[3])(int) = { f1, f2, f3 };
```

### Typedef usage
To make it easier, you can do this:
```c++
typedef double (*pfunc)(int);

pfunc p1 = f1;
```

## Inline Functions
Inline functions are special types of function that are not called, but instead pasted to the location that invoked the function. 

This, 
```c++
int main()
{
    foo()
}

void foo() { 
    print("bar")
}
```

becomes this,
```c++
int main() 
{
    print("bar") // Replaced with the body of the function
}
```

This is useful when function invoking may be slower than the actual execution of the function. 

> You should be very careful when using inline functions. 

## Function Overloading
In c++, you can overload functions, meaning that you can use same name for a number of functions, with different types of the parameters. 
```c++
void print(const chat *str);
void print(string str);
void print(long l, int width);
void print(int i, int width);
```

When you call a function, the compiler will find a function with the matching signature(function name and parameters).
> You can also use functions that match the signature of castable parameters. 
> For example, you can call `add(1.0, 1.0)` to a function of `int add(int a, int b)`.

Because compilers does not check the return type of functions, you can not overload functions with different return types. 

> Function overloading is possible with the help of `name decoration`/`name mangling` that produces unique identifier for a function using its name and parameters. 

## Function Template
In c++, you can use templates in functions to declare functions with `generic type`. Compilers will produce appropriate variations of the function using its generic declaration. 
```c++
template <typename AnyType>
void swap(AnyType &a, AnyType &b) 
{
    AnyType temp;
    temp = a;
    a = b;
    b = temp;
}
```

Above function uses a template type of `AnyType` that can be replaced with other types. The function declaration and implementation uses the same `AnyType`.

This function can be used with any type, and the compiler will produce appropraite variation of the function by replacing `AnyType` with the specified type. 
```c++
int i = 10;
int j = 10;
swap(i, j);
```

### Overloading Function Template
Just like normal functions, you can also overload a function with template. 
```c++
template <typename T>
void swap(T &a, T &b);

template <typename T>
void swap(T *a, T *b, int i);
```

### Explicit Specialization
When using templates, there may be instances where you need to specify the type of the generic that conforms to some requirement.

For example, a function that adds two parameters need to be `addable`.
```c++
template <typename T>
T add(T a, T b)
{
    return a + b;
}

add(1,2); // Valid
add(&a, &b); // Invalid
```

In order to explicitly handle special types, you can use explicit specialization. 
```c++
struct job
{ 
    char name[40];
    double salary;
    int department;
}

template <typename T>
void swap(T &, T&);

// Explicit specialization for `job`
template <> void swap<job>(job &a, job &b)
{
    double tempSalary;
    int tempDepartment;
    
    tempSalary = a.salary;
    a.salary = b.salary;
    b.salary = tempSalary;
    
    tempDepartment = a.department;
    a.department = b.department;
    b.department = tempDepartment;
}
```
The specialized `swap<job>` is just an another type of the `swap<T>` function. When you use `swap` with parameters of `job`, the designated function will be called appropriately. 

### Explicit Instantiation
When the compiler uses the template to create a function implementation for specific data type, it's called template's implicit instantiation.
```c++
int a = 1;
int b = 2;
swap(a, b);
```

When you declare a template function using a specific data type, it's called explicit instantiation. 
```c++
template void swap<int>(int, int);
```
When compiler comes across this declaration, it creates appropriate function for the specific data type.   

> You should not use explicit instantiation and explicit specialization for a single function within the same scope.  

## Overload resolution
With function overloading, template function, template function overloading, and so on, compilers have a specific set of strategy to choose the proper type of function declaration. 

1. List the possible candidates of the functions. These are the functions of the same name. 
2. Filter out function declarations with matching parameter types. This includes parameter data types that can be automatically casted.
3. Find the most appropriate function. If there is no such function, then the function call is invalid. If there are multiple matching functions, then the function call is ambiguous. 

When choosing the best candidate, compilers use the following prioritization:
1. Parameter that exactly matches the type. Normal function is prioritized over template functions. Explicit specialization is prioritized over explicit instantiation. 
2. Promotion of data types. (i.e. `float` to `double`)
3. Standard conversion. (i.e. `int` to `char`)
4. User-defined conversion. (i.e. Defined within the class definition)

### Trivial Conversion
c++ allows trivial conversion for better representation of the functions.
| Actual parameter before conversion  |  Converted parameter type |
|---|---|
| Type | Type & |
| Type & | Type |
| Type [] | * Type |
| Type (argument-list) | Type (*) (argument-list) |
| Type | const Type |
| Type | volatile Type |
| Type * | const Type * |
| Type * | volatile Type * |

## Additional

### decltype
When using template function, it may be ambiguous to define a variable within the function that matches the template data type. 

c++11 provides `decltype` that can be used like this:
```c++
int x;
decltype(x) y; // Creates y with the same type of x
```

`decltype` can be used like this as well:
```c++
template<typename T1, typename T2>
void ft(T1 x, T2 y)
{
decltype(x+y) xpy;
}
```

> To declare reference variable, you can use double parenthesis like this: `decltype ((xx))` which will create a reference variable with the type of  `xx`. 

### Trailing Return Type
When using template function, it may also be ambiguous to define the return type of the function. 

c++11 allows for trailing return type that can be used like this:
```c++
template <typename T1, typename T2>
auto ft(T1 x, T2 y) -> decltype(x+y)
{
return x + y;
}
```
This moves the return type after the declaration of the parameters, allowing the compiler to compute the `decltype` using the type of the parameters. 
