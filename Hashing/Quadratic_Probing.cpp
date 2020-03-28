// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void QuadraticProbing(int hash[],int hashSize,int arr[],int sizeOfArray);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    int hash[hashSize];
	    
	    
	    
	    int  sizeOfArray;
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    
	    for(int i=0;i<hashSize;i++)
	    hash[i]=-1;
	    
	    QuadraticProbing( hash, hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	    
	}
	return 0;
}// } Driver Code Ends

void QuadraticProbing(int hash[],int hashSize,int arr[],int sizeOfArray)
{
    //Your code here
    for(int i=0;i<sizeOfArray;i++)
    {
        int j=0;
        while(true)
        {
            if(hash[((arr[i]%hashSize)+(j*j))%hashSize]==-1)
            {
                hash[((arr[i]%hashSize)+(j*j))%hashSize]=arr[i];
                break;
            }
            j++;
        }
    }
}
