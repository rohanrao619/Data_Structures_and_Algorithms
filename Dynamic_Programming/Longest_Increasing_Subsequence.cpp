// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        cout << longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends

// Function to find longest subsequence
int longestSubsequence(int n, int a[]){
    
   // your code here
   vector<int> vec;
   
   vec.push_back(a[0]);
   
   for(int i=1;i<n;i++)
   {
       if(a[i]>vec.back())
       vec.push_back(a[i]);
       else
       {
           auto it = lower_bound(vec.begin(),vec.end(),a[i]);
           (*it) = a[i];
       }
   }
   
   return vec.size();
    
}

