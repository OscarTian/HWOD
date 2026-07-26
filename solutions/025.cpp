#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;
int main()
{
    string temp;
    vector<vector<int>> n;
    while(cin>>temp)
    {
        if(temp.size()!=3)
        {
            cout<<"ERROR";
            return 0;
        }
        if(!isdigit(temp[0])||temp[1]!='/'||(temp[2]!='Y'&&temp[2]!='N'))
        {
            cout<<"ERROR";
            return 0;
        }
        bool yn;
        yn=temp[2]=='Y'? 1:0;
        n.push_back({temp[0]-'0',yn});
    }
    int s=n.size();
    vector<int> a;
    vector<int> b;
    bool location=0;
    a.push_back(n[0][0]);
    if(s==1)
    {
        cout<<n[0][0];
        return 0;
    }
    for(int i=1;i<s;i++)
    {
        if(location^n[i][1]==0)
        {
            b.push_back(n[i][0]);
            location=1;
        }
        else
        {
            a.push_back(n[i][0]);
            location=0;
        }
    }
    sort(a.begin(),a.end());
    if(b.size()==0)
    {
        for(int i=0;i<a.size();i++)
            cout<<a[i]<<' ';
        cout<<endl;
        return 0;
    }
    sort(b.begin(),b.end());
    if(a[0]<b[0])
    {
        for(int i=0;i<a.size();i++)
            cout<<a[i]<<' ';
        cout<<endl;
        for(int i=0;i<b.size();i++)
            cout<<b[i]<<' ';
        return 0;
    }
    for(int i=0;i<b.size();i++)
        cout<<b[i]<<' ';
    cout<<endl;
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<' ';
    return 0;
}
