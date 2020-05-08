#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
    struct TrieNode *child[52];
    bool isEnd;
    int count;
    
    TrieNode()
    {
        isEnd = false;
        count = 0;
        for(int i=0;i<52;i++)
        child[i] = NULL;
    }
};

void insertWord(TrieNode *root,string word)
{
    for(int i=0;i<word.length();i++)
    {
        int index; 
        
        if(isupper(word[i]))
        index = word[i]-65+26;
        else
        index = word[i]-97;
        
        if(root->child[index]!=NULL)
        root = root->child[index];
        else
        {
            TrieNode *temp = new TrieNode();
            root->child[index] = temp;
            root = temp;
        }
    }
    
    root->isEnd = true;
    root->count = root->count + 1;
}

void findPattern(TrieNode *root,string pattern,vector<pair<string,string>> &result,string curr,string cap_curr)
{
    if(root->isEnd==true and pattern=="")
    {
        for(int i=0;i<root->count;i++)
        result.push_back({curr,cap_curr});
    }
    
    for(int i=0;i<26;i++)
    {
        if(root->child[i+26]!=NULL)
        {
            if(pattern=="")
            findPattern(root->child[i+26],pattern,result,curr+char(i+65),cap_curr+char(i+65));
            
            else if(pattern[0]==char(i+65))
            findPattern(root->child[i+26],pattern.substr(1,pattern.length()-1),result,curr+char(i+65),cap_curr+char(i+65));
        }
        else if(root->child[i]!=NULL)
        findPattern(root->child[i],pattern,result,curr+char(i+97),cap_curr);
    }
}

bool comparator(pair<string,string> A,pair<string,string> B)
{
    return A.second<B.second;
}

int main()
 {
	//code
	int T;
	cin>>T;
	
	while(T--)
	{
	    int n;
	    string word,pattern;
	    vector<pair<string,string>> result;
	    
	    cin>>n;
	    
	    TrieNode *root = new TrieNode();
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>word;
	        insertWord(root,word);
	    }
	    
	    cin>>pattern;
	    findPattern(root,pattern,result,"","");
	    
	    sort(result.begin(),result.end(),comparator);
	    
	    if(result.empty())
	    cout<<"No match found";
	    else for(auto i:result)
	    cout<<i.first<<" ";
	    
	    cout<<endl;
	}
	return 0;
}
