#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    vector<int> power(n);
    for(int i=0;i<n;i++)
        cin>>power[i];
    sort(power.begin(),power.end());
    vector<vector<int>> dp(n);
    int match,gap;
    match=0;
    gap=0;
    dp[0]={match,gap};
    if(power[1]-power[0]<=d)
    {
        match=1;
        gap=power[1]-power[0];
        dp[1]={match,gap};
    }
    else
        dp[1]={0,0};
    for(int i=2;i<n;i++)
    {
        if(power[i]-power[i-1]>d)
            dp[i]=dp[i-1];
        else
        {
            if(dp[i-2][0]+1>dp[i-1][0])
                dp[i]={dp[i-2][0]+1,dp[i-2][1]+power[i]-power[i-1]};
            else
            {
                if(dp[i-2][1]+power[i]-power[i-1]<dp[i-1][1])
                    dp[i]={dp[i-1][0],dp[i-2][1]+power[i]-power[i-1]};
                else
                    dp[i]={dp[i-1][0],dp[i-1][1]};
            }
        }
    }
    if(dp[n-1][0]==0)
    {
        cout<<-1;
        return 0;
    }
    cout<<dp[n-1][1];
    return 0;
}
