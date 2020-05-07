#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
    struct TrieNode *child[26];
    int isEnd;
    
    TrieNode()
    {
        isEnd = 0;
        for(int i=0;i<26;i++)
        child[i] = NULL;
    }
};

string insertCity(TrieNode *root,string city)
{
    int i,flag=0;
    string code = "";
    
    for(i=0;i<city.length();i++)
    {
        if(root->child[city[i]-97]!=NULL)
        {   
            code+=city[i];
            root = root->child[city[i]-97];
        }
        else
        {
            if(flag==0)
            {
                code+=city[i];
                flag=1;
            }
            TrieNode *temp = new TrieNode();
            root->child[city[i]-97] = temp;
            root = temp;
        }
    }
    
    root->isEnd = root->isEnd+1;
    
    if(root->isEnd>1)
    code += (" "+to_string(root->isEnd));
    
    return code;
}

int main()
 {
	//code
	int T;
	cin>>T;
	
	while(T--)
	{
	    int n;
	    string word;
	    cin>>n;
	    
	    TrieNode *root = new TrieNode();
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>word;
	        cout<<insertCity(root,word)<<endl;
	    }
	}
	return 0;
}
