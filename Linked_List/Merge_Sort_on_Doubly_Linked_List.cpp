// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


 // } Driver Code Ends
/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */
struct Node * Merge(struct Node *left,struct Node *right,int lcount,int rcount)
{
    Node *res = NULL,*previous=NULL,*start;
    
    while(lcount && rcount)
    {
        if(right->data<left->data)
        {
        	if(res==NULL)
        	{
        		res = right;
        		start = res;
			}
        	else
        	{
        		res->next = right;	
        		res = res->next;
			}
            
            right = right->next;
            rcount--;
        }
        else
        {
            if(res==NULL)
        	{
        		res = left;
        		start = res;
			}
        	else
        	{
        		res->next = left;	
        		res = res->next;
			}
            
            left = left->next;
            lcount--;
        }
        
        res->prev = previous;
        previous = res;
        
    }
    
    while(lcount--)
    {
        res->next = left;
        left = left->next;
        res = res->next;
        res->prev = previous;
        previous = res;
    }
    
    while(rcount--)
    {
        res->next = right;
        right = right->next;
        res = res->next;
        res->prev = previous;
        previous = res;
    }
    
    res->next=NULL;
    return start;
}

struct Node* MSort(struct Node *head,int count)
{
    if(count==1)
    return head;
    
    int lcount,rcount,t;
    
    Node *temp=head;
    rcount = count/2;
    lcount = count-rcount;
    t = lcount;
   
    
    while(t--)
    {
    	temp=temp->next;
	}
    
    head = MSort(head,lcount);
    temp = MSort(temp,rcount);
    
    head = Merge(head,temp,lcount,rcount);
    
    return head;
}

// Function to merge two DLLs
struct Node *sortDoubly(struct Node *head)
{
	// Your code here
	int count = 0;
	Node *temp=head;
	
	while(temp)
	{
	    count++;
	    temp=temp->next;
	}
 	
 	return MSort(head,count);
}


// { Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}


// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}
  // } Driver Code Ends
