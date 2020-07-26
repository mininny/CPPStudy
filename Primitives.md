## Naming Variables
```cpp
int variable = 3;
int _variable = 3;
int Variable = 3;
int __variable = 3;
int var_iable = 3;
int variable1 = 3;
// 1Variable = 3; -> Error, do not start with number
// var-iable = 3; -> Error, no hyphens
```

## Initializaing variables
```cpp
int intValue1 = 1;
int intValue2(1);
int intValue3 = { 1 };
int intValue4 { 1 };
int emptyIntValue1 { }; // 0
int emptyIntValue2 = { }; // 0
```

## Arithmetic types
```cpp
short shortNumber = 1;
int intNumber = 1;
long longNumber = 1;
long long veryLongNumber = 1;
```

## Unsigned Types
```cpp
unsigned short ushortNumber = 1;
unsigned int uintNumber = 1;
unsigned long ulongNumber = 1;
unsigned long long uveryLongNumber = 1;
```

## Bool
```cpp
bool trueValue = true;
bool falseValue = false;
bool trueValue1 = 1; // true
bool falseValue0 = 0; // false
```

## Const
```cpp
const int constValue = 0; // Won't be changed
// const int uninitializedValue; // Invalid - should be initialized
const bool CONVENTION = 0;
```

## Floating Point Types
```cpp
float floatValue = 0.0;
double doubleValue = 0.0;
long double longDoubleValue = 0.0;

double largeValue = 3.9e31;
double smallValue = 3.9e-31;
1.234f; // float
1.234F; // float
1.234L; // long double
```

## Operations
```cpp
1 + 1; // Addition
1 - 1; // Subtraction
1 * 1; // Multiplication
1 / 1; // Division
1 % 1; // Remainder (in integer)
```

## Type conversion
```cpp
long validCasting = shortNumber; // Lower type -> Higher type : OK
short lostCasting = longNumber; // Higher type -> Lower type : Some bits may be lost
int valueLostCasting = doubleValue; // Floating point -> Integer : floating point is lost
```

## Narrowing
> C++'s { } initialization does not allow narrowing of values when casting
>
> C++ only allows list initialization with const

```cpp
// char narrowingInit = { 99999999 }; //Invalid : Constant expression evaluates to 99999999 which cannot be narrowed to type 'char'
// char invalidInit = { intValue1 }; // Invalid : Non-constant-expression cannot be narrowed from type 'int' to 'char' in initializer list
const int value = 0;
char validInit = { value };
```

## Automatic data conversion
> bool, char, unsigned char, signed char, short -> int

```cpp
long double * xType => long double * (long double)xType
double * yType => double * (double)yType
float * zType => float * (double)zType
otherType *aType => (int)otherType * (int)aType
```

## Conversion priority
> long long -> long -> int -> short -> signed char
>
> long double -> double -> float

## Type cast
> static_cast<typeName> (value)

```cpp
short castedValue = static_cast<short>(longDoubleValue);
```
## Auto
> Automatic inference for declarations

```
auto autoInt = 100;
auto autoDouble = 100.5;
auto autoLongDouble = 100.5L;
```
