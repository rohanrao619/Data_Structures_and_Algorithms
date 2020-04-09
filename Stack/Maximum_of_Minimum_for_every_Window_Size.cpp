// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
void printMaxOfMin(int arr[], int n);
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        printMaxOfMin(a, n);
    }
    return 0;
}
// } Driver Code Ends
// Function to print maximum of minimum of every window size
// arr[]: input array
// n: size of array
void printMaxOfMin(int arr[], int n) {
    
    stack<int> s;
  
    int left[n+1];   
    int right[n+1];  
  
    for (int i=0; i<n; i++) 
    { 
        left[i] = -1; 
        right[i] = n; 
    } 
  
    for (int i=0; i<n; i++) 
    { 
        while (!s.empty() && arr[s.top()] >= arr[i]) 
            s.pop(); 
  
        if (!s.empty()) 
            left[i] = s.top(); 
  
        s.push(i); 
    } 
    
    while (!s.empty()) 
        s.pop(); 
  
    for (int i = n-1 ; i>=0 ; i-- ) 
    { 
        while (!s.empty() && arr[s.top()] >= arr[i]) 
            s.pop(); 
  
        if(!s.empty()) 
            right[i] = s.top(); 
  
        s.push(i); 
    } 
    
    int res[n+1]; 
    for (int i=0; i<=n; i++) 
    res[i] = 0; 
    
    for (int i=0; i<n; i++) 
    { 
        int len = right[i] - left[i] - 1; 
        res[len] = max(res[len], arr[i]); 
    } 
  
    for (int i=n-1; i>=1; i--) 
    res[i] = max(res[i], res[i+1]); 
  
    for (int i=1; i<=n; i++) 
    cout << res[i] << " ";
    
    cout<<endl;
}
