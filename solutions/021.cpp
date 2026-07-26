#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main() {
    vector<int> nums;
    int x;
    while (cin >> x) {
        nums.push_back(x);
    }
    vector<int> st;
    for (int cur : nums) {
        if (cur > 0) {
            st.push_back(cur);
        } else {
            int left_power = -cur;
            bool alive = true;
            while (!st.empty() && st.back() > 0) {
                int& right_power = st.back();
                if (right_power == left_power) {
                    st.pop_back();
                    alive = false;
                    break;
                } else if (right_power > left_power) {
                    right_power -= left_power;
                    alive = false;
                    break;
                } else {
                    st.pop_back();
                }
            }
            if (alive) {
                st.push_back(cur);
            }
        }
    }
    cout << st.size() << endl;
    return 0;
}
