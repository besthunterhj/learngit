#include <iostream>
using namespace std;

int median(int a[],int a_l,int a_r,int b[],int b_l,int b_r){
	int a_m,b_m;
	int ans;
	if (a_l == a_r)
	{
	return a[a_l] < b[b_l] ? a[a_l] : b[b_l];
	}
 
	a_m = (a_l + a_r) / 2;
 
	b_m = (b_l + b_r) / 2;
 
	if (a[a_m] == b[b_m])
	{
	ans = a[a_m];
	}
 
	else if (a[a_m] < b[b_m])
	{
	if ((a_r - a_l + 1) % 2 ==0)
	{
		a_m += 1;
    }
	ans = median(a,a_m,a_r,b,b_l,b_m);
	}
 
	else
	{
	if ((a_r - a_l + 1) % 2 ==0)
	{
		b_m += 1;
	}
 
	ans = median(a,a_l,a_m,b,b_m,b_r);
	}

	return ans;

}
 
int main(){
	int n;
	cin >> n;
	int arr1[n],arr2[n];
	for(int i = 0;i<n;i++)
	{
	cin >> arr1[i];
	}
	
	for(int j = 0;j<n;j++)
	{
	cin >> arr2[j];
	}
    cout << median(arr1,0,n-1,arr2,0,n-1);
    return 0;
}