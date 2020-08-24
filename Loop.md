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

## Break and Continue
```c++
while (some-condition)
{
    if (i == 3)
        break;
    if (i == 5)
        continue;
}
```

- `break` breaks the loop(i.e. `for` and `while`) and proceeds to the next line of code after the loop block.
- `continue` skips the remaining code in the code block, and continues to the next iteration of the loop. 
