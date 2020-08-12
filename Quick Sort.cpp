#include<iostream>
#include<cstdlib>
 
using namespace std;
 
// Swapping two values.
void swap(int *a, int *b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
 
// Partitioning the array on the basis of values at high as pivot value.
int Partition(int a[], int low, int high)
{
	int Pivot, Index;
	Index = low;
	Pivot = high;
 
	// Getting index of pivot.
	for(int i=low; i < high; ++i)
	{
		if(a[i] < a[Pivot])
		{
			swap(&a[i], &a[Index]);
			Index++;
		}
	}
	// Swapping value at high and at the index obtained.
	swap(&a[Pivot], &a[Index]);
 
	return Index;
}
 
// Random selection of pivot.
int Random_Pivot_Partition(int a[], int low, int high)
{
	int pvt, n, temp;
	n = rand();
	// Randomizing the pivot value in the given subpart of array.
	pvt = low + n%(high-low+1);
 
	// Swapping pvt value from high, so pvt value will be taken as pivot while partitioning.
	swap(&a[high], &a[pvt]);
 
	return Partition(a, low, high);
}
 
// Implementing Quick_Sort algorithm.
void Quick_Sort(int a[], int low, int high)
{
	int pindex;
	if(low < high)
	{
		// Partitioning array using randomized pivot.
		pindex = Random_Pivot_Partition(a, low, high);
		// Recursively implementing Quick_Sort.
		Quick_Sort(a, low, pindex-1);
		Quick_Sort(a, pindex+1, high);
	}
}
 
int main()
{
	int Size;
	cout<<"\nEnter the total numbers of elements to be sorted: ";
	cin>>Size;
 
	int array[Size];
	for(int i = 0; i < Size; ++i)
	{
		cout<<"Enter "<<i+1<<" Element : ";
		cin>>array[i];
	}
 
	Quick_Sort(array, 0, Size-1);
 
	// Printing the sorted data.
	cout<<"\nSorted List ";
	for (int i = 0; i < Size; ++i)
        	cout<<array[i] <<", ";
		
 
	return 0;
}