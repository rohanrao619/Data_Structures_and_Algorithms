// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class FindMedian
{
	public:
		void insertHeap(int &);
		double getMedian();
	private:
		priority_queue<int> max; //Max heap for lower values
		priority_queue<int, vector<int>, greater<int> > min; //Min heap for greater values
		void balanceHeaps(); //Method used by insertHeap
};


 // } Driver Code Ends

// Function to insert heap
void FindMedian::insertHeap(int &x)
{
	// Your code here
	if(max.empty() || min.empty())
	max.push(x);
	else
	{
	    if(x>max.top())
	    min.push(x);
	    else
	    max.push(x);
	}
	balanceHeaps();
}

// Function to balance heaps
void FindMedian::balanceHeaps()
{
	// Your code here
	if((max.size()-min.size())<=1)
	return;
	
	if(max.size()>min.size())
	{
	    min.push(max.top());
	    max.pop();
	}
	else
	{
	    max.push(min.top());
	    min.pop();
	}
	
}

// Function to return getMedian
double FindMedian::getMedian()
{
	// Your code here
	if((max.size()+min.size())%2==1)
	return max.top();
	else
	return (floor((max.top()+min.top())/2));
}


// { Driver Code Starts.

int main()
{
    int n, x;
	FindMedian Ans;
	cin >> n;
	for(int i = 1;i<= n; ++i)
	{
		cin >> x;
		Ans.insertHeap(x);
	    cout << floor(Ans.getMedian()) << endl;
	}
	// }
	return 0;
}  // } Driver Code Ends
