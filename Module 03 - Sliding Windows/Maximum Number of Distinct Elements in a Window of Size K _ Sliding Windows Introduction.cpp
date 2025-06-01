#include <bits/stdc++.h>
using namespace std;

int maxDistinctElementsWithSet(const vector<int>& arr, int k) {
    int maxDistinct = 0;

    for (int i = 0; i <= arr.size() - k; ++i) {
        set<int> s;
        for (int j = i; j < i + k; ++j) {
            s.insert(arr[j]);
        }
        maxDistinct = max(maxDistinct, (int)s.size());
    }

    return maxDistinct;
}

int main() {
    vector<int> arr = {1, 1, 2, 1, 3, 2, 1, 1, 2};
    int k = 4;
    cout << maxDistinctElementsWithSet(arr, k) << endl;
    return 0;
}