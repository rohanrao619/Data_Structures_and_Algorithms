// { Driver Code Starts
//Initial Template for C++

// CPP code to find floor of a key in BST 
#include <bits/stdc++.h> 
using namespace std; 

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

/* This function is used to insert 
new values in BST*/
Node* insert(Node* root, int key) 
{ 
	if (!root) 
		return new Node(key); 
	if (key < root->data) 
		root->left = insert(root->left, key); 
	else
		root->right = insert(root->right, key); 
	return root; 
} 


 // } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

// Function to find ceil of a given input in BST. If input is more 
// than the max key in BST, return -1 
int findCeil(Node* root, int input) 
{ 
    // Base case 
    if (root == NULL) 
        return -1; 
  
    // Your code here
    if (!root) 
	return INT_MAX; 

    int res = -1;
    
    while(root)
    {
        if(input<root->data)
        {
            res = root->data;
            root = root->left;
        }
        else if(input>root->data)
        {
            root=root->right;
        }
        else
        {
            res = input;
            break;
        }
    }
    
    return res;
    
    
} 

// { Driver Code Starts.

int main() 
{ 
	
	int t;
	cin >> t;
	
	while(t--){
	    Node* root = NULL;
	    int n, x;
	    cin >> n;
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	        if(root == NULL) root = insert(root, arr[i]);
	        else insert(root, arr[i]);
	    }
	    cin >> x;
	    cout << findCeil(root, x) << endl;
	}
	
	return 0; 
}  // } Driver Code Ends
