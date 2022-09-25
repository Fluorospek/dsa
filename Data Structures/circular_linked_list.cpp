#include<bits/stdc++.h>
using namespace std;

template<class T>
struct node
{
	T data;
	struct node<T>* next;
};

template<class T>
class clinkedlist
{
	node<T>* head=nullptr;
	node<T>* tail=nullptr;
	
	public:
		
		void createnode(T value)
		{	
			node<T>* new_node=new node<T>;
			new_node->data=value;
			
			if(head==nullptr)
			{
				head=new_node;
				tail=new_node;
				tail->next=head;
			}
			else
			{
				tail->next=new_node;
				tail=new_node;
				tail->next=head;
			}
		}
		
		void iterate()
		{
			node<T>* temp=head;
			cout<<"Entered linked list is:"<<endl;
			do
			{
				cout<<temp->data<<endl;
				temp=temp->next;
			}while(temp!=head);
		}
		
		void insert_start(int value)
		{
			node<T>* new_node=new node<T>;
			new_node->data=value;
			new_node->next=head;
			head=new_node;
			tail->next=head;	
		}
		
		void insert_end(int value)
		{
			node<T>* new_node=new node<T>;
			new_node->data=value;
			tail->next=new_node;
			tail=new_node;
			tail->next=head;
		}
		
		void insert(int pos,int value)
		{
			node<T>* new_node=new node<T>;
			new_node->data=value;
			node<T>* temp=head;
			for(int i=1;i<pos-1;i++)
			temp=temp->next;
			new_node->next=temp->next->next;
			temp->next=new_node;
		}
		
		void delete_node(int pos)
		{
			node<T>* temp=head;
			if(pos!=1)
			{
				for(int i=1;i<pos-1;i++)
				temp=temp->next;
				temp->next=temp->next->next;
			}
			else
			{
				head=head->next;
				tail->next=head;
			}
		}
		
		void search(int value)
		{
			node<T>* temp=head;
			int i=1,flag=1;
			do
			{
				if(temp->data==value)
				{
					cout<<"Found at position: "<<i;
					flag=0;
					break;
				}
				else
				{
					temp=temp->next;
					++i;
				}
			}while(temp!=head);
			
			if(flag)
			cout<<"Value not found"<<endl;
		}
		
		void iterate_tail()
		{
			node<T>* temp=head;
			do
			{
				cout<<temp->data<<endl;
				temp=temp->next;
			}while(temp!=head);
			cout<<temp->data<<endl;
		}
		
		void size_list()
		{
			node<T>* temp=head;
			int i=0;
			do
			{
				i+=1;
				temp=temp->next;
			}while(temp!=head);
			cout<<"Size of the linked list is: "<<i<<endl;
		}
};

int main()
{
	clinkedlist<int> list;
	int count,value,pos;
	cout<<"Enter number of nodes to be created"<<endl;
	cin>>count;
	for(int i=0;i<count;i++)
	{
		cout<<"Enter a value:"<<endl;
		cin>>value;
		list.createnode(value);
	 }
	 list.iterate();
	 cout<<"-------------------"<<endl;
	//  list.insert_start(30);
	//  list.iterate();
	//  cout<<"-------------------"<<endl;
	//  list.insert_end(100);
	//  list.iterate();
	//  cout<<"-------------------"<<endl;
	//  cin>>pos;
	//  list.insert(pos,90);
	//  list.iterate();
	//  cin>>pos;
	//  list.delete_node(pos);
	//  list.iterate();
	// list.search(4);
	// list.iterate_tail();
	// list.size_list();
	return 0;
}