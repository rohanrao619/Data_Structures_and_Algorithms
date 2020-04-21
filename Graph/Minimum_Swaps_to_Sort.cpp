// { Driver Code Starts
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends
/* You are required to complete this method */

bool comparator(pair<int,int> A,pair<int,int> B)
{
    return A.first<B.first;
}

int minSwaps(int A[], int N){
    /*Your code here */
    vector<pair<int,int>> vec;
    bool visited[N];
    
    for(int i=0;i<N;i++)
    {
        visited[i]=false;
        vec.push_back({A[i],i});
    }
    
    sort(vec.begin(),vec.end(),comparator);
    int result=0,count=0;
    
    for(int i=0;i<N;i++)
    {
        if(visited[i]==false)
        {
            visited[i]=true;
            int j = vec[i].second;
            while(visited[j]==false)
            {
                count++;
                visited[j]=true;
                j = vec[j].second;
            }
            
            result+=count;
        }
    }
    
    return count;
}

