// { Driver Code Starts
// C Program for counting sort
#include <stdio.h>
#include <string.h>
#define RANGE 255

// The main function that sort the given string arr[] in
// alphabatical order
void countSort(char arr[]);

// Driver program to test above function
int main()
{
    long int t;
    scanf("%ld",&t);
    while(t--)
    {
        long int n;
        scanf("%ld",&n);
        char arr[n+1];
        scanf("%s",arr);
        countSort(arr);
    printf("%s\n", arr);
    }return 0;
}
// } Driver Code Ends
// The main function that sort the given string arr[] in
// alphabatical order
void countSort(char arr[])
{

// Your code goes here
    int i,n=0;
    for(i=0;arr[i]!='\0';i++)
    n++;
    
    int count[26];
    char temp[n+1];
    
    for(i=0;i<26;i++)
    count[i]=0;
    
    for(i=0;i<n;i++)
    count[int(arr[i])-97]++;
    
    for(i=1;i<26;i++)
    count[i]+=count[i-1];
    
    for(i=n-1;i>=0;i--)
    {
        temp[count[int(arr[i])-97]-1]=arr[i];
        count[int(arr[i])-97]--;
    }
    
    for(i=0;i<n;i++)
    arr[i]=temp[i];
}
