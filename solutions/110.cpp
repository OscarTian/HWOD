#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> points;
vector<int> ttl;
int n,m;
bool comp(int a,int b)
{
    if(ttl[a]>ttl[b])
        return 0;
    if(ttl[a]<ttl[b])
        return 1;
    vector<int> anum(10);
    vector<int> bnum(10);
    for(int i=0;i<10;i++)
    {
        int temp=0;
        for(int j=0;j<m;j++)
        {
            if(points[j][a]==10-i)
                temp++;
            if(points[j][b]==10-i)
                temp--;
        }
        if(temp>0)
            return 0;
        if(temp<0)
            return 1;
    }
    return 0;
}
int main()
{
    string s;
    getline(cin,s);
    for(int x=0;x<s.size();x++)
            if(s[x]==',')
                s[x]=' ';
    stringstream sss(s);
    sss>>m;
    if(m<3||m>10)
    {
        cout<<-1;
        return 0;
    }
    sss>>n;
    if(n<3||n>100)
    {
        cout<<-1;
        return 0;
    }
    ttl.assign(n, 0);
    points.resize(m);
    for(int i=0;i<m;i++)
    {
        getline(cin,s);
        for(int x=0;x<s.size();x++)
            if(s[x]==',')
                s[x]=' ';
        stringstream ss(s);
        int str;
        for(int j=0;j<n;j++)
        {
            ss>>str;
            if(str<1||str>10)
            {
                cout<<-1;
                return 0;
            }
            points[i].push_back(str);
            ttl[j]+=points[i][j];
        }
    }
    int top1,top2,top3;
    top1=0;
    if(comp(0,1))
    {
        top1=1;
        top2=0;
    }
    else
        top2=1;
    if(comp(top2,2))
    {
        top3=top2;
        if(comp(top1,2))
        {
            top2=top1;
            top1=2;
        }
        else
            top2=2;
    }
    else
        top3=2;
    for(int i=3;i<n;i++)
    {
        if(comp(top3,i))
        {
            top3=i;
            if(comp(top2,i))
            {
                top3=top2;
                top2=i;
                if(comp(top1,i))
                {
                    top2=top1;
                    top1=i;
                }
            }
        }
    }
    cout<<top1+1<<","<<top2+1<<","<<top3+1;
    return 0;
}
