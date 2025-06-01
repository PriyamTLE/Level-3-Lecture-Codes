#include <bits/stdc++.h>
using namespace std;

vector<int> sliding_window_minimum(vector<int>& a, int k) {
    int n = a.size();
    vector<int> ans;
    deque<int> deq;
    // deq.push_back((INT_MAX));

    for (int i = 0; i < n; i++) {
        while (!deq.empty() && a[deq.back()] >= a[i])
            deq.pop_back();
        deq.push_back(i);

        if (deq.front() == i - k)
            deq.pop_front();

        if (i >= k - 1)
            ans.push_back(a[deq.front()]);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 3, 1, 2, 4, 5, 1, 7, 2};
    int k = 3;

    vector<int> res = sliding_window_minimum(arr, k);

    for (int x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}