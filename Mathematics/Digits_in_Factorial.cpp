// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

//You need to complete this function
int digitsInFactorial(int N)
{
    //Your code here
    
    float digits = 0;
    
    for (int i=N; i>1; i--)
    digits += log10(i);
    
    return floor(digits)+1;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        cout<<digitsInFactorial(N)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
