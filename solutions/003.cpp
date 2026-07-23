#include <iostream>
#include <vector>
using namespace std;
void answer(vector<int>& a) {
    int n = a.size();
    for (int len = 1; len <= n; ++len) {
        if (n % len != 0) continue;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] != a[i % len]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int k = 0; k < len; ++k)
                cout << a[k] << " ";
            return;
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    answer(a);
    return 0;
}
