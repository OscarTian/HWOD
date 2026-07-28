#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<priority_queue<pair<int, int>>> printers(6);
    int fileId = 1;
    while (n--) {
        string op;
        cin >> op;
        if (op == "IN") {
            int p, num;
            cin >> p >> num;
            printers[p].push({num, -fileId});
            fileId++;
        } else if (op == "OUT") {
            int p;
            cin >> p;
            if (printers[p].empty()) {
                cout << "NULL" << endl;
            } else {
                cout << -printers[p].top().second << endl;
                printers[p].pop();
            }
        }
    }
    return 0;
}
