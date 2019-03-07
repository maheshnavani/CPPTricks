# include <iostream>

int main() 
{

	int a[10][10];
	for ( int i = 0 ; i < 10  ; i++ ) 
	{
		for (int j = 0 ; j < 10 ; j++)
			a[i][j] = i+j;
	}

	std::cout << "a[7][5] ="  << a[7][5] << "|With Pointer *(*(a+7)+5) =" << *(*(a+7)+5) << "\n"; //a[7][5] =12|With Pointer *(*(a+7)+5) =12
	std::cout << "a[1][5] ="  << a[1][5] << "|With Pointer *(*(a+1) + 5) =" << *(*(a+1) + 5) << "\n"; a[1][5] =6|With Pointer *(*(a+1) + 5) =6
  // Prints junk value, as double dimension array is pointer to pointer a[1][5] =6|With Pointer *(a+15) = 0x61ffd0
	std::cout << "a[1][5] ="  << a[1][5] << "|With Pointer *(a+15) = " << *(a+15) << "\n"; 
  
	return 0;
}
