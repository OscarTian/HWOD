#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <numeric>          // 新增：用于 accumulate
#include <functional>
using namespace std;

// 新增函数：判断能否将 nums 分成 k 个和为 target 的子集
bool canPartition(vector<int>& nums, int k, int target) {
    if (k == 1) return true;                     // 只剩一份，一定可以
    int n = nums.size();
    vector<bool> used(n, false);
    sort(nums.begin(), nums.end(), greater<int>()); // 降序加速剪枝
    if (nums[0] > target) return false;          // 最大元素超过目标，不可能

    function<bool(int, int, int)> dfs = [&](int cur, int start, int filled) -> bool {
        if (filled == k - 1) return true;        // 最后一个桶不用检查，总和必对
        if (cur == target) {                     // 当前桶填满，开始下一个桶
            return dfs(0, 0, filled + 1);
        }
        for (int i = start; i < n; ++i) {
            if (used[i] || cur + nums[i] > target) continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue; // 剪枝
            used[i] = true;
            if (dfs(cur + nums[i], i + 1, filled)) return true;
            used[i] = false;
            if (cur == 0) return false;          // 当前桶第一个数都放不进去，失败
        }
        return false;
    };
    return dfs(0, 0, 0);
}

int main()
{
    int maxi = 0;
    int ttl = 0;
    int t;
    cin >> t;
    vector<int> points(t);
    for (int i = 0; i < t; i++) {
        cin >> points[i];
        maxi = max(maxi, points[i]);
        ttl += points[i];
    }
    int ans = ttl;   // 初值：所有人分数加起来（一个人包揽）
    // 枚举人数 i，从最多可能的人数（总分/最大单分）递减到 1
    for (int i = ttl / maxi; i >= 1; i--) {
        if (ttl % i == 0) {
            int target = ttl / i;
            if (canPartition(points, i, target)) {
                ans = target;   // 找到更小的每人得分
                break;          // 因为 i 递减，第一个找到的就是最小得分
            }
        }
    }
    cout << ans;
    return 0;
}
