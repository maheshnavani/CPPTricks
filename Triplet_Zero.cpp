#include <iostream>
#include <unordered_set>





// HashMap 0(n2)
void findTriplets(int arr[] , int size)
{
	for (int i =0; i < size - 1; i++)
	{
		std::unordered_set<int> lookup;
		
		for ( int j = i+1 ; j < size  ; j++)
		{
			int x = -(arr[i] + arr[j]);
			if  ( lookup.find(x) != lookup.end())
			{
				std::cout << "x=" << x << "|arr[i]=" << arr[i] << "|arr[j]=" << arr[j]  << "\n";
			}
			else 
			{
				lookup.insert  (arr[j]);
			}
		}
	}
}

/*
// Brut force O(n3)
//Given an array of distinct elements. The task is to find triplets in array whose sum is zero.
void findTriplets(int arr[] , int size)
{

	for (  int i = 0 ; i < size -2 ; i++)
		for ( int j = i+1 ; j < size -1 ; j++)
			for  ( int k = j+1 ; k < size ; k++)
			{
				if ( (arr[i] + arr[j] + arr[k] )== 0)
				{
					std::cout << "i=" << i << "|j=" << j << "|k=" << k  << "\n";
					std::cout << "arr[i]=" << arr[i] << "|arr[j]=" << arr[j] << "|arr[k]=" << arr[k]  << "\n";

				}
			}
}
*/
int main() 
{ 
    int arr[] = {0, -1, 2, -3, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    findTriplets(arr, n); 
    return 0; 
} 
