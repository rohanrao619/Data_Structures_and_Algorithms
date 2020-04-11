// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */
#include<cmath>

bool isPalindrome(Node *head)
{
    //Your code here
    if(head->next==NULL)
    return 1;
    
    int count=0,t;
    Node *temp=head,*first=head,*second,*curr,*prev;
    
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    
    if(count%2==0)
    t = (count/2)-1;
    else
    t = count/2;
    
    temp = head;
    while(t--)
    temp=temp->next;
    
    second=temp;
    
    prev=NULL;
    curr=temp->next;
    
    while(curr->next)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    
    curr->next=prev;
    
    second->next = curr;
    second=second->next;
    
    while(second)
    {
        if(first->data != second->data)
        return 0;
        
        first=first->next;
        second=second->next;
    }
    
    return 1;
}


