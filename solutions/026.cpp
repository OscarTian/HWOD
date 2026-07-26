#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
using namespace std;
int algorithm(string type,string a,string b)
{
    if(type=="add")
        return stoi(a)+stoi(b);
    if(type=="sub")
        return stoi(a)-stoi(b);
    if(type=="mul")
        return stoi(a)*stoi(b);
    if(stoi(a)*stoi(b)<0&&stoi(a)%stoi(b)!=0)
        return stoi(a)/stoi(b)-1;
    return stoi(a)/stoi(b);
}
int main()
{
    string orig;
    getline(cin,orig);
    for(int i=0;i<orig.size();i++)
        if(orig[i]=='('||orig[i]==')')
        {
            orig.replace(i,1," "+string(1,orig[i])+" ");
            i+=2;
        }
    stringstream ss(orig);
    string temp;
    vector<string> s;
    while(ss>>temp)
    {
        if(temp[temp.size()-1]!=')')
            s.push_back(temp);
        else
        {
            string b=s.back();
            s.pop_back();
            string a=s.back();
            s.pop_back();
            string type=s.back();
            s.pop_back();
            s.pop_back();
            if(type=="div"&&b=="0")
            {
                cout<<"error";
                return 0;
            }
            s.push_back(to_string(algorithm(type,a,b)));
        }
    }
    int ans=stoi(s.back());
    cout<<ans;
    return 0;
}
