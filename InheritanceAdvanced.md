### Public vs. Private Inheritance
* Public inheritance is equivalent to `is a~` relationship
* Private inheritance is equivalent to `has a~` relationship

Public inheritance makes the public interfaces of the superclass a part of the subclass. Private inheritance hides the interfaces of the superclass within the subclass. Effectively, private inheritance works similarly as "containment".

> While private inheritance may fulfill the role of `has a` relationship, using containment is much simpler and logical than using inheritance.

### Protected Inheritance
Protected inheritance is similar to private inheritance, except for few things. 

In protected inheritance, the `public` and `protected` members of the base class becomes the `protected` members of the derived class. Like private inheritance, these members are not accessible outside of the derived class. 

However, when another class derives from the derived class, this 3rd class can access the `protected` members from the first base class. 

|                    | Public inheritance              | Protected Inheritance             | Private Inheritance             |
|--------------------|---------------------------------|-----------------------------------|---------------------------------|
| public member      | protected member                | protected member                  | private member                  |
| protected member   | protected member                | protected member                  | private member                  |
| private member     | Only accessible from base class | Only accessible from base class   | Only accessible from base class |
| Implicit upcasting | Possible                        | Possible within the derived class | Not possible                    |