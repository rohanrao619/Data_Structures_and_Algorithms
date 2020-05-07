#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
    struct TrieNode *child[26];
    bool isEnd;
    
    TrieNode()
    {
        isEnd = false;
        for(int i=0;i<26;i++)
        child[i] = NULL;
    }
};

void insertWord(TrieNode *root,string word)
{
    for(int i=0;i<word.length();i++)
    {
        if(root->child[word[i]-97]!=NULL)
        root = root->child[word[i]-97];
        else
        {
            TrieNode *temp = new TrieNode();
            root->child[word[i]-97] = temp;
            root = temp;
        }
    }
    
    root->isEnd = true;
}

bool searchWord(TrieNode *root,string word)
{
    for(int i=0;i<word.length();i++)
    {
        if(root->child[word[i]-97]!=NULL)
        root = root->child[word[i]-97];
        else
        return false;
    }
    
    return(root->isEnd==true);
}

int main()
 {
	//code
	int T;
	cin>>T;
	
	while(T--)
	{
	    int n,q;
	    string word;
	    cin>>n>>q;
	    
	    TrieNode *root = new TrieNode();
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>word;
	        insertWord(root,word);
	    }
	    
	    while(q--)
	    {
	        cin>>word;
	    
	        if(searchWord(root,word))
	        cout<<"1"<<endl;
	        else
	        cout<<"0"<<endl;
	    }
	}
	return 0;
}
