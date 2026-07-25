#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> ppl(n,0);
    int ttl=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>ppl[i];
        ttl+=ppl[i];
    }
    for(int i=(ttl-m)/n;i<=ttl-m;i++)
    {
        int remain=m;
        int j=0;
        for(;j<n;j++)
        {
            if(remain<ppl[j])
                break;
            remain+=i-ppl[j];
        }
        if(j==n)
        {
            ans=i;
            break;
        }
    }
    cout<<ans;
    return 0;
}
