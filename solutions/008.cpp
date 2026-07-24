#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
double value(string s)
{
    int exrate[5]={100,1825,123,14,12};
    int ss=s.size();
    string ld;
    int i=0;
    int type;
    while(isdigit(s[i]))
    {
        ld+=s[i];
        i++;
    }
    int lc=stoi(ld);
    if(s[i]=='C')
        type=0;
    else if(s[i]=='J')
        type=1;
    else if(s[i]=='H')
        type=2;
    else if(s[i]=='E')
        type=3;
    else if(s[i]=='G')
        type=4;
    else
    {
        if(s[i]=='f')
            type=0;
        else if(s[i]=='s')
            type=1;
        else if(s[i]=='c')
            type=2;
        else if(s[i]=='e')
            type=3;
        else if(s[i]=='p')
            type=4;
        return 100.0*lc/exrate[type];
    }
    if(i==ss-3)
        return 10000.0*lc/exrate[type];
    else
    {
        i+=3;
        string sd;
        while(isdigit(s[i]))
        {
            sd+=s[i];
            i++;
        }
        int sc=stoi(sd);
        return 100.0*(100.0*lc+sc)/exrate[type];
    }
}
int main()
{
    int n;
    cin>>n;
    double ans=0.0;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        ans+=value(s);
    }
    cout<<(int)ans;
}
