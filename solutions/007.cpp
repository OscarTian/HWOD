#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, t, k;
    cin >> n >> t >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> dp(k + 1, vector<int>(t + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = k; j >= 1; --j) {
            for (int s = t; s >= a[i]; --s) {
                dp[j][s] += dp[j - 1][s - a[i]];
            }
        }
    }
    cout << dp[k][t] << endl;
    return 0;
}
