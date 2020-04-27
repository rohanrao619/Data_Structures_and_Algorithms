// { Driver Code Starts

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//Complete this function
long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
{
    long long minimumNumberOfCoinsRequired[value+1]={0};
    //The above array holds the minimum number of coins for every amount from 0 to value
    
    
    minimumNumberOfCoinsRequired[0]=0;
    //
    
    for(int i=1;i<value+1;i++)
    {
        minimumNumberOfCoinsRequired[i]=INT_MAX;
        //We fill all array with inifinty as intially we need infinite coins to make the value
    }
    
    vector<int> coinsSet;
    
    for(int i=0;i<numberOfCoins;i++)
    {
        coinsSet.push_back(coins[i]);
    }
    
    int minC; 
    
    for(int i=1;i<value+1;i++) 
    {
        minC = INT_MAX;
        
        for(auto coin:coinsSet)//Iterating over each coin
        {
            if(i>=coin) //No use in checking for values that are smaller than the current coin
            {
                //Your code here
                if(minC>minimumNumberOfCoinsRequired[i-coin])
                minC = minimumNumberOfCoinsRequired[i-coin];
              
            }
        }
        
        if(minC!=INT_MAX)
        minimumNumberOfCoinsRequired[i] = 1+minC;
    }
    
    return minimumNumberOfCoinsRequired[value];
}

// { Driver Code Starts.



int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int value;
	    cin>>value;
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    
	    int answer=minimumNumberOfCoins(coins,numberOfCoins,value);
	    if(answer==INT_MAX)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
