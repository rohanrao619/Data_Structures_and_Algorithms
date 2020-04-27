#include <bits/stdc++.h>
using namespace std;
 
int minJumps(int arr[],int n);
 
int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int arr[n];
		
		for(int i=0;i<n;i++)
		cin>>arr[i];
		
		cout << minJumps(arr,n) << endl;
	}
    
    return 0;
    
}

int minJumps(int arr[],int n){
    
    vector<int> DP(n,INT_MAX);
    int minimum;
    DP[0] = 0;
    
    for(int i=1;i<n;i++)
    {
        minimum = INT_MAX;
        
        for(int j=0;j<i;j++)
        if(i<=(j+arr[j]))
        {
            minimum = min(minimum,DP[j]);
        }
        
        if(minimum!=INT_MAX)
        DP[i] = 1+minimum;
    }
    
    return (DP[n-1]==INT_MAX?-1:DP[n-1]);
}

