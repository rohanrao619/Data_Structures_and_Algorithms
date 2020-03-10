// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

bool isPrime(int N)
{
    //Your code here
    
    if((!(N%6==1||N%6==5))&&(N>3))
    return 0;
    
    for(int i=2; i<=sqrt(N); i++)
    if(N%i==0)
    return 0;
    
    return 1;
}

//Complete this function
int exactly3Divisors(int N)
{
    
    int count=0;
    
    for(int i=4;i<=N;i++)
    {
        if((sqrt(i)-floor(sqrt(i)))>0)
        continue;
        if(isPrime(sqrt(i)))
        count++;
    }
    
    return count;
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
        cout<<exactly3Divisors(N)<<endl;
    }
	return 0;
}  // } Driver Code Ends
