#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    long long t;
    cin>>n>>t;
    vector<int> a(n,0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    vector<long long> dp(n);
    dp[0]=a[0];
    if(n==1)
    {
        if(dp[0]<=t)
        {
            cout<<1<<" "<<dp[0];
            return 0;
        }
        cout<<0<<" "<<0;
        return 0;
    }
    if(dp[0]>t)
    {
        cout<<0<<" "<<0;
        return 0;
    }
    dp[1]=min(10*a[0],a[1]);
    if(dp[1]>t)
    {
        cout<<1<<" "<<dp[0];
        return 0;
    }
    for(int i=2;i<n;i++)
    {
        dp[i]=min(dp[i-1]+a[0]+min(10*a[0],a[i]),dp[i-2]+a[0]+a[1]+min(a[i],10*a[i-1])+min(a[1],10*a[0]));
        if(dp[i]>t)
        {
            cout<<i<<" "<<dp[i-1];
            return 0;
        }
    }
    cout<<n<<" "<<dp[n-1];
    return 0;
}
