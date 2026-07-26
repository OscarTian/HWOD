#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> a{1,2,4};
char alphabet[26]={'a','b','c','d','e','f',
'g','h','i','j','k','l','m','n','o','p',
'q','r','s','t','u','v','w','x','y','z'};
string turn(string s)
{
    string ans;
    if(s.size()>a.size())
        for(size_t i=a.size();i<s.size();i++)
            a.push_back((a[i-1]+a[i-2]+a[i-3])%26);
    for(size_t i=0;i<s.size();i++)
    {
        int j=0;
        for(;j<26;j++)
            if(alphabet[j]==s[i])
                break;
        ans+=alphabet[(j+a[i])%26];
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    string s;
    getline(cin,s);
    for(int z=0;z<n;z++)
    {
        getline(cin,s);
        cout<<turn(s)<<endl;
    }
    return 0;
}
