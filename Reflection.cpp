#include <iostream>


//Template Meta programming 2 rules
// 1. choosing good names,
// 2. separating out levels of abstractions.

// Implement Reflection 
//https://www.fluentcpp.com/2017/06/02/write-template-metaprogramming-expressively/
//We will end up with something resembling the is_detected exprerimental feature.
//The part that can vary most in the above code is clearly the decltype expression. So let’s take it in input, as a template parameter.
// But again, let’s pick the name carefully: this parameter represents the type of an expression.
//This expression itself depends on a template parameter. For this reason we don’t simply use a typename as a parameter, but rather a template (hence the template<typename> class):

template<typename...>
using try_to_instantiate = void;

template<typename T, template<typename> 
class Expression, typename Attempt = void>
struct is_detected : std::false_type{};
 
template<typename T, template<typename> class Expression>
struct is_detected<T, Expression, try_to_instantiate<Expression<T>>> : std::true_type{};

//is_incrementable then becomes:

template<typename T>
using increment_expression = decltype(++std::declval<T&>());
 
template<typename T>
using is_incrementable = is_detected<T, increment_expression>;

// Validate function for given class serialize or toString
class A
{
public:
	std::string serialize() 
	{
		return "Hello World serialize";
	}
};

class B
{
public:
	std::string toString() 
	{
		return "Hello World toString";
	}
};

template<typename T>
using serialize_expression = decltype(std::declval<T&>().serialize());
 
template<typename T>
using is_serialize = is_detected<T, serialize_expression>;


int main()
{

	std::cout << is_incrementable<int>() << "\n";
	std::cout << is_serialize<A>() << "\n";
	std::cout << is_serialize<B>() << "\n";
	return 0;
}
