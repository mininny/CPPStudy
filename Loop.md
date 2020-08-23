## For Loops
```c++
for (init-expression; test-expression; update-expression) 
{ 
    statements(s);
}
```


## While Loops
```c++
init-expression;

while (test-expression) 
{ 
    statement(s);
    update-expression;
}
```

## Do-while Loops
```c++
do
{
    statement(s);
} while (test-expression);
```

Unlike `for` loop and `while` loops, `do-while` loops are exit-condition loop, performing the contents first **then** checking the test expression.

## For Loop with Range
```c++
double values[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
for ( double x : values )
{
    // x iterates through the values of `values`.
}

for ( double &x : values )
{
    // You can use & to modify the value of x
}
```


## Expression and Statements
In c++, there are expressions and statements.

### Expression
In  c++, expression is rather `a value`, or a combination of `value and operator`. All expressions have a single value.  

- `22 + 26` is an expression of value `48`. 
- `x = 10` is an expression that returns the value of `10`.  This allows us to declare variables like this: `x = y = z = 10`.
- `x > z` is another expression that returns `bool` depending on the result of the comparison. 

### Statements
Statements, are expressions with semicolons(`;`) at the end of them. However, it can turn out as a meaningless statements. 

- `age = 100;` is a statement that applies 100 to `age`.
- `number + 3;` is a statement, but it has no meaning, passing the execution to the next line without doing anything. 


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
