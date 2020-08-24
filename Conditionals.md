## If-statements
```c++
if (test-condition)
{
    statement(s);
}
```

## If-else statments
```c++
if (test-condition)
{
    statement(s);
}
else 
    other_statement(s);
```

## If-else-if statements
```c++
if (test-condition)
{
    statement(s);
}
else if (other-condition)
{
    other_statement(s);
}
else 
    else_statement(s);
```

## Switch statements
```c++
switch (integer-expression)
{
    case label1 : statement(s);
    case label2 : statement(s);
    ...
    default : statement(s);
}
```

The code will continue to run after the statement in a given case. In order to escape the switch statement, you must use `break;` after your statement. 

In the case labels, you can use `enum` cases that each represent some integer value. 
