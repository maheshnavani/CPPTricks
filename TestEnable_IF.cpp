# include <iostream>
# include <type_traits>

using namespace std;
#pragma optimize("",off)
// 1. Tag dispatch 
// 2. SFINAE (pronouced as SINAE) Subsitituation failure is not an error

template <typename T>
enable_if_t <!is_floating_point<T>::value,bool>  Equals (T lhs , T rhs)
{
	std::cout << "lhs=" << lhs <<"\n";
	std::cout << "rhs=" << rhs <<"\n";
	return ( lhs == rhs);
}

template <typename T>
enable_if_t <is_floating_point<T>::value,bool>  Equals (T lhs , T rhs)
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




/*
// SFINAE: Second eg , where enable_if is part of parameter list , we have set default type as void* and default value as nullptr

template <typename T>
bool Equals (T lhs , T rhs,  enable_if_t<!is_floating_point<T>::value,void> *ptr = nullptr)
{
	std::cout << "lhs=" << lhs <<"\n";
	std::cout << "rhs=" << rhs <<"\n";
	return ( lhs == rhs);
}

template <typename T>
bool Equals (T lhs , T rhs,  enable_if_t<is_floating_point<T>::value,void> *ptr = nullptr)
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

// SFINAE : First eg where enable_if is part of Template type, to control what type of parameter can access teh function
template <typename T, typename = enable_if_t<!is_floating_point<T>::value>> // Integer
bool Equals (T lhs , T rhs)
{
	std::cout << "lhs=" << lhs <<"\n";
	std::cout << "rhs=" << rhs <<"\n";
	return ( lhs == rhs);
}

int main()
{
	std::cout << Equals(1,1) << "\n";
	//std::cout << Equals(0.22f -0.2f,0.02f) << "\n"; // Output is 1, as it calls specifized function for float but we need one more for double, long double and few more
	return 0;
}

*/


