// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 
 // } Driver Code Ends
 

// Function to count number of pairs such that x^y is greater than y^x
// X[], Y[]: input array
// m, n: size of arrays X[] and Y[] respectively
long long countPairs(int X[], int Y[], int m, int n)
{
   long long count_1 = 0;
   long long count_2 = 0;
   long long count_3 = 0;
   long long count_4 = 0;
   
   sort(Y,Y+n);
   
   for(int i=0;i<n;i++)
   {
       switch(Y[i])
       {
           case 1:{
               count_1++;
               break;
           }
           case 2:{
               count_2++;
               break;
           }
           case 3:{
               count_3++;
               break;
           }
           case 4:{
               count_4++;
               break;
           }
       }
   }
   
   long long result = 0,count_x_1=0;
   
   for(int i=0;i<m;i++)
   {    
       if(X[i]==1)
       {
           count_x_1 ++;
           continue;
       }
       
       auto it = upper_bound(Y,Y+n,X[i]);
       result += distance(it,Y+n);
       
       if(X[i]==2)
       {
           if(count_3)
           result-=count_3;
           
           if(count_4)
           result-=count_4;
       }
       else if(X[i]==3 and count_2)
       result+=count_2;
   }
   
   if(count_1)
   result += (count_1*(m-count_x_1));
   
   return result;
}


// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		cout<<countPairs(a, b, M, N)<<endl;
	}
}  // } Driver Code Ends
