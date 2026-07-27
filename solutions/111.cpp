#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool anti101(int a)
{
    vector<int> digit;
    while(a/16>0)
    {
        digit.push_back(a%16);
        a=a/16;
    }
    digit.push_back(a);
    for(int i=0;i<digit.size();i++)
    {
        if(digit[i]==5||digit[i]==10||digit[i]==13||digit[i]==11)
            return 0;
        if(i!=digit.size()-1)
        {
            if((digit[i]==4||digit[i]==6||digit[i]==7)&&(digit[i+1]==1||digit[i+1]==3||digit[i+1]==7||digit[i+1]==9||digit[i+1]==15))
                return 0;
            if((digit[i]==8||digit[i]==9||digit[i]==12||digit[i]==14||digit[i]==15)&&(digit[i+1]==2||digit[i+1]==6||digit[i+1]==14))
                return 0;
        }
    }
    return 1;
}
int main()
{
    int l,r;
    cin>>l>>r;
    int ans=0;
    for(int i=l;i<=r;i++)
        ans+=anti101(i);
    cout<<ans;
    return 0;
}
