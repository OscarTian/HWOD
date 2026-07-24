#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    vector<int> jobs(n);
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i];
    }
    sort(jobs.begin(), jobs.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < m && i < n; ++i) {
        pq.push(jobs[i]);
    }
    for (int i = m; i < n; ++i) {
        int earliest = pq.top();
        pq.pop();
        pq.push(earliest + jobs[i]);
    }
    int result = 0;
    while (!pq.empty()) {
        result = max(result, (int)pq.top()); 
        pq.pop();
    }
    cout << result << endl;
    return 0;
}
