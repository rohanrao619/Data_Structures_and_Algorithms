// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

bool isIsogram(string s);

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        string s;
        cin>>s;
        
        cout<<isIsogram(s)<<endl;
        
    }
	return 0;
}// } Driver Code Ends
//Complete this function
bool isIsogram(string s)
{
    //Your code here
    int freq[256]={0};
    
    for(auto i:s)
    {
        freq[i]++;
        
        if(freq[i]>1)
        return 0;
    }
    
    return 1;
}
