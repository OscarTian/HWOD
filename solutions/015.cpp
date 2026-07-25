#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
long long di(int n)
{
    int i=1;
    while(n/10>0)
    {
        n=n/10;
        i++;
    }
    long long ans=1;
    for(int j=0;j<i;j++)
        ans*=10;
    return ans;
}
int main()
{
    char te;
    string temp;
    vector<int> num;
    while(cin>>te)
    {
        if(isdigit(te))
            temp+=te;
        else if(te==',')
        {
            num.push_back(stoi(temp));
            temp.clear();
        }
    }
    num.push_back(stoi(temp));
    if(num.size()==1)
    {
        cout<<num[0];
        return 0;
    }
    if(num.size()==2)
    {
        cout<<min(num[0]+di(num[0])*num[1],num[1]+di(num[1])*num[0]);
        return 0;
    }
    sort(num.begin(),num.end());
    cout<<min(min(min(num[0]*(di(num[1])*di(num[2]))+num[1]*di(num[2])+num[2],num[0]*(di(num[1])*di(num[2]))+num[2]*di(num[1])+num[1]),min(num[1]*(di(num[0])*di(num[2]))+num[0]*di(num[2])+num[2],num[1]*(di(num[2])*di(num[0]))+num[2]*di(num[0])+num[0])),min(num[2]*(di(num[0])*di(num[1]))+num[0]*di(num[1])+num[1],num[2]*(di(num[1])*di(num[0]))+num[1]*di(num[0])+num[0]));
    return 0;
}
