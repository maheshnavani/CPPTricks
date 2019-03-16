#include <iostream>


//Template Meta programming 2 rules
// 1. choosing good names,
// 2. separating out levels of abstractions.

template<typename...>
using void_t = void;


//void_t is just instantiating the template types it is passed, and never uses them. It’s like a surrogate mother for templates, if you would.
//And as said above void_t is just a helper to instantiate this return type. It doesn’t carry any data or behaviour, 
//it’s just a sort of launchpad to instantiate the type returned by decltype.

template< typename, typename = void >
struct is_incrementable : std::false_type { };
 

 //Ok, to understand TMP you also need to understand decltype and declval: decltype returns the type of its argument, 
//and declval<T>() does as if an object of type T was instantiated in the decltype expression (it’s useful because we don’t necessarily know what the constructors of T look like).
// So decltype(++std::declval<T&>()) is the return type of operator++ called on T.
template< typename T >
struct is_incrementable<T,
           std::void_t<decltype( ++std::declval<T&>() )>
       > : std::true_type { };

//If the increment expression is not valid then this intantiation made by void_t fails, SFINAE kicks in and is_incrementable resolves to the primary template inheriting from std::false_type.       

//It’s a great mechanism, but I’m cross with the name. In my opinion it’s absolutely 
//at the wrong level of abstraction: it’s implemented as void, but what it means to do is trying to instantiate a type. 
//By working this piece of information into the code, the TMP expression immediately clears up:

template<typename...>
using try_to_instantiate = void;

template< typename, typename Attempt = void > // to instantiate the expression in the specialization.
struct is_incrementable_1 : std::false_type { };
 
template<typename T>
struct is_incrementable_1<T, try_to_instantiate<decltype(++std::declval<T&>())>> : std::true_type{};

int main()
{
	std::cout << is_incrementable<int>() << "\n"; //Ouput = 1,as int is incrementable
	std::cout << is_incrementable<std::string>() << "\n"; //Output = 0 as std:string is not incrementable


	std::cout << is_incrementable_1<int>() << "\n"; //Ouput = 1,as int is incrementable
	std::cout << is_incrementable_1<std::string>() << "\n"; //Output = 0 as std:string is not incrementable

	return 0;
}
