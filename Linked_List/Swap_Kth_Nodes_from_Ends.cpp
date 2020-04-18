// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void append(Node** head_ref, Node **tail_ref, int new_data)
{
    Node* newnode = new Node(new_data);
    
    if(*head_ref == NULL)
        *head_ref = newnode;
    else
        (*tail_ref)->next = newnode;
    *tail_ref = newnode;
}

Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K;
        cin>>num>>K;
        int temp;
        Node* head = NULL;
        Node* tail = NULL;
        for(int i = 0; i<num; i++){
            cin>>temp;
            append(&head, &tail, temp);
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends
//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

// Should swap Kth node from beginning and Kth
// node from end in list and return new head.
Node *swapkthnode(Node* head, int num, int K)
{
    // Your Code here
    if(K>num)
    return head;
    
    Node *res,*temp;
    
    if(K==1||K==num)
    {
        int t = num-2;
        temp = head;
        
        while(t--)
        temp=temp->next;
    
        res = temp->next;
        temp->next->next = head->next;
        temp->next = head;
        head->next=NULL;
    }
    else
    {
        int t = num-K-1;
        temp = res = head;
        
        while(t--)
        head=head->next;
        
        t = K-2;
        
        while(t--)
        temp=temp->next;
        
        if(temp->next==head)
        {
            temp->next = temp->next->next;
            Node *t = head->next->next;
            head->next->next = head;
            head->next = t;
        }
        else if(head->next==temp)
        {
            head->next = head->next->next;
            Node *t = temp->next->next;
            temp->next->next = temp;
            temp->next = t;
        }
        else
        {
            swap(head->next->next,temp->next->next);
            swap(head->next,temp->next);
        }
    }
    return res;
}

