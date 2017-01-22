// Sum of 2 linked lists

#include<stdio.h>
#include<iostream>

using namespace std;
struct node
{
    int data;
    struct node* next=NULL;
};

typedef struct node node;

node* create(int n)
{
	node* head = NULL; 
	node* tail = NULL; 
	int i =0;
    while(i<n)
    {
    	cout<<"Enter data"<<endl;
    	node* temp = new node();
    	cin>>temp->data;    	
    	if(head==NULL)
    	{
    		tail = temp;
    		head = temp;
	   	}
    	else
    	{
    		tail->next = temp;
    		tail = temp;
    	}
    	i++;
    }
    return (head);
}

void printnode(node* s)
{
	node* curr = s;
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}

node* reverse(node* s)
{
	node* ptr=NULL;
	node* current = s;
	node* next;
	while(current!=NULL)
	{
		next = current->next;
		current->next = ptr;
		ptr = current;
		current = next;
	}
	return (ptr);
}

node* add(node* ra, node* rb)
{
	node* head = NULL;
	node* tail = NULL;
	int sum = 0;
	int extra = 0;
	while( ra || rb || extra)
	{
		sum = (ra ? ra->data:0) + (rb ? rb->data:0) + extra;
		extra = sum/10;
		node* ans = new node();
		ans->data = sum % 10;
		if(head==NULL)
		{
			head = ans;
			tail = ans;
		}
		else
		{
			tail->next = ans;
			tail = ans;
		}
		if(ra){
			ra = ra->next;
		}
		if(rb){
			rb = rb->next;
		}
		
	}
	return (head);
}

int main()
{
	cout<<"Enter 1st No:"<<endl;
	node* a = create(3);
	cout<<"Enter 2nd No:"<<endl;
	node* b = create(1);
	// cout<<"Print 1st No:"<<endl;
	// printnode(a);
	// cout<<"Print 2nd No:"<<endl;
	// printnode(b);
	node* ra = reverse(a);
	node* rb = reverse(b);
	// printnode(ra);
	// printnode(rb);
	node* ans = add(ra, rb);
	printnode(reverse(ans));
	return (0);
}