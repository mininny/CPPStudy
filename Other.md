## Time Lock
c++ provides a `clock()` method to help us to gauge the time that the program has been running so far. 

As `clock()` returns different representations of time(i.e. long, unsigned long), we need to convert it between seconds using `CLOCKS_PER_SEC` from `ctime`.

```c++
clock_t delay = secs * CLOCKS_PER_SEC;
clock_t start = clock();
while (clock() - start < delay) 
{
    // do something
}
```

## Memory locations
- automatic storage: variables declared within a scope like a function. Only valid within that scope. `LIFO`
- static storage: storage that persists throughout the lifetime of the program. Usually declared as a `static`.
- dynamic storage/heap: dynamic allocations to the memory pool using `new` and `delete`.

## File in/out
In order to read from and write to a file, you should use `fstream` header file, as well as `ofstream` and `ifstream`. 

Writing to a file: 
```c++
#include <fstream>;

ofstream outFile;
outFile.open("text.txt");

oufFile << "Whatever text";
outFile.close();
```

Reading from a file:
```c++
#include <fstream>;

ifstream inFile;
inFile.open("text.txt");

inFile >> value;
while (inFile.good()) 
{
    inFile >> value; 
}
inFile.close();
```

## Constants
Oftentimes, you want to define constants that are used inside a class. 

Having multiple instances of the class share the same constant can be good sometiems and you can do it in several different ways: 

#### Enum
```c++
class Bakery
{
private:
    enum { Months = 12 };
...
```
This does not create any new variable, but substitues every usage of `Months` with the value of `12`. 

#### Static Const
```c++
class Bakery
{
private:
    static const int Months = 12;
..l.
```