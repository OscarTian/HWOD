#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    long long ans=0;
    int y=0;
    int n;
    int e;
    cin>>n>>e;
    vector<vector<int>> offset;
    int temp1,temp2;
    for(int i=0;i<n;i++)
    {
        cin>>temp1>>temp2;
        offset.push_back({temp1,temp2});
    }
    int x=0;
    for(int i=0;i<e;i++)
    {
        if(offset[x][0]==i)
        {
            y+=offset[x][1];
            if(x==offset.size()-1)
            {
                ans+=(e-i)*abs(y);
                cout<<ans;
                return 0;
            }
            x++;
        }
        ans+=abs(y);
    }
    cout<<ans;
    return 0;
}
