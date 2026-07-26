#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
bool cmp(const string& a, const string& b) {
    return a + b > b + a;
}
int main() {
    string input;
    getline(cin, input);
    vector<string> nums;
    stringstream ss(input);
    string token;
    while (getline(ss, token, ',')) {
        nums.push_back(token);
    }
    sort(nums.begin(), nums.end(), cmp);
    for (const string& s : nums) {
        cout << s;
    }
    cout << endl;
    return 0;
}
