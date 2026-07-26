#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> cost(n,vector<int>(3));
    for(int i=0;i<n;i++)
        cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
    int banned=-1;
    int temp=-1;
    int ttlcost=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
            if(banned!=j)
            {
                if(temp==-1)
                    temp=j;
                else if(cost[i][j]<=cost[i][temp])
                    temp=j;
            }
        banned=temp;
        ttlcost+=cost[i][temp];
        temp=-1;
    }
    cout<<ttlcost;
    return 0;
}
