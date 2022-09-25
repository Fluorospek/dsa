#include<bits/stdc++.h>
using namespace std;

void mergesort(int*,int,int);
void merge(int*,int,int,int);

int main()
{
    int* arr;
    int n;
    cout<<"Enter the number of elements to be entered:"<<endl;
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    mergesort(arr,0,n-1);
    cout<<"The sorted array is:"<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<endl;
}

void merge(int* arr,int i,int j,int k)
{
    int n1=j-i+1;
    int n2=k-j;
    int A1[n1],A2[n2];
    for(int p=0;p<n1;p++)
    A1[p]=arr[i+p];
    for(int q=0;q<n2;q++)
    A2[q]=arr[j+1+q];

    int p=0,q=0,r=i;

    while(p<n1&&q<n2)
    {
        if(A1[p]<A2[q])
        {
            arr[r]=A1[p];
            p++;
        }
        else
        {
            arr[r]=A2[q];
            q++;
        }
        r++;
    }

    while(p<n1)
    {
        arr[r]=A1[p];
        p++;
        r++;
    }
    while(q<n2)
    {
        arr[r]=A2[q];
        q++;
        r++;
    }
}

void mergesort(int* arr,int i,int j)
{
    if(i<j)
    {
        int mid=i+((j-i)/2);
        mergesort(arr,i,mid);
        mergesort(arr,mid+1,j);
        merge(arr,i,mid,j);
    }
}