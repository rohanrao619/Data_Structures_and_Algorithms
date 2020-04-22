// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number
string largestNumber(int n, int sum){
    // Your code here
    if(sum>(9*n))
    return "-1";
    
    string res = "";
    
    while(n--)
    res+="0";
    
    int curr_sum=0,i=0; 
    
    while(sum)
    {
        if((curr_sum+9)<sum)
        {
            res[i++]='9';
            sum-=9;
        }
        else
        {
            res[i++] = char(sum+48);
            sum = 0;
        }
    }
    
    return res;
}

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n,sum;
		cin>>n>>sum;

		cout<<largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends
