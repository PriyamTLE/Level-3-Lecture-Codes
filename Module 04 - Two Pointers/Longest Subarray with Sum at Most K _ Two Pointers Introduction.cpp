#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 6, k = 15;
    vector<int> a = {10, 5, 2, 7, 1, 9};

    int ans = 0, sum = 0;
    int left = 0, right = 0;

    while (right < n) {
        sum += a[right];

        // Shrink the window from the left if sum exceeds k
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // Update answer if the current window is valid
        if (sum <= k) {
            ans = max(ans, right - left + 1);
        }

        right++;
    }

    cout << ans << endl; // Output: 4
    return 0;
}
