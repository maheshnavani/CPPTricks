#include <iostream> 
#include <memory>

class Base
{
	private:
		int m_i;
	public:
		Base (int i) :m_i(i) 
		{
			std::cout << "Inside Base CTOR i = " << i << "\n";
		}
		~Base() 
		{
			std::cout << "Inside Base DTOR \n";
		}
		int geti() 
		{
			return m_i;
		}
		void seti(int i) 
		{
			this->m_i = i;
		}
};

int main()
{
	std::shared_ptr<Base> sp = std::make_shared<Base>(1);
	std::cout << "shared_ptr.count=" << sp.use_count() << "\n";
	std::shared_ptr<Base> sp2 = sp;
	std::cout << "shared_ptr.count=" << sp.use_count() << "\n";

	std::shared_ptr<int> p1(new int());
	//In above line it allocates two memory on heap i.e.
	//1.) For int.
	//2.) A memory for Reference Counting that will be used to manage the count of shared_ptr objects attached with this memory. Initially it count will be 1.


	//std::shared_ptr<int> p2 = new int(); // Compile  error: conversion from 'int*' to non-scalar type 'std::shared_ptr<int>' requested

	p1.reset(); //Detaching Pointer
	std::cout << "p1 shared_ptr.count=" << p1.use_count() << "\n";	 // Output = 0
	p1.reset ( new int());
	std::cout << "p1 shared_ptr.count=" << p1.use_count() << "\n";	 // Output = 1
	p1 = nullptr;// Reseting using nullptr
	std::cout << "p1 shared_ptr.count=" << p1.use_count() << "\n";	 // Output = 0
	return 0;
}
