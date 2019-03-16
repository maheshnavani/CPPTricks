#include <iostream>


//Template Meta programming 2 rules
// 1. choosing good names,
// 2. separating out levels of abstractions.

// Implement Reflection 
// Allowing serveral types in expression

template<typename...>
using try_to_instantiate = void;

using discard_this  = void;

/*
// It’s not going to work because the variadic pack typename... Ts is going to eat up all the template parameters, so it needs to be put at the end 
//But the default template parameter Attempt also needs to be at the end. So we have a problem.
template<typename... Ts, template<typename...> class Expression, typename Attempt = void>
struct is_detected : std::false_type{};
 
template<typename... Ts, template<typename...> class Expression>
struct is_detected<Ts..., Expression, try_to_instantiate<Expression<Ts...>>> : std::true_type{};
*/

//Default Teamplate
template < template<typename...> class Expression , typename Attempt , typename... Ts>
struct  is_detected :std::false_type {};

//Specilization , hence typename Attempt is not part of Template param list 
// we call try_to_instantiate <Expression>
template < template<typename...> class Expression ,  typename... Ts>
struct  is_detected < Expression , try_to_instantiate<Expression<Ts...>>,Ts...> :std::true_type {};



//And then the check for assignment can be written this way:

template<typename T, typename U>
using assign_expression = decltype(std::declval<T&>() = std::declval<U&>());
 
template<typename T, typename U>
using are_assignable = is_detected<assign_expression, discard_this, T, U>;

int main()
{

	std::cout << are_assignable<int,double> () << "\n";  // Output is 1 , we can assign double to int
	std::cout << are_assignable<int,std::string> () << "\n"; // Output is 0 , as we cannot assign std::string  to int
	return 0;
}
