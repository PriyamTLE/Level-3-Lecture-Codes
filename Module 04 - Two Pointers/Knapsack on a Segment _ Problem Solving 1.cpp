#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> w(n), c(n); // w: weights, c: profits

    for (auto &i : w) cin >> i;
    for (auto &i : c) cin >> i;

    int left = 0, right = 0;
    int weight = 0, profit = 0, answer = 0;

    for (right = 0; right < n; ++right) {
        weight += w[right];      // include current item
        profit += c[right];

        // shrink window from left if weight exceeds limit
        while (weight > W) {
            weight -= w[left];
            profit -= c[left];
            left++;
        }

        answer = max(answer, profit); // update max profit
    }

    cout << answer << "\n";
    return 0;
}