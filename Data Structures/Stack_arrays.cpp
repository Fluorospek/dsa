#include<bits/stdc++.h>
using namespace std;

template<class T>
class stack_class
{
    int flag=-1;
    int size;
    T* stack;

    public:

    stack_class(int size)
    {
        this->size=size;
        stack=new T[size];
    }

    void push(T value)
    {
        if(isFull())
        {
            cout<<"overflow"<<endl;
        }
        else
        {
            ++flag;
            stack[flag]=value;
        }
    }

    T pop()
    {
        if(isEmpty())
        {
            cout<<"underflow"<<endl;
            return 0;
        }
        else
        {
            int data;
            data=stack[flag];
            flag--;
            return data;
        }
    }

    bool isEmpty()
    {
        return (flag==-1);
    }

    bool isFull()
    {
        return (flag==size-1);
    }

    void peek()
    {
        return stack[flag];
    }

    void print()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            for(int i=flag;i>=0;i--)
            cout<<stack[i]<<endl;
        }
    }
};

int main()
{
    int size,n,value;
    cout<<"Enter the size of the stack to be created:"<<endl;
    cin>>size;
    stack_class<int> stack(size);
    cout<<"Enter no. of elements to be pushed:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter value to be pushed:"<<endl;
        cin>>value;
        stack.push(value);
    }
    stack.print();
}