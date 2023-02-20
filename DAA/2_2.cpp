#include<bits/stdc++.h>
using namespace std;

class job
{
    public:
    char id;
    int ded;
    int prof;

    job(){}

    job(char id,int ded,int prof)
    {
        this->id=id;
        this->ded=ded;
        this->prof=prof;
    }
};

bool cmp(job x,job y)
{
    return (x.prof>y.prof);
}

void jobseq(job* arr,int n)
{
    sort(arr,arr+n,cmp);
    vector<int> result(n);
    vector<bool> slot(n,false);
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i].ded)-1;j>=0;j--)
        {
            if(slot[j]==false)
            {
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }

    cout<<"Sequence of the jobs is:"<<endl;
    for(int i=0;i<n;i++)
    {
        if(slot[i])
        {
            cout<<arr[result[i]].id<<endl;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    job* arr=new job[n];
    char id;
    int ded,prof;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter details of job "<<i+1<<endl;
        cin>>id>>ded>>prof;
        arr[i]=job(id,ded,prof);
    }
    jobseq(arr,n);
}