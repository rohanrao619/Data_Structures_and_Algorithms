// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

char getMaxOccuringChar(char*);

int main()
{
   
    char str[100];
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%s",str);
    cout<< getMaxOccuringChar(str)<<endl;
    }
}// } Driver Code Ends
// Function to get maximum occuring 
// character in given string str
char getMaxOccuringChar(char* str)
{
    // Your code here
    int count[256]={0};
    
    for(int i=0;str[i]!='\0';i++)
    count[str[i]]++;
    
    int max=0,res;
    
    for(int i=0;i<256;i++)
    if(count[i]>max)
    {
        max=count[i];
        res=i;
    }
    
    return char(res);
}

