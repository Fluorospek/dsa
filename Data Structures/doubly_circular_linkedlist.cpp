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
            delete_start();
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

    void delete_start()
    {
        node<T>* temp=head;
        if(temp->next==head)
        head=nullptr;
        else
        {
            head->next->prev=tail;
            tail->next=head->next;
            head=head->next;
            delete temp;
        }
    }

    void delete_end()
    {
        node<T>* temp=tail;
        if(temp->next==head)
        head=nullptr;
        else
        {
            tail->prev->next=head;
            head->prev=tail->prev;
            tail=tail->prev;
            delete temp;
        }
    }

    void insert_node(int pos,T value)
    {
        if(pos==1)
        insert_start(value);
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

    void insert_start(T value)
    {
        if(head==nullptr)
        {
            create_node(value);
        }
        else
        {
            node<T>* new_node=new node<T>;
            new_node->data=value;
            new_node->next=head;
            new_node->prev=head->prev;
            head->prev->next=new_node;
            head->prev=new_node;
            head=new_node;
        }
    }

    void insert_end(T value)
    {
        if(head==nullptr)
        {
            create_node(value);
        }
        else
        {
            node<T>* new_node=new node<T>;
            new_node->data=value;
            new_node->next=head;
            new_node->prev=tail;
            head->prev=new_node;
            tail->next=new_node;
            tail=new_node;
        }
    }

    void insert_value(T value,T num)
    {
        node<T>* new_node=new node<T>;
        new_node->data=value;
        new_node->prev=nullptr;
        new_node->next=nullptr;
        if(head==nullptr)
        {
            head=new_node;
            head->next=head;
            head->prev=head;
        }
        else
        {
            node<T>* temp=head;
            while(temp->next!=head&&temp->data!=num)
            temp=temp->next;
            if(temp->next==head&&temp->data!=num)
            {
                cout<<"Num not found"<<endl;
            }
            else
            {
                new_node->prev=temp;
                new_node->next=temp->next;
                new_node->next->prev=new_node;
                temp->next=new_node;
            }
        }
    }

    void delete_value(T num)
    {
        if(head==nullptr)
        {
            cout<<"List is empty"<<endl;
        }
        else
        {
            node<T>* temp=head;
            while(temp->next!=head&&temp->data!=num)
            temp=temp->next;

            if(temp==head)
            {
                delete_start();
            }
            else if(temp==tail)
            {
                delete_end();
            }
            else
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
            }
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
    list.insert_start(200);
    list.insert_end(300);
    list.traverse();
    list.traverse_reverse();
    list.delete_start();
    list.delete_end();
    list.traverse();
    list.traverse_reverse();
    list.insert_value(400,3);
    list.traverse();
    list.traverse_reverse();
}