#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    int mini;
    while(m>0)
    {
        int i=0;
        for(;i<n;i++)
            if(i==n-1||(i<n-1&&a[i+1]!=a[i]))
                break;
        if(i==n-1)
        {
            mini=a[0]+m/n;
            cout<<mini;
            return 0;
        }
        int j=i;
        while(a[0]!=a[i+1]&&m>0)
        {
            a[j]+=1;
            m-=1;
            j--;
            if(j==-1)
                j=i;
        }
    }
    mini=a[0];
    cout<<mini;
    return 0;
}
