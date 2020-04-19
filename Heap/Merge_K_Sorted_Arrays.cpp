// { Driver Code Starts
#include<bits/stdc++.h>


#define N 105
using namespace std;

int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}// } Driver Code Ends
// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
struct Element
{
    int k,i,value;
    
    Element(int k,int i,int value)
    {
        this->k = k;
        this->i = i;
        this->value = value;
    }
};

struct Comparator
{
    bool operator()(Element A,Element B)
    {
        return A.value>B.value;
    }
};


int *mergeKArrays(int arr[][N], int k)
{
//code here
priority_queue<Element,vector<Element>,Comparator> PQ;

int *res = new int[k*k];
int ind=0;

for(int i=0;i<k;i++)
{
    Element newElement(i,0,arr[i][0]);
    PQ.push(newElement);
}

while(!PQ.empty())
{
    Element temp = PQ.top();
    res[ind++]=temp.value;
    
    PQ.pop();
    
    if(temp.i<(k-1))
    {
        Element newElement(temp.k,temp.i+1,arr[temp.k][temp.i+1]);
        PQ.push(newElement);
    }
    
}

return res;

}
