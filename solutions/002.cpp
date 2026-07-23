#include <iostream>
#include <string>
#include <vector>
using namespace std;
string url(string s){
    int ss=s.size();
    size_t pos = s.find(','); 
    s[pos]='/';
    if(pos<ss-1&&s[pos+1]=='/')
        s.erase(pos+1,1);
    if(pos>0&&s[pos-1]=='/')
        s.erase(pos-1,1);
    return s;
}
int main(){
    string s;
    cin>>s;
    cout<<url(s);
    return 0;
}
