#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> orig(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>orig[i];
    vector<vector<int>> op;
    int type;
    int temp;
    for(int i=0;i<m;i++)
    {
        cin>>type;
        cin>>temp;
        op.push_back({type,temp});
    }
    vector<int> request;
    for(int i=0;i<op.size();i++)
    {
        int j;
        int re;
        int ttl=1001;
        int release=0;
        if(op[i][0]==1)
        {
            j=1;
            for(;j<=n;j++)
            {
                if(orig[j]>=op[i][1])
                {
                    if(orig[j]<ttl)
                    {
                        re=j;
                        ttl=orig[j];
                    }
                }
            }
            if(ttl==1001)
            {
                cout<<0<<" ";
                request.push_back(0);
            }
            else
            {
                orig[re]-=op[i][1];
                cout<<re<<" ";
                request.push_back(re);
            }
        }
        else
        {
            if(request[op[i][1]-1]!=0)
                orig[request[op[i][1]-1]]+=op[op[i][1]+release][1];
            release++;
        }
    }
    return 0;
}
