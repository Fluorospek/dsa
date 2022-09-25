#include<bits/stdc++.h>
using namespace std;

int main()
{
    int* arr;
    int n,min,temp;
    cout<<"Enter number of elements to be entered:"<<endl;
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int step=0;step<n;step++)
    {
        min=step;
        for(int i=step;i<n;i++)
        {
            if(arr[min]>arr[i])
            min=i;
        }
        if(min!=step)
        {
            temp=arr[step];
            arr[step]=arr[min];
            arr[min]=temp;
        }
    }
    cout<<"The sorted array is:"<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<endl;
}