#include <iostream>
#include <string>
using namespace std;
int main() {
    string s, l;
    cin >> s >> l;
    int i = 0;
    int last = -1;
    for (int j = 0; j < l.size() && i < s.size(); ++j) {
        if (l[j] == s[i]) {
            i++;
            last = j;
        }
    }
    if (i == s.size()) {
        cout << last << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
