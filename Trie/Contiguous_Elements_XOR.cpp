#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
    struct TrieNode *child[2];
    int value;
    
    TrieNode()
    {
        child[0] = NULL;
        child[1] = NULL;
    }
};

void insertWord(TrieNode *root,int word)
{
    for(int i=0;i<32;i++)
    {
        bool j = word&(1<<(31-i));
        
        if(root->child[j]!=NULL)
        root = root->child[j];
        else
        {
            TrieNode *temp = new TrieNode();
            root->child[j] = temp;
            root = temp;
        }
    }
    
    root->value = word;
}

int searchMax(TrieNode *root,int word)
{
    for(int i=0;i<32;i++)
    {
        bool j = word&(1<<(31-i));
        
        if(root->child[1-j]!=NULL)
        root = root->child[1-j];
        
        else
        root = root->child[j];
    }
    
    return word^(root->value);
}

int main()
 {
	//code
	int T;
	cin>>T;
	
	while(T--)
	{
	    int n,num,XOR;
	    cin>>n;
	    TrieNode *root = new TrieNode();
	    
	    int result = INT_MIN;
	    
	    cin>>num;
	    result = max(result,num);
	    XOR = num;
	    insertWord(root,num);
	    
	    for(int i=1;i<n;i++)
	    {
	        cin>>num;
	        XOR = XOR^num;
	        insertWord(root,XOR);
	        result = max(result,searchMax(root,XOR));
	    }
	    
	    cout<<result<<endl;
	}
	return 0;
}
