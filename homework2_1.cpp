#include <iostream>
using namespace std; 

int partition(int a[], int left, int right)
{

	
}

int find(int a[],int left,int right,int k)
{
	
}



int main() 
{
	int num;
	int p;
	cin>>p>>num;
	const int length = p;
	int array[length];
	for (int i = 0; i < length; i++)
	{
		cin>>array[i];
	}
	int left = 0;
	int right = length - 1;
	partition(array,left,right);
	return 0;
}
