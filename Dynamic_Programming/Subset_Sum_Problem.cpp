#include<iostream>
using namespace std;

bool isPossible(int arr[],int n,int sum)
{
    bool DP[n+1][sum+1];
    
    for(int i=1;i<=sum;i++)
    DP[0][i] = false;
    
    for(int i=0;i<=n;i++)
    DP[i][0]=true;
    
    for(int i=1;i<=n;i++)
    for(int j=0;j<=sum;j++)
    {
        DP[i][j] = DP[i-1][j];
        
        if(j>=arr[i-1])
        DP[i][j] = DP[i][j]|DP[i-1][j-arr[i-1]];
    }
    
    return DP[n][sum];
}

int main()
 {
	int T;
	cin>>T;
	
	while(T--)
	{
	    int n,sum=0;
	    cin>>n;
	    
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    
	    if(sum%2==1)
	    cout<<"NO"<<endl;
	    else
	    cout<<(isPossible(arr,n,sum/2)==true?"YES":"NO")<<endl;
	}
	return 0;
}
