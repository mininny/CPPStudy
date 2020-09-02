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
