// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*  Function to check if str1 can be formed from
*   str2 after rotation by 2 places
*/
bool isRotated(string str1, string str2)
{
    // Your code here
    if(str1.length()!=str2.length())
    return 0;
    
    if(str1.length()<=2)
    return str1==str2;
    
    str1+=str1;
    
    if((str1.substr(2,str2.length())==str2)||(str1.substr(str2.length()-2,str2.length())==str2))
    return 1;
    else
    return 0;
}


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		cout<<isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
