#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    // Compute prefix sums
    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i)
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];

    ll max_sum = LLONG_MIN;
    deque<int> dq;

    for (int i = a; i <= n; ++i) {
        // Maintain deque for the window [i - b, i - a]
        if (!dq.empty() && dq.front() < i - b)
            dq.pop_front();

        // Add new index to deque
        while (!dq.empty() && prefix_sum[dq.back()] >= prefix_sum[i - a])
            dq.pop_back();
        dq.push_back(i - a);

        // Update maximum sum
        max_sum = max(max_sum, prefix_sum[i] - prefix_sum[dq.front()]);
    }

    cout << max_sum << endl;
    return 0;
}
