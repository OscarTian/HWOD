#include <iostream>
#include <vector>
using namespace std;
int main() {
    int T, n;
    cin >> T >> n;
    vector<int> dp(T + 1, 0);
    for (int i = 0; i < n; ++i) {
        int t, w;
        cin >> t >> w;
        for (int j = T; j >= t; --j) {
            dp[j] = max(dp[j], dp[j - t] + w);
        }
    }
    cout << dp[T] << endl;
    return 0;
}
