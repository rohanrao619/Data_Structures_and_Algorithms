// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;

void winner(string arr[],int n);


int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        
        winner(arr,n);
        
        cout<<endl;
        
        
    }
    return 0;
}
// } Driver Code Ends
// Funtion to find winner
// arr[]: input array
// n: size of array
void winner(string arr[],int n)
{
    //Your code here
    int max=1;
    string winner=arr[0];
    unordered_map<string,int> map;
    map[arr[0]]=1;
    for(int i=1;i<n;i++)
    {
        map[arr[i]]++;
        if(map[arr[i]]>max)
        {
            max=map[arr[i]];
            winner=arr[i];
        }
        else if(map[arr[i]]==max)
        {
            if(arr[i]<winner)
            {
                max=map[arr[i]];
                winner=arr[i];
            }
        }
    }
    
    cout<<winner<<" "<<max;
}
