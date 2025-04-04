#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a;
        int empty = 0;
        for (int i = 0; i < n; i++) // n
        {
            if (s[i] == '.')
                empty++;
            else
                a.push_back(empty);
        }
        int mid = (a.size() - 1) / 2;
        long long ans = 0;
        for (auto x : a) // n
        {
            ans += abs(x - a[mid]);
        }
        cout << ans << endl;
    }
    return 0;
}

// tc = O(n)
// sc = O(1)