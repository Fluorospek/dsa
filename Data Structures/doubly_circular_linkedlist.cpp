#include<bits/stdc++.h>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node* next;
    struct node* prev;
};

template<class T>
class linkedlist
{
    node<T>* head=nullptr;
    node<T>* tail=nullptr;

    public:

    void create_node(T value)
    {
        node<T>* new_node=new node<T>;
        new_node->data=value;
        new_node->next=nullptr;
        new_node->prev=nullptr;

        if(head==nullptr)
        {
            head=new_node;
            tail=new_node;
            tail->next=head;
            head->prev=tail;
        }
        else
        {
            tail->next=new_node;
            new_node->prev=tail;
            new_node->next=head;
            head->prev=new_node;
            tail=new_node;
        }
    }

    void traverse()
    {
        if(head==nullptr)
        cout<<"Linked list is empty";
        else
        {
            node<T>* temp=head;
            cout<<"Entered linked list is:"<<endl;
            do
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }while(temp!=head);
        }
    }

    void traverse_reverse()
    {
        if(head==nullptr)
        cout<<"Linked list is empty"<<endl;
        else
        {
            node<T>* temp=tail;
            cout<<"Entered linked list in reverse is:"<<endl;
            do
            {
                cout<<temp->data<<endl;
                temp=temp->prev;
            } while (temp!=tail);
        }
        
    }

    void delete_node(int pos)
    {
        if(pos==1)
        {
            node<T>* temp=head;
            head->next->prev=tail;
            tail->next=head->next;
            head=head->next;
            delete temp;
        }
        else
        {
            node<T>* temp=head;
            for(int i=1;i<pos-1;i++)
            temp=temp->next;
            temp->next->next->prev=temp;
            temp->next=temp->next->next;
        }
    }

    void insert_node(int pos,T value)
    {
        if(pos==1)
        create_node(value);
        else
        {
            node<T>* temp=head;
            node<T>* new_node=new node<T>;
            new_node->data=value;
            new_node->next=nullptr;
            new_node->prev=nullptr;
            for(int i=1;i<pos-1;i++)
            temp=temp->next;
            new_node->prev=temp;
            new_node->next=temp->next;
            temp->next->prev=new_node;
            temp->next=new_node;
        }
    }
};

int main()
{
    linkedlist<int> list;
    int n,value;
    cout<<"Enter number of nodes to be created:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter a value:"<<endl;
        cin>>value;
        list.create_node(value);
    }
    list.traverse();
    list.traverse_reverse();
    list.delete_node(1);
    list.traverse();
    list.traverse_reverse();
    list.insert_node(3,100);
    list.traverse();
    list.traverse_reverse();
}