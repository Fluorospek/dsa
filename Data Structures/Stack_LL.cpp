#include<bits/stdc++.h>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node* next;
};

template<class T>
class stack_LL
{
    node<T>* top=nullptr;

    public:

    void push(T value)
    {
        node<T>* new_node=new node<T>;
        new_node->data=value;
        if(top==nullptr)
        {
            top=new_node;
            top->next=nullptr;
        }
        else
        {
            new_node->next=top;
            top=new_node;
        }
    }

    void pop()
    {
        if(top==nullptr)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            node<T>* temp=top;
            cout<<"Deleted element: "<<temp->data<<endl;
            top=top->next;
            delete temp;
        }
    }

    void peek()
    {
        cout<<top->data<<endl;
    }

    void print_stack()
    {
        if(top==nullptr)
        cout<<"Stack is empty"<<endl;
        else
        {
            node<T>* temp=top;
            while(temp!=nullptr)
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
    }
};

int main()
{
    stack_LL<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.peek();
    stack.push(40);
    stack.pop();
    stack.print_stack();
}