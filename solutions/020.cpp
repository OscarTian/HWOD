#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    string target;
    string source;
    cin>>target>>source;
    int t=target.size()-1;
    int s=source.size()-1;
    for(;s>=0&&t>=0;s--)
    {
        if(source[s]==target[t])
        {
            if(t==0)
            {
                cout<<s;
                return 0;
            }
            t--;
        }
    }
    cout<<-1;
    return 0;
}
