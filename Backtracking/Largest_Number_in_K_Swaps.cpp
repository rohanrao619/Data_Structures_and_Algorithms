// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
void findMaximumNum(string str, int k, string& max);

// Driver code
int main() {
    int t, k;
    string str;
    cin >> t;
    while (t--) {
        cin >> k;
        cin >> str;
        string max = str;
        findMaximumNum(str, k, max);

        cout << max << endl;
    }
    return 0;
}
// } Driver Code Ends
// function to find maximum integer possible by
// doing at-most K swap operations on its digits

void isLarge(string curr,string &max,int k)
{
    if(k==0)
    return;
    // cout<<curr<<endl;
    
    for(int i=0;i<curr.length()-1;i++)
    for(int j=i+1;j<curr.length();j++)
    {
        if(curr[i]<curr[j])
        {
            swap(curr[i],curr[j]);
            
            if(curr>max)
            {
                max = curr;
                
            }
            isLarge(curr,max,k-1);
            swap(curr[i],curr[j]);
        }
    }
}


void findMaximumNum(string str, int k, string &max) {
    
    // Your code here
    string res = str,curr = str;
    isLarge(curr,res,k);
    max = res;
}

