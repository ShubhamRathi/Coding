// Merge two sorted linked lists
#include <stdio.h> 
#include <iostream>
using namespace std;

typedef struct ListNode {
  int val;
  ListNode * next=NULL;
} ListNode;

ListNode* create(int n)
{
  ListNode* head = NULL; 
  ListNode* tail = NULL; 
  int i =0;
    while(i<n)
    {
      cout<<"Enter data"<<endl;
      ListNode* temp = new ListNode();
      cin>>temp->val;      
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

ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
  ListNode *tail, *head;
  if (l1->val <= l2-> val)
  {
    head = l1;
    l1=l1->next;
  }
  else
  {
    head = l2;
    l2 = l2->next;
  }
  tail = head;
  while (l1 && l2) {
    if (l1 -> val < l2 -> val) {
      tail -> next = l1;
      l1 = l1 -> next;
    } else {
      tail -> next = l2;
      l2 = l2 -> next;
    }
    tail = tail -> next;
  }

  tail -> next = l1 ? l1 : l2;
  return head;
}

void printListNode(ListNode* s)
{
  ListNode* curr = s;
  while(curr!=NULL)
  {
    cout<<curr->val<<" ";
    curr=curr->next;
  }
  cout<<endl;
}

int main()
{
  cout<<"Enter 1st List:"<<endl;
  ListNode* a = create(3);
  cout<<"Enter 2nd List:"<<endl;
  ListNode* b = create(3);
  ListNode* ans = mergeTwoLists(a, b);
  printListNode(ans);
  return (0);
}