
# include <iostream >

// Yes, it is possible to call special member functions explicitly by programmer. Following program calls constructor and destructor explicitly.	
class Test
{
public: 
    Test()  { std::cout << "Constructor is executed\n"; } 
    ~Test() { std::cout << "Destructor is executed\n";  } 
}; 
  
int main() 
{ 
    Test();  // Explicit call to constructor 
    Test t; // local object 
    t.~Test(); // Explicit call to destructor 
    return 0; 

    /* Output
    Constructor is executed
Destructor is executed
Constructor is executed
Destructor is executed // Explicit call to destructor 
Destructor is executed // Default call to destrutor when it goes out of scope

When the constructor is called explicitly the compiler creates a nameless temporary object and it is immediately destroyed. That’s why 2nd line in the output is call to destructor.

Once a destructor is invoked for an object, the object no longer exists; the behavior is undefined if the destructor 
is invoked for an object whose lifetime has ended [Example: if the destructor for an automatic object is explicitly invoked, 
and the block is subsequently left in a manner that would ordinarily invoke implicit destruction of the object, the behavior is undefined. —end example ].
*/
}
