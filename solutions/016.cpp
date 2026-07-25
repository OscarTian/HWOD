#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
bool isVowel(char c) {
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
int main() {
    int flaw;
    cin >> flaw;
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + (isVowel(s[i]) ? 0 : 1);
    }
    vector<int> earliest(n + 2, -1);
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (isVowel(s[i])) {
            int cur = pref[i];
            if (earliest[cur] == -1) earliest[cur] = i;
            int target = cur - flaw;
            if (target >= 0 && earliest[target] != -1) {
                ans = max(ans, i - earliest[target] + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
