// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends

//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

// function to return fractionalweights
bool comparator(Item A,Item B)
{
    return (double(A.value)/A.weight)>(double(B.value)/B.weight);
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    double res = 0.0;
    int curr_weight = 0; 
    
    sort(arr,arr+n,comparator);
    
    for(int i=0;i<n;i++)
    {
        if((curr_weight+arr[i].weight)<=W)
        {
            res += double(arr[i].value);
            curr_weight += arr[i].weight;
        }
        else if(curr_weight<=W)
        {
            res += (W-curr_weight)*(double(arr[i].value)/arr[i].weight);
            break;
        }
    }
    
    return res;
}

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
