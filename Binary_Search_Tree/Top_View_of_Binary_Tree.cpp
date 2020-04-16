// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends
//Structure of binary tree
/*struct Node
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
// function should print the topView of the binary tree

void levelOrderTraversal(Node *root,map<int,int> &m)
{
    queue<pair<Node *,int>> q;
    q.push({root,0});
    
    while(!q.empty())
    {
        int count = q.size();
        while(count--)
        {
            pair<Node *,int> temp = q.front();
            q.pop();
            
            if(m.count(temp.second)==0)
            m[temp.second] = temp.first->data;
            
            if(temp.first->left)
            q.push({temp.first->left,temp.second-1});
            
            if(temp.first->right)
            q.push({temp.first->right,temp.second+1});
        }
    }
}


void topView(struct Node *root)
{
    //Your code here
    if(root==NULL)
    return;
    
    map<int,int> m;
    
    levelOrderTraversal(root,m);
    
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->second<<" ";
    }
}



