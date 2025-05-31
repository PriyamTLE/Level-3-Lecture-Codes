#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n = 8, k = 3;
    vector<int> a = {10, 5, 2, 7, 2, 2, 1, 9};

    map<int, int> freq;
    int left = 0, right = 0, ans = 0;

    while (right < n) {
        // Include a[right] into the window
        freq[a[right]]++;

        // Shrink the window from the left if distinct elements exceed k
        while (left <= right && freq.size() > k) {
            freq[a[left]]--;
            if (freq[a[left]] == 0) {
                freq.erase(a[left]);
            }
            left++;
        }

        // Update the answer if current window is valid
        if (freq.size() <= k) {
            ans = max(ans, right - left + 1);
        }

        right++;
    }

    cout << ans << endl; // Output: 5
    return 0;
}
