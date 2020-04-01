// { Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void reverseWords(char*);

/* Driver function to test above functions */
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[10000];
        cin >> s;
        reverseWords(s);
        cout<<endl;
    }
}// } Driver Code Ends
/*Function to reverse words*/
void reverseWords(char *s) {
    
    // Your code here
    int len=strlen(s),i;
    
    reverse(s,s+len);
    
    int curr=0;
    
    for(i=0;i<len;i++)
    if(s[i]=='.')
    {
        reverse(s+curr,s+i);
        curr=i+1;
    }
    
    reverse(s+curr,s+len);
    
    for(i=0;i<len;i++)
    cout<<s[i];
    
}

