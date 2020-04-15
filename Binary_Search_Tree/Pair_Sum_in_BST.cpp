// { Driver Code Starts
// Initial Template for C++

// CPP program to find a pair with
// given sum using hashing
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}


bool findPair(Node* root, int sum);

// Driver code
int main() {

    int t;
    cin >> t;
    while (t--) {
        Node* root = NULL;
        int n, x;
        cin >> n;
        int val;
        for (int i = 0; i < n; i++) {
            cin >> val;
            root = insert(root, val);
        }
        cin >> x;
        if (findPair(root, x))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}// } Driver Code Ends
/* BST Node
struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

// This function should return true
// if there is a pair in given BST with
// given sum.


bool FindSumPair(Node* root, int sum,unordered_set<int> &S)
{
    if(root==NULL)
    return false;
    
    if(S.count(sum-root->data)==1)
    {
        return true;
    }
    else
    S.insert(root->data);
    
    return FindSumPair(root->left,sum,S)||FindSumPair(root->right,sum,S);
}

bool findPair(Node* root, int sum) {
    // Your code here
    unordered_set<int> S;
    return FindSumPair(root,sum,S);
}




