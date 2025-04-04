#include <bits/stdc++.h>
using namespace std;

bool checkRBS(string &s)
{
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            cnt++;
        else
            cnt--;
        if (cnt < 0)
            return false;
    }
    return cnt == 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<int> pos;
        int op = s.size() / 2, cl = s.size() / 2;
        for (int i = 0; i < s.size(); ++i) // n
        {
            if (s[i] == '?')
                pos.push_back(i);
            if (s[i] == '(')
                --op;
            if (s[i] == ')')
                --cl;
        }

        for (int i = 0; i < pos.size(); ++i) // n
        {
            if (i < op)
                s[pos[i]] = '(';
            else
                s[pos[i]] = ')';
        }

        bool ok = true;
        if (op > 0 && cl > 0)
        {
            swap(s[pos[op - 1]], s[pos[op]]); // 1
            if (checkRBS(s)) // n
                ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}

// tc - O(n)
// sc - O(n)