#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26); // Frequency array for 26 letters

    for (auto &i : s)
        freq[i - 'a']++;

    int answer = 0;

    for (int left = 0, right = 0; right < n; right++) {
        freq[s[right] - 'a']--; // Consume the character at 'right'

        // Shrink the window if any character count becomes negative
        while (*min_element(freq.begin(), freq.end()) < 0) {
            freq[s[left] - 'a']++; // Restore the character at 'left'
            left++;
        }

        answer += (right - left + 1); // Count valid substrings
    }

    cout << answer << "\n";

    return 0;
}
