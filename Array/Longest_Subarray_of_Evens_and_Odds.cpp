// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// arr: input array
// num: length of array
// This function returns true or false
bool checkRotatedAndSorted(int arr[], int num){
    
    // Your code here
    int inc=0,dec=0,i;
    
    for(int i=0;i<num-1;i++)
    if(arr[i]<arr[i+1])
    inc++;
    else
    dec++;
    
    if((inc*dec)==0)
    return 0;
    
    if(arr[num-1]<arr[0])
    inc++;
    else
    dec++;
    
    if(inc==1||dec==1)
    return 1;
    else
    return 0;
    
}

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--){
	    int num;
        cin>>num;
        int arr[num];
        for(int i = 0; i<num; ++i)
            cin>>arr[i];
        
        bool flag = false;
        
        flag = checkRotatedAndSorted(arr, num);
        
        if(!flag){
            cout << "No"<<endl;
        }
        else
        cout << "Yes"<<endl;
    
	}
	
	return 0;
}  // } Driver Code Ends
