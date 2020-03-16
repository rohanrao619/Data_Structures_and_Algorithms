// { Driver Code Starts
#include <bits/stdc++.h>
#include <string>

using namespace std;

void possibleWords(int a[],int n);


int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	  possibleWords(a,N);
	   cout << endl;
	}
	
	return 0;
}// } Driver Code Ends
//Complete this function

char mapping[][8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void printPossibleWords(string curr,int a[],int i,int N)
{
    if(i==N)
    {
        cout<<curr<<" ";
        return;
    }
    
    string keys = mapping[a[i]-2];
    
    printPossibleWords(curr+keys[0],a,i+1,N);
    printPossibleWords(curr+keys[1],a,i+1,N);
    printPossibleWords(curr+keys[2],a,i+1,N);
    
    if(a[i]==7||a[i]==9)
    printPossibleWords(curr+keys[3],a,i+1,N);
}

void possibleWords(int a[],int N)
{
    //Your code here
    printPossibleWords("",a,0,N);
}
