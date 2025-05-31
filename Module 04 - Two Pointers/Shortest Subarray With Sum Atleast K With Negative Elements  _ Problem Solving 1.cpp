#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deque;
        vector<long long> prefixSum(n + 1, 0);

        // Step 1: Compute prefix sum
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int result = n + 1;

        for (int i = 0; i <= n; ++i) {
            // Step 2: Check if current prefix sum can form a valid subarray
            while (!deque.empty() && prefixSum[i] - prefixSum[deque.front()] >= k) {
                result = min(result, i - deque.front());
                deque.pop_front();
            }

            // Step 3: Maintain deque in increasing order of prefixSum values
            while (!deque.empty() && prefixSum[i] <= prefixSum[deque.back()]) {
                deque.pop_back();
            }

            deque.push_back(i);
        }

        return result == n + 1 ? -1 : result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;

    cout << sol.shortestSubarray(nums, k) << endl; // Output: 2
    return 0;
}
