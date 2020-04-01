#include<iostream>
#include<string>
using namespace std;
int main()
 {
	//code
	int map[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    for(auto i:s)
	    cout<<map[i-97];
	    cout<<endl;
	   // cout<<endl;
	}
	return 0;
}
