// { Driver Code Starts
//Initial Template for C++


// CPP program to generate power set
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

void powerSet(vector <string> &vec,string s,string curr,int i)
{
    if(i<0)
    {
        vec.push_back(curr);
        return;
    }
    
    powerSet(vec,s,curr,i-1);
    powerSet(vec,s,curr+s[i],i-1);
}

//Complete this function
vector <string> powerSet(string s)
{
   //Your code here
   vector <string> vec;
   reverse(s.begin(),s.end());
   powerSet(vec,s,"",s.length()-1);
   return vec;
}


// { Driver Code Starts.


// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        vector<string> ans = powerSet(s);
        sort(ans.begin(),ans.end());
        for(auto x:ans)
        cout<<x<<" ";
        cout<<endl;
        
        
    }

return 0;
}   // } Driver Code Ends
