// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find inversion count in the array
// A[]: input array
// N: size of the array
long long result=0;

void merge(long long arr[], long long l, long long m, long long r)
{
     // Your code here
     long long temp[r-l+1],i,j,k;
     
     i=l;
     j=m+1;
     k=0;
     
     while((i<=m)&&(j<=r))
     {
         if(arr[i]<=arr[j])
         {
             temp[k++]=arr[i++];
         }
         else
         {
            result+=(m-i+1);
            temp[k++]=arr[j++];
         }
     }
     
     while(i<=m)
     {
         temp[k++]=arr[i++];
     }
     while(j<=r)
     {
         temp[k++]=arr[j++];
     }
     
     for(i=0;i<=(r-l);i++)
     arr[i+l]=temp[i];
}

void mergeSort(long long arr[], long long l, long long r)
{
    if (l < r)
    {
        long long m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

long long int inversionCount(long long A[],long long N)
{
    result=0;
    mergeSort(A,0,N-1);
    return result;

}


// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
