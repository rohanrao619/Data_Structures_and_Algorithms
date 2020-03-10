// { Driver Code Starts
//Initial Template for C++
/* C++ program to find roots of a quadratic equation */
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

//You need to complete this function
void quadraticRoots(int a,int b, int c)
{
   
   //Your code here
   
   int D;
   float root1,root2;
   
   D = (b*b)-(4*a*c);
   
   if(D<0)
   {
       cout<<"Imaginary";
       return;
   }
   
   root1 = (-b+sqrt(D))/(2.0*a);
   root2 = (-b-sqrt(D))/(2.0*a);
   
   cout<<floor(root1)<<" "<<floor(root2);
   
   
   // Your don't need to printline
   // It will automatically be handled by driver code
}



// { Driver Code Starts.

int main() {
	int T; 
	cin>>T; //input number of testcases
	
	while(T--)
	{
	    int a, b, c; 
	    cin>>a>>b>>c; //Input a, b, and c
	    
	    quadraticRoots(a,b,c);
	    cout<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
