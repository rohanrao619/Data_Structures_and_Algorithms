// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

string caseSort(string str, int n){
    
    // your code here
    string res = str;
    
    sort(str.begin(),str.end());
    
    int i=0,j;
    
    for(j=0;j<n;j++)
    if(int(str[j])>=97)
    break;
    
    for(int k=0;k<n;k++)
    {
        if(int(res[k])<97)
        {
            res[k]=str[i];
            i++;
        }
        else
        {
            res[k]=str[j];
            j++;
        }
    }
    
    return res;
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		
		cout<<caseSort (str, n)<<endl;
	}
}  // } Driver Code Ends
