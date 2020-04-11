// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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
struct Node* pairwise_swap(struct Node* head)
{
    // your code here
    if(head->next==NULL)
    return head;
    
    Node *curr=head->next,*prev=head,*res=head->next,*temp;
    
    while(curr->next && curr->next->next)
    {
        temp=curr->next;
        prev->next = curr->next->next;
        curr->next = prev;
        prev = temp;
        curr=prev->next;
    }
    
        if(curr->next==NULL)
        {
            curr->next=prev;
            prev->next=NULL;
        }
        else
        {
            temp=curr->next;
            curr->next=prev;
            prev->next=temp;
        }
        
        return res;
    
}

// { Driver Code Starts.
void printList(struct Node* node) 
{ 
    while (node!=NULL) 
    { 
        printf("%d ", (node)->data); 
        node = (node)->next; 
    } 
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n, l;
        cin>>n;
         struct Node* head = NULL;
      struct Node* tail = NULL;
        
        for(int i = 1; i <= n; i++)
        {
            cin>>l;
            append(&head,&tail, l);
        }
        head =pairwise_swap(head);
        printList(head);
        cout << endl;
    }
}  // } Driver Code Ends
