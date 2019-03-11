# include <iostream>
# include <vector>
# include <algorithm>

/*
1. A lambda is an ad-hoc, locally-scoped function (well, more strictly, a functor). Basically, lambdas are syntactic sugar, designed to reduce a lot of the work required in creating ad-hoc functor classes.

[]() -> int {}

2. The brackets ([]) mark the declaration of the lambda; it can have parameters, and it should be followed by its body (the same as any other function).
3. When the lambda is executed the parameters are passed using the standard ABI mechanisms. One difference between lambdas and functions: lambda parameters can’t have defaults.

4. Note the lambda uses a trailing return type declaration. This is (no doubt) to simplify parsing (since types are not valid function parameters).
	a. The return type may be omitted if:
	b. The return type is void 
5. The compiler can deduce the return type (lambda body is return <type>) 
6. A lambda is an object (hence why we’re referring to it as a functor, rather than a function) so has a type and can be stored. 
7.However, the type of the lambda is only known by the compiler (since it is compiler-generated), so you must use auto for declaration instances of the lambda.
8. Under the hood
	When you define a lambda the compiler uses that to create an ad-hoc functor class. The functor name is compiler-generated (and probably won’t be anything human readable)
	[] (X& elem) {elem.op() ;};

	Compiler Generated (conceptual)
	class _SomeCompilerGeneratedName_
	{
		public void operator()(X& elem) const
		{
			elem.op();
		}
	}

*/

class Filter
{
	/*
	To capture the class’ member variables we must capture the this pointer of the class. We now have full access to all the class’ data (including private data, as we are inside a member function).
	*/
public:
	Filter(std::vector<int> _v,int _level) : v(_v),level(_level) {}
	void filter()
	{

		v.erase(std::remove_if(v.begin(), v.end(),
			[this](int i)-> bool  { return (i  < level);} ),
			v.end()) ; // pass this to access level

	}
	void print() 
	{
		for (int n : v)
    		std::cout << n << ' ';
    	std::cout << "\n";
		
	}

private:
	std::vector<int> v;
	int level =10;

};
int main()
{

	int i = 9;
	auto l1 = [&]()  { i = 10;}; // Capture by referene 
	/*
	class _SomeCompilerGeneratedNamePassByReference_
	{
		private:
		int &i;
		public:
		_SomeCompilerGeneratedNamePassByReference_(int _i) : i(_i) 
		{
	
		}
		// For refernce const function has no impact as reference is const pointer, 
		//but the pointee is not constant hence below funciton can change value of i
		void operator() () const {
			i = 10;// Bypass by reference hence the global i is now set to 10
		}
	} 
	*/
	l1();
	std::cout << " i = " << i << "\n";  // i = 10

	//auto l2  = [=]() { i = 20;};  //  error: assignment of read-only variable 'i'
	//l2();
	auto l3  = [=]() mutable  {  // Capture by Value
		i ++;
		return i;};  

	/*
	class _SomeCompilerGeneratedNamePassByValue_
	{
		private:
		int i;
		public:
		_SomeCompilerGeneratedNamePassByReference_(int _i) : i(_i) 
		{
	
		}
		int operator() ()  {// since we have mutable , hence function is not const
			i++;// Bypass by Value,hence no impact to global variable
			return i; // Since pass by value, hence every call to lambda will throw different value eg 9 , 10 and so on
		}
	} 
	*/
	

	std::cout << " l3 = " << l3() << "\n";  
	std::cout << " l3 = " << l3() << "\n";  

	std::vector<int> test {1,5,7,8,91,87};
	Filter filter(test,10);
	filter.print();
	filter.filter();
	filter.print();
	return 0;
}

/* 
1. 
[&total, offset] (X &elem) { total += elem.getl()  + Offset;};

class _SomeRandomName_
{
	private:
	int &total ;
	int offset;

	public:
	_SomeRandomName_(int &_total , int _offset) : total(_total), offset(_offset)
	{
	
	}

	void operator()(X &elem) const 
	{
		total += elem.getl() + offset;
	}
}
*/

/*

Callable objects
Callable object is a generic name for any object that can be called like a function:
	1. A member function (pointer) 
	2. A free function (pointer) 
	3. A functor 
	4. A lambda 

std::function <<ReturnType> (<Parameter List>)>

In C we have the concept of a pointer-to-function, which allows the address of any function to be stored (providing its signature matches that of the pointer).
 However, a pointer-function has a different signature to a pointer-to-member-function; which as a different signature to a lambda. What would be nice is a 
 generalised ‘pointer-to-callable-object’ that could store the address of any callable object (providing its signature matched, of course).
std::function is a template class that can hold any callable object that matches its signature. std::function provides a consistent mechanism for storing, passing and accessing these objects.
*/
