// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
long long minCost(long long arr[], long long n) {
    // Your code here
    priority_queue<long long,vector<long long>,greater<long long>> PQ(arr,arr+n);
    long long res=0;
    
    while(PQ.size()>1)
    {
        long long a = PQ.top();
        PQ.pop();
        
        long long b = PQ.top();
        PQ.pop();
        
        res+=(a+b);
        PQ.push(a+b);
    }
    
    return res;
}

