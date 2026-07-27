#include <numeric>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main()
{
    int n,m;
    cin>>n>>m;
    bool found=0;
    for(int i=n;2*i*i+2*i<=m*m-1;i++)
    {
        for(int j=i+1;i*i+j*j<=m*m;j++)
        {
            int k=sqrt(i*i+j*j);
            if(k*k==i*i+j*j)
            {
                if(gcd(i,j)+gcd(i,k)+gcd(k,j)==3)
                {
                    found=1;
                    cout<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }
    }
    if(!found)
        cout<<"NA"<<endl;
    return 0;
}
