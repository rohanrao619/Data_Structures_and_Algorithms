// { Driver Code Starts
#include<bits/stdc++.h>
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

Node *buildTree(int a[],int b[],int str,int end);
int preIndex=0;
void printPostOrder(Node *root){
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		preIndex=0;
		Node *root=NULL;
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		root=buildTree(a,b,0,n-1);
		printPostOrder(root);
		cout<<endl;
	}
}// } Driver Code Ends
/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
Node* buildTree(int in[],int pre[], int start, int end)
{
    if(start>end)
    return NULL;
    
    Node *newNode = new Node(pre[preIndex]);
    preIndex++;
    
    int i;
    for(i=start;i<=end;i++)
    {
        if(in[i]==newNode->data)
        break;
    }
    
    newNode->left = buildTree(in,pre,start,i-1);
    newNode->right = buildTree(in,pre,i+1,end);
    
    return newNode;
}
