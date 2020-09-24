## How are methods called in c++?
There are two aspects to methods being called in C++.

### Compilation & Linking
When a `.cpp` file is compiled, the compiler creates an obj file and two tables of symbols that the file refer to. 
- List of symbols that is expected to be defined externally (i.e. extern)
- List of symbols that are defined within the scope of the file. 

Then, the linker links the obj files together. In this process, the linker looks at the list of symbols that are marked `external` and looks through other files to find the matching symbol. 

If the referred symbol is not found by the linker, it will produce an error like: `symbol not found`.

### Dispatch
Now, how are methods actually called during the runtime?

There are two different ways c++ calls a method. 
- Static dispatch / Early binding
- Dynamic dispatch

#### Static Dispatch
Static Dispatch used by methods that can not be changed during the runtime. They are not overloaded, and the pointer to the method stays constant throughout the program. 

With that in mind, the compiler remembers the address of the method, and is used whenever the method is called. 

#### Dynamic dispatch
However, some methods, like virtual methods, can be overloaded and changed during the runtime. In order to correctly track and find the right variation of the method during the runtime, c++ manages something called `vtable`.

The compiler creates and manages a `vtable` that contains the pointer to the virtual functions from classes. 

Using this table, the program can find the correct pointer that a instance method point to. 

In order to remove the ambiguity and mistakes that might arise due to the different types of class used, c++ also creates a `vpointer`.

Classes with `vtable` has a `vpointer` that point to the correct virtual table. This `vpointer` is implicitly a member of the class, and thus correctly type-corrected during the runtime. As the class changes, the call to the `vpointer` will change as well, and the `vpointer` will always point to the correct `vtable` that the class should refer to. 