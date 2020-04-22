// { Driver Code Starts


// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
// Prints minimum number of platforms reqquired 

bool comparator(Job A,Job B)
{
    return A.profit>B.profit;
}

void printJobScheduling(Job arr[], int n) 
{ 
    // your code here
    bool taken[n];
    int count=0,res=0;
    
    for(int i=0;i<n;i++)
    taken[i]=false;
    
    sort(arr,arr+n,comparator);
    
    for(int i=0;i<n;i++)
    {
        int j = (arr[i].dead)-1;
        
        if(j>=n)
        j = n-1;
        
        while(taken[j]==true && j>=0)
        j--;
        
        if(j!=-1)
        {
            count++;
            taken[j]=true;
            res += arr[i].profit;
        }
    }
    
    cout<<count<<" "<<res<<endl;
} 

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        Job arr[n];
        
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        printJobScheduling(arr, n);
    }
	return 0; 
}


  // } Driver Code Ends
