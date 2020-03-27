// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

void segragate012(int A[], int N);

int main() {

    int T;
    cin >> T;

    while(T--){
        int N;
        cin >>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin >> A[i];
        }

        segragate012(A, N);

        for(int i=0;i<N;i++){
            cout << A[i]  << " ";
        }

        cout << endl;
        
        
    }

}
// } Driver Code Ends

// Function to segregate 0s, 1s and 2s
// A[]: input array
// N: size of array
void segragate012(int A[], int N)
{
    //Your code here
    int l=0,m=0,h=N-1;
    
    while(m<=h)
    {
        switch(A[m])
        {
            case 0:{
                swap(A[l],A[m]);
                m++;
                l++;
                break;
            }
            case 1:{
                m++;
                break;
            }
            case 2:
            {
                swap(A[h],A[m]);
                h--;
                break;
            }
        }
    }
}
