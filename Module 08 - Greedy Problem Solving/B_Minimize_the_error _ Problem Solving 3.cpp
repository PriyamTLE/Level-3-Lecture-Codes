#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) // n
        cin >> a[i];
    for (int i = 0; i < n; i++) // n
        cin >> b[i];

    priority_queue<long long> diff;

    for (int i = 0; i < n; i++) // n
        diff.push(abs(a[i] - b[i])); // log2n

    long long k = k1 + k2;

    while (k--) // k
    {
        long long temp = diff.top();
        diff.pop();
        diff.push(abs(temp - 1)); // log2n
    }

    long long ans = 0;
    while (!diff.empty())
    {
        long long temp = diff.top();
        diff.pop();
        ans += temp * temp;
    }

    cout << ans << endl;
    return 0;
}

// tc = O(nlogn + klogn) = O(10^3log10^3) = O(10^4)
// sc = O(n)