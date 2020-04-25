#include <iostream>
#include <boost/multiprecision/cpp_int.hpp> 

using namespace boost::multiprecision;
using namespace std;

int256_t DP[100];

int main()
{
    DP[0]=1;
    DP[1]=1;
    
    for(int i=2;i<=100;i++)
    DP[i] = (DP[i-1]*(4*i-2))/(i+1);
    
    int T;
    cin>>T;
    
    while(T--)
    {
        int n;
        cin>>n;
        
        cout<<DP[n]<<endl;
    }
    
	return 0;
}
