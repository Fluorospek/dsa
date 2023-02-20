#include<bits/stdc++.h>
using namespace std;

class item
{
    public:
    int wt,prof;

    item(){}

    item(int wt,int prof)
    {
        this->wt=wt;
        this->prof=prof;
    }
};

bool cmp(item x,item y)
{
    int xr=x.prof/x.wt;
    int yr=y.prof/y.wt;
    if(xr==yr)
    return (x.prof>y.prof);
    else
    return (xr>yr);
}

void fractionalknap(item* arr,int n,int cap)
{
    sort(arr,arr+n,cmp);
    int bal=cap;
    double final_prof=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].wt<=bal)
        {
            final_prof+=arr[i].prof;
            bal-=arr[i].wt;
        }
        else
        {
            final_prof+=(arr[i].prof*((double)bal/(double)arr[i].wt));
            break;
        }
    }
    cout<<"Total profit= "<<final_prof;
}

int main()
{
    item* arr;
    int n;
    cin>>n;
    arr=new item[n];
    int wt,prof,cap;
    cout<<"Enter max capacity of knapsack"<<endl;
    cin>>cap;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter details of item "<<i+1<<endl;
        cin>>wt>>prof;
        arr[i]=item(wt,prof);
    }
    fractionalknap(arr,n,cap);
}