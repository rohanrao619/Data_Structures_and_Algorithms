// { Driver Code Starts
// Program to find best buying and selling days

#include <bits/stdc++.h>
using namespace std;
 
// solution structure
struct Interval
{
    int buy;
    int sell;
};



 // } Driver Code Ends
// solution structure
/* struct Interval
 {
     int buy;
     int sell;
 };*/

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n)
{
    
    // Your code here
    int i,start=-9;
    
    if(price[0]<price[1])
    start=0;
    
    for(i=1;i<n-1;i++)
    {
        
        if((price[i]<=price[i-1])&(price[i]<price[i+1]))
        start=i;
        
        if((price[i]>=price[i-1])&(price[i]>price[i+1]))
        {
            cout<<"("<<start<<" "<<i<<")"<<" ";
            start=-1;
        }
    }
    
    if(start==-9)
    {
        cout<<"No Profit";
        return;
    }
    
    if(start!=-1)
    cout<<"("<<start<<" "<<i<<")"<<" ";
}

// { Driver Code Starts.
 
// Driver program to test above functions
int main()
{   
    
    int price[10000],n,i,T;
    
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&price[i]);
    // fucntion call
    stockBuySell(price, n);
    cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
