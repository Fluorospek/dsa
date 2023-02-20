#include<bits/stdc++.h>
using namespace std;

void binary_search_it(int* arr,int n,int num)
{
	int lo=0,hi=n-1;
	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;

		if(num==arr[mid])
		{
			cout<<"Number is at index: "<<mid+1;
			return;
		}
		else if(num>arr[mid])
			lo=mid+1;
		else
			hi=mid-1;
	}
	cout<<"Number not found";
	return;
}

int binary_search_rec(int* arr,int n, int num,int lo,int hi)
{
	if(hi>=lo)
	{
		int mid=lo+(hi-lo)/2;
		if(num==arr[mid])
		return mid+1;
		else if(num>arr[mid])
		return binary_search_rec(arr,n,num,mid+1,hi);
		else
		return binary_search_rec(arr,n,num,lo,mid-1);
	}

	return -1;
}

int main()
{
	int n,num;
	cin>>n;
	int* arr=new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	cout<<"The sorted array is:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\nEnter number to be searched:"<<endl;
	cin>>num;
	binary_search_it(arr,n,num);
	int index=binary_search_rec(arr,n,num,0,n-1);
	if(index==-1)
	{
		cout<<"\nNumber not present in the array";
		return 0;
	}
	else
	{
		cout<<"\nNumber is at index: "<<index;
		return 0;
	}
	return 0;
}