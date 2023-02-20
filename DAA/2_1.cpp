#include<bits/stdc++.h>
using namespace std;

class activity
{
    int start,fin;
    public:
    activity(){};

    activity(int start,int fin)
    {
        this->start=start;
        this->fin=fin;
    }

    int getfin()
    {
        return fin;
    }

    int getst()
    {
        return start;
    }
};

bool cmp(activity x,activity y)
{
    return (x.getfin()<y.getfin());
}

void activityselection(activity* arr,int n)
{
    sort(arr,arr+n,cmp);

    cout<<"Following activities are selected: "<<endl;
    int i=0;
    //first activity always gets selected
    cout<<"("<<arr[i].getst()<<", "<<arr[i].getfin()<<")";\

    for(int j=1;j<n;j++)
    {
        if(arr[j].getst()>=arr[i].getfin())
        {
            cout<<", ("<<arr[j].getst()<<", "<<arr[j].getfin()<<")";
            i=j;
        }
    }
}

int main()
{
    activity* arr;
    int n;
    cin>>n;
    arr=new activity[n];
    int start,fin;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter details of activity "<<i+1<<endl;
        cin>>start>>fin;
        if(fin<start)
        {
            cout<<"Enter correct details\n";
            i--;
            continue;
        }
        arr[i]=activity(start,fin);
    }
    activityselection(arr,n);
}