
/*

//Tag Dispatch :
//1. Tag dispatching is a useful complement to enable_if. 
//2. It can also be used in conjunction with trailing return type and decltype. (expression SFINAE) 
//3. It is most useful when you have multiple overloads for the same function, and they all have conditions for when they can be called. With just enable_if,
// you have to test for not just the overloads condition, but also the negation of all the other overloads conditions, lest you get overload ambiguity. Tag dispatch will help reduce the mess: 

template <typename T>
bool Equals (T lhs , T rhs)
{

	return Equals(lhs,rhs,   conditional_t<is_floating_point<T>::value,std::true_type,std::false_type> {}  ); 
}

template <typename T>
bool Equals (T lhs , T rhs, false_type)
{
	std::cout << "lhs=" << lhs <<"\n";
	std::cout << "rhs=" << rhs <<"\n";
	return ( lhs == rhs);
}

template <typename T>
bool Equals (T lhs , T rhs,true_type)
{
	std::cout << "lhs=" << lhs <<"\n";
	std::cout << "rhs=" << rhs <<"\n";
	return ( abs(lhs - rhs) < 0.001);
}

int main()
{
	std::cout << Equals(1,1) << "\n";
	std::cout << Equals(0.22f -0.2f,0.02f) << "\n"; // Output is 1, as it calls specifized function for float but we need one more for double, long double and few more
	return 0;
}

*/

/*

template <typename T>
bool Equals (T lhs , T rhs)
{
	std::cout << "lhs=" << lhs <<"\n";
	std::cout << "rhs=" << rhs <<"\n";
	return ( lhs == rhs);
}

template <>
bool Equals<float> (float lhs , float rhs)
{
	std::cout << "lhs=" << lhs <<"\n";
	std::cout << "rhs=" << rhs <<"\n";
	return ( abs(lhs - rhs) < 0.001);
}

int main()
{
	std::cout << Equals(1,1) << "\n";
	std::cout << Equals(0.22f -0.2f,0.02f) << "\n"; // Output is 1, as it calls specifized function for float but we need one more for double, long double and few more
	return 0;
}

*/

/*
template <typename T>
bool Equals (T lhs , T rhs)
{
	std::cout << "lhs=" << lhs <<"\n";
	std::cout << "rhs=" << rhs <<"\n";
	return ( lhs == rhs);
}

int main()
{
	std::cout << Equals(1,1) << "\n";
	std::cout << Equals(0.22 -0.2,0.02) << "\n"; // Output is 0, due to floating point error
	return 0;
}
*/
