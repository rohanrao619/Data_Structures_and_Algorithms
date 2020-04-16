// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
   int data;
   Node* left;
   Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
   Node* temp = new Node;
   temp->data = val;
   temp->left = NULL;
   temp->right = NULL;

   return temp;
}



vector<int> merge(Node *root1,Node *root2);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = newNode(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);

       vector<int> vec = merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends
/* The structure of Node is
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};*/

/*You are required to complete below method */
vector<int> merge(Node *root1, Node *root2)
{
   //Your code here
   vector<int> vec;
   
   stack<pair<int,Node *>> s1,s2;
   Node *temp;
   
   while(root1)
   {
       s1.push({root1->data,root1});
       root1 = root1->left;
   }
   
   while(root2)
   {
       s2.push({root2->data,root2});
       root2 = root2 ->left;
   }
   
   while(!s1.empty() && !s2.empty())
   {
       if(s1.top().first<=s2.top().first)
       {
           
           vec.push_back(s1.top().first);
           temp = s1.top().second->right;
           s1.pop();
           
           if(temp!=NULL)
           {
               while(temp)
               {
                   s1.push({temp->data,temp});
                   temp = temp->left;
               }
           }
       }
       else
       {
           vec.push_back(s2.top().first);
           temp = s2.top().second->right;
           s2.pop();
           
           if(temp!=NULL)
           {
               while(temp)
               {
                   s2.push({temp->data,temp});
                   temp = temp->left;
               }
           }
       }
   }
   
   while(!s1.empty())
   {
        vec.push_back(s1.top().first);
        temp = s1.top().second->right;
        s1.pop();
           
        if(temp!=NULL)
        {
            while(temp)
            {
                s1.push({temp->data,temp});
                temp = temp->left;
            }
        }
   }
   
   while(!s2.empty())
   {
        vec.push_back(s2.top().first);
        temp = s2.top().second->right;
        s2.pop();
           
        if(temp!=NULL)
        {
            while(temp)
            {
                s2.push({temp->data,temp});
                temp = temp->left;
            }
        }
   }
   
   
   return vec;
}
