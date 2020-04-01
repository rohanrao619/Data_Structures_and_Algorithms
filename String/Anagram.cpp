// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*  Function to check if two strings are anagram
*   c, d: input string
*/
bool isAnagram(string c, string d){
    
    // Your code here
    if(c.length()!=d.length())
    return 0;
    
    unordered_map<char,int> map;
    
    for(int i=0;i<c.length();i++)
    {
        map[c[i]]++;
    }
    
    for(int i=0;i<d.length();i++)
    {
        if(map.count(d[i])==0)
        return 0;
        
        map[d[i]]--;
        
        if(map[d[i]]==0)
        map.erase(d[i]);
    }
    
    return map.empty();
}


// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;

        if(isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends
