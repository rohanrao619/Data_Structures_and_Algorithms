// { Driver Code Starts
#include <bits/stdc++.h>
#define NIL -1
using namespace std;

void find(vector<int> adj[], stack<int> &st, int index[], int lowlink[],
          bool onstack[], int i);

int main() {

    int t; // number of test cases
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m; // n- number of nodes and m- number of edges

        int lowlink[n + 1], index[n + 1];

        // v.index, which numbers the nodes consecutively in the order in which
        // they are discovered
        // v.lowlink that represents the smallest index of any node known to be
        // reachable from v through v's DFS subtree, including v itself.

        vector<int> adj[n + 1]; // adjacency list
        bool onstack[n +
                     1]; // onstack is true if ith node is present on the stack

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        stack<int> st;

        for (int i = 0; i < n; ++i) {
            lowlink[i] = -1;
            index[i] = -1;
            onstack[i] = false;
        }

        for (int i = 0; i < n; ++i) {
            if (index[i] ==
                -1) { // index is -1 if the ith node is still not visit

                find(adj, st, index, lowlink, onstack, i); // dfs calling
            }
        }

        cout << "\n";
    }
}// } Driver Code Ends


void find(vector<int> adj[], stack<int> &st, int index[], int lowlink[],
          bool onstack[], int i) {

    // your code here
    static int curr_time = 0;
    
    index[i] = lowlink[i] = (++curr_time);
    st.push(i);
    onstack[i] = true;
    
    for(int j:adj[i])
    {
        if(index[j]==-1)
        {
            find(adj,st,index,lowlink,onstack,j);
            lowlink[i] = min(lowlink[i],lowlink[j]);
        }
        else if(onstack[j]==true)
        lowlink[i] = min(lowlink[i],index[j]);
    }
    
    if(lowlink[i]==index[i])
    {
        int curr =i;
        while(st.top()!=curr)
        {
            cout<<st.top()<<" ";
            onstack[st.top()] = false;
            st.pop();
        }
        
        onstack[i] = false;
        cout<<i<<",";
        st.pop();
    }
}
