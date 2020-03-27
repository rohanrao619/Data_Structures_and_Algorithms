// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//arr1,arr2 : the arrays
// n, m: size of arrays
void findUnion(int arr1[], int arr2[], int n, int m)
{
    //Your code here
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            if(i==0 || arr1[i]!=arr1[i-1])
            cout<<arr1[i]<<" ";
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            if(j==0 || arr2[j]!=arr2[j-1])
            cout<<arr2[j]<<" ";
            j++;
        }
        else
        {
            if(i==0 || arr1[i]!=arr1[i-1])
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        
    }
    
    while(i<n)
    {
        if(i==0 || arr1[i]!=arr1[i-1])
        cout<<arr1[i]<<" ";
        i++;
    }
    
    while(j<m)
    {
        if(j==0 || arr2[j]!=arr2[j-1])
        cout<<arr2[j]<<" ";
        j++;
    }
    
}

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    
	    findUnion(arr1,arr2, N, M);
	    
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
