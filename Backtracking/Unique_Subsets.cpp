// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

void printSubSet(string subset)
{
    if(subset.empty())
    return;
    
    cout<<"(";
    
    for(int i=0;i<subset.length()-1;i++)
    cout<<subset[i]<<" ";
    
    cout<<subset[subset.length()-1]<<")";
}

void buildSubSets(vector<int> A, string curr_set,int i,set<string> &S)
{
    if(i==A.size())
    return;
    
    curr_set += to_string(A[i]);
    buildSubSets(A,curr_set,i+1,S);
    
    if(S.count(curr_set)==0)
    S.insert(curr_set);
    
    curr_set.pop_back();
    buildSubSets(A,curr_set,i+1,S);
}

void func(vector <int> A)
{
    // Your code here
    sort(A.begin(),A.end());
    
    string curr_set;
    set<string> S;
    
    cout<<"()";
    
    buildSubSets(A,curr_set,0,S);
    
    for(auto i:S)
    printSubSet(i);
    
    cout<<endl;
}

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        func(A);
        
    }
}	  // } Driver Code Ends
