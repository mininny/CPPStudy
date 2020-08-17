## Arrays
```c++
int arr[3]; // Initializese int type array of size 3

int arr[3] = { 1, 2, 3 };  // Valid initailization
int arr[3]; // Valid initilization

arr[3] = { 1, 2, 3 }; // Invalid initialization

int arr[3] = { 1 }; // Valid initialization -> { 1, 0, 0 }
int arr[] = { 1, 2, 3 }; // Valid initialization -> array of size 3

int arr[3] { 1, 2, 3 }; // Valid
int arr[3] = { }; // Valid -> { 0, 0, 0 }
```

## Strings
Strings are series of characters that are saved consequently in the memory. 

Strings must always end with a null character. String interpretations are done until a null character is encountered, so strings must have a null character in order to be processed correctly. 

String literals automatically have null character at the end of the string. 

```c++
char str[7] = "String"; // Automatically has a null character
```

`'s'` and `"s"` is different. '' refers to the actual value of the char character, while "" refers to the memory address of the string.

```c++
string str1 = "1";
string str2 = "2";

string str3 = str1 + str2;

strcpy(charr1, charr2); // Copies charr2 to charr1
strcat(charr1, charr2); // Appends charr2 to charr1

str1.size(); // Returns length of the string 
strlen(charr1); // Returns the string length of the char array. Reads until null character. 

auto rawString = R"(This is "Raw String")"; // Raw String = This is "Raw String"
auto rawString = R"_-(This is "Raw String")_-"; ? // Equivalent as above
```

## Structs
```c++
// Declaration
struct somedata {
    char name[10];
    float value;
    int number;
}

// Usage
somedata data = 
{ 
    "Name",
    1.0,
    3
};
// data.name -> char name[10]

somedata invalid { }; // All values are initialized with 0

somedata dataarr[2] = { 
    { "James", 1.0, 2 },
    { "Mark", 5.2, 3 }
};
```

## Union
Unions are used to contain multiple types of data within a single container. You can only use `int`, `long`, and `double` in a union. 

```c++
union all_type {
    int int_val;
    long long_val;
    double double_val;
}
```

This `all_type` can contain any values of int, long, and double, but only one at a time.
```c++
all_type numb;
numb.int_val = 15; // numb now has int value
numb.double_val = 15.0; // numb now has double value, and has lost the int value. 
```

unions can be inserted within structs for easy usage like this:
```c++
struct toaster {
    char bread_type;
    union id {
        long id_num;
        char id_char[20];
    } id_val;
}

toaster toast;
toast.id_val.id_num;

// This is allowed as well,
struct toaster {
    char bread_type;
    union {
        long id_num;
        char id_char[20];
    };
}

toaster toast;
toast.id_num;
```

## Enum
```c++
// Declaration
enum color { red, green, blue }; // 0, 1, 2, respectively.

// Usage
color band = red;

int bad = red // red upgrades to int
color bad = 0 // int cannot be coerced into enumeration

band = color(2); // turns 2 into color type

enum numbers { zero, null = 0, one, real_one = 1 }; // 0, 0, 1, 1; Enumerations can have cases with same value. 
```

You can also use enumeration without declaring it as a type.
```c++
enum { red, green, blue };
// red, green, and blue is accessible as a enumeration type. 
```

## Pointers
```c++
int var = 1;
&var // memory address where var is stored.

int * p_var
p_var = &var // now, p_var points at the location of var.
*p_var == var
```

Initializing/deinitializing variable:
```c++
int* pn = new int; // Allocates new memory block of int type to this pointer. 

delete pn; // Deallocates the memory given to pn. Can be reused later. 

int* invalid = 0;
delete invalid; // Not allowed. 
```

Arrays with pointer: 
```c++ 
int* p_arr = new int [10]; // New memory address with size of 10 int
p_arr[0] = 1; // First element
p_arr[1] = 2; // Second element

p_arr += 1; // Moves up the pointer to second element. Pointer is a variable of memory address

delete [] p_arr;  

// *(arr + index) is equal to arr[index]
int arr[10];
*(arr + 3) = 3; // Puts 3 into the third element of the array.
```