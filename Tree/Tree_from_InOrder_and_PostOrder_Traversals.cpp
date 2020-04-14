// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays

Node *treeFromInPost(int in[],int post[],int start,int end,int &curr_index)
{
    if(start>end)
    return NULL;
    
    Node *newNode = new Node(post[curr_index]);
    curr_index--;
    
    int i;
    for(i=start;i<=end;i++)
    {
        if(in[i]==newNode->data)
        break;
    }
    
    newNode->right = treeFromInPost(in,post,i+1,end,curr_index);
    newNode->left = treeFromInPost(in,post,start,i-1,curr_index);
    
    return newNode;
}


Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int curr_index = n-1;
    Node * root = treeFromInPost(in,post,0,n-1,curr_index);
    return root;
    
}

