// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

void buildSolution(vector<int> A,vector<vector<int>> &res,vector<int> &curr_sol,int &curr_sum,int sum,int pos)
{
    for(int i=pos;i<A.size();i++)
    {
        curr_sum += A[i];
        curr_sol.push_back(A[i]);
        
        if(curr_sum==sum)
        {
            res.push_back(curr_sol);
        }
        else if(curr_sum<sum)
        {
            buildSolution(A,res,curr_sol,curr_sum,sum,i);
        }
        
        curr_sol.pop_back();
        curr_sum -= A[i];
    }
}

void removeDup(vector<int> &v)
{
    vector<int>::iterator ip = unique(v.begin(), v.end()); 
    v.resize(distance(v.begin(), ip)); 
}

vector<vector<int>> combinationSum(vector<int> &A, int sum) {
    // Your code here
    
    vector<vector<int>> res;
    vector<int> curr_sol;
    int curr_sum = 0;
    sort(A.begin(),A.end());
    removeDup(A);
    
    buildSolution(A,res,curr_sol,curr_sum,sum,0);
    
    return res;
}

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        vector<vector<int> > result;
   		result=combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends
