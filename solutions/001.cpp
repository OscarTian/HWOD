#include <iostream>
#include <string>
using namespace std;
char findChar(int n, unsigned long long k) {
    unsigned long long len = 1ULL << (n - 1);
    bool flip = false;
    while (len > 1) {
        unsigned long long mid = len / 2;
        if (k < mid) {
            flip = !flip;
        } else {
            k -= mid;
        }
        len = mid;
    }
    char base = 'R';
    if (flip) base = (base == 'R') ? 'B' : 'R';
    return base;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        unsigned long long k;
        cin >> n >> k;
        char ans = findChar(n, k);
        cout << (ans == 'R' ? "red" : "blue") << endl;
    }
    return 0;
}
