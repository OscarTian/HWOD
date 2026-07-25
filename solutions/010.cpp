#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    string line1, line2;
    if (!getline(cin, line1) || !getline(cin, line2)) {
        cout << -1 << endl;
        return 0;
    }
    stringstream ss1(line1);
    vector<int> peaches;
    int num;
    int total=0;
    bool hasValidData = false;
    while (ss1 >> num) {
        total+=num;
        peaches.push_back(num);
        hasValidData = true;
    }
    char leftover;
    if (ss1 >> leftover) {
        cout << -1 << endl;
        return 0;
    }
    if (!hasValidData) {
        cout << -1 << endl;
        return 0;
    }
    stringstream ss2(line2);
    int leaveTime;
    if (!(ss2 >> leaveTime)) {
        cout << -1 << endl;
        return 0;
    }
    if (ss2 >> leftover) {
        cout << -1 << endl;
        return 0;
    }
    if(leaveTime==0||total/leaveTime==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    int mini=total/leaveTime;
    int ans=0;
    int n=peaches.size();
    for(int i=mini;1;i++)
    {
        int time=0;
        for(int j=0;j<n;j++)
            time+=peaches[j]/i+(peaches[j]%i? 1:0);
        if(time<=leaveTime)
        {
            ans=i;
            break;
        }
    }
    cout<<ans;
    return 0;
}
