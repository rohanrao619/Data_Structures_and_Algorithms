// { Driver Code Starts
// C++ program Find concatenated string with 
// uncommon characters of given strings 
#include <bits/stdc++.h> 
using namespace std; 

string concatenatedString(string, string);

/* Driver program to test above function */
int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	string res = concatenatedString(s1, s2);
    	
    	if(res.length() >= 1) cout << res << endl;
    	else cout << "-1" << endl;
	
	}
	return 0; 
}
// } Driver Code Ends
// Function which concatenate two strings
// after removing common characters
string concatenatedString(string s1, string s2) 
{ 
    // Your code here
    string s="";
    
    unordered_map<char,int> map;
    
    for(char i:s1)
    map[i]=1;
    
    for(char i:s2)
    {
        if(map.count(i)==1)
        {
            if(map[i]==1)
            map[i]=-1;
        }
        else
        map[i]=0;
    }
    
    for(char i:s1)
    if(map[i]!=-1)
    s+=i;
    
    for(char i:s2)
    if(map[i]!=-1)
    s+=i;
    
    return s;
    
    
}

