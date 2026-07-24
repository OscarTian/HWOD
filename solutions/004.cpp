#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int c;
    cin>>c;
    unsigned long long restime=31744ULL;
    for(int i=0;i<c;i++)
    {
        int t;
        unsigned long long m;
        cin>>t>>m;
        m=m>=128?  ((m%16 | 0x10) << ((m%128)/16 + 3)):m;
        restime=min(restime,t+m);
    }
    cout<<restime;
    return 0;
}
