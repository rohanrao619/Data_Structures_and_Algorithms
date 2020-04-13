// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

/*you are required to
complete this function */
bool isEqual(Node *t1,Node *t2)
{
    if(t1==NULL && t2==NULL)
    return true;
    
    if(t1==NULL || t2==NULL)
    return false;
    
    return ((t1->data)==(t2->data))&&isEqual(t1->left,t2->left)&&isEqual(t1->right,t2->right);
    
}

void findRoots(Node *root,int head,queue<Node *> &q)
{
    if(root==NULL)
    return;
    
    if(root->data == head)
    q.push(root);
    
    findRoots(root->left,head,q);
    findRoots(root->right,head,q);
    
}

bool isSubTree(Node* T, Node* S) {
    // Your code here
    // return 1 if S is subtree of T else 0
    
    queue<Node *> q;
    
    findRoots(T,S->data,q);
    
    if(q.empty())
    return 0;
    
    while(!q.empty())
    {
        if(isEqual(q.front(),S))
        return 1;
        
        q.pop();
    }
    
    return 0;
    
}

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Node *rootS = buildTree(strS);
        cout << isSubTree(rootT, rootS) << "\n";

    }


    return 0;
}  // } Driver Code Ends
