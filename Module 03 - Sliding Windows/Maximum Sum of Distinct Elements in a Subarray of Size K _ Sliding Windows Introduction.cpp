#include <bits/stdc++.h>
using namespace std;


int maxSumDistinctSubarrayOfSizeK(const vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return 0;

    map<int, int> freq; 
    int sum = 0, maxSum = 0;

    for (int i = 0; i < n; ++i) {
        // include current element
        sum += arr[i];
        freq[arr[i]]++;

        // remove element going out of the window
        if (i >= k) {
            freq[arr[i - k]]--;
            sum -= arr[i - k];
            if (freq[arr[i - k]] == 0)
                freq.erase(arr[i - k]);
        }

        // check window size and uniqueness
        if (i >= k - 1 && freq.size() == k) {
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

int main() {
    vector<int> arr = {1, 1, 2, 1, 3, 2, 1, 1, 2};
    int k = 3;

    cout << maxSumDistinctSubarrayOfSizeK(arr, k) << endl;

    return 0;
}
