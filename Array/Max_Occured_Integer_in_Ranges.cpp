// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends
// L and R are input array
// maxx : maximum in R[]
// n: size of array
// arr[] : declared globally with size equal to maximum in L[] and R[]
int maxOccured(int L[], int R[], int n, int maxx){

    // Your code here
    int i,prefix[maxx+1]={0},max,maxIndex=0;
    
    for(i=0;i<n;i++)
    {   
        prefix[L[i]]++;
        prefix[R[i]+1]--;
        
    }
    
    max=prefix[0];
    for(i=1;i<=maxx;i++)
    {
        prefix[i]+=prefix[i-1];
        
        if(prefix[i]>max)
        {
            max=prefix[i];
            maxIndex=i;
        }
    }
    
    return maxIndex;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    int L[n];
	    int R[n];
	    for(int i = 0;i<n;i++){
	        cin >> L[i];
	    }
	    
	    int maxx = 0;
	    for(int i = 0;i<n;i++){
	        
	        cin >> R[i];
	        if(R[i] > maxx){
	            maxx = R[i];
	        }
	    }
	    
	    cout << maxOccured(L, R, n, maxx) << endl;
	}
	
	return 0;
}  // } Driver Code Ends
