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

