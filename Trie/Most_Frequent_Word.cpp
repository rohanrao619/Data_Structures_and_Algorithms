#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
    struct TrieNode *child[26];
    int isEnd,firstIndex;
    
    TrieNode()
    {
        isEnd = 0;
        for(int i=0;i<26;i++)
        child[i] = NULL;
    }
};

pair<int,int> insertWord(TrieNode *root,string word,int index)
{
    int i;
    
    for(i=0;i<word.length();i++)
    {
        if(root->child[word[i]-97]!=NULL)
        {   
            root = root->child[word[i]-97];
        }
        else
        {
            TrieNode *temp = new TrieNode();
            root->child[word[i]-97] = temp;
            root = temp;
        }
    }
    
    if(root->isEnd==0)
    root->firstIndex = index;
    
    root->isEnd = root->isEnd+1;
    
    return {root->isEnd,root->firstIndex};
}

int main()
 {
	//code
	int T;
	cin>>T;
	
	while(T--)
	{
	    int n,m = INT_MIN,curr_i;
	    string word,result;
	    cin>>n;
	    
	    TrieNode *root = new TrieNode();
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>word;
	        pair<int,int> res = insertWord(root,word,i);
	        
	        if(res.first>m)
	        {
	            curr_i = res.second;
	            m = res.first;
	            result = word;
	        }
	        else if(res.first==m)
	        {
	            if(res.second>curr_i)
	            {
	                curr_i = res.second;
	                result = word;
	            }
	        }
	    }
	    
	    cout<<result<<endl;
	}
	return 0;
}
