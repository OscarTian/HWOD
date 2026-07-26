#include <string>
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ss=s.size();
    int signal=-1;
    int count=0;
    if(ss==1)
    {
        int ans=s[0]=='I'? 0:-1;
        cout<<ans;
        return 0;
    }
    for(int i=0;i<ss;i++)
    {
        if(s[i]=='M')
        {
            if(i!=0&&i!=ss-1)
            {
                if(s[i-1]=='M'&&s[i+1]=='M')
                {
                    cout<<-1;
                    return 0;
                }
                if(i-1!=signal)
                {
                    if(s[i+1]=='I')
                    {
                        signal=i+1;
                        count++;
                    }
                    else 
                    {
                        signal=i-1;
                        count++;
                    }
                    
                }
            }
            else if(i==0)
            {
                if(s[1]=='M')
                {
                    cout<<-1;
                    return 0;
                }
                count++;
                signal=1;
            }
            else if(i==ss-1)
            {
                if(s[ss-2]=='M')
                {
                    cout<<-1;
                    return 0;
                }
                if(signal!=ss-2)
                {
                    signal=ss-2;
                    count++;
                }
            }
        }
    }
    cout<<count;
    return 0;
}
