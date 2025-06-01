#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    string s;
    cin >> s;

    int answer = 0;
    int curr = 0; // current cost
    int a = 0, b = 0; // count of 'a' and 'b'
    int left = 0;

    for (int right = 0; right < n; right++) {
        a += (s[right] == 'a');
        b += (s[right] == 'b');
        if (s[right] == 'b') curr += a;

        while (curr > c) {
            a -= (s[left] == 'a');
            b -= (s[left] == 'b');
            if (s[left] == 'a') curr -= b;
            left++;
        }

        answer = max(answer, right - left + 1);
    }

    cout << answer << "\n";
    return 0;
}
