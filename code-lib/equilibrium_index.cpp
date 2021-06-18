#include<bits/stdc++.h>
using namespace std;

void findEquilibrium(int a[],int n)
{
	int sum=0;
	int leftSum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}
	for(int i=0;i<n;i++)
	{
		sum=sum-a[i];
		if(sum==leftSum)
		{
			cout<<i;
			return;
		}
		leftSum+=a[i];
	}
	cout<<"-1";
}

int main()
{
	int a[]={-7, 1, 5, 2, -4, 3, 0};
	int n=7;
	findEquilibrium(a,n);
	return 0;
}