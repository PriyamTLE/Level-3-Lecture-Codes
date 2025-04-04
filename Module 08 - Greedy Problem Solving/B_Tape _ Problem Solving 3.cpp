#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> segments(n);
    for (int i = 0; i < n; i++) // n
        cin >> segments[i];

    long long minimum_length_of_tape = n;

    vector<long long> gaps;
    for (int i = 1; i < n; i++) // n
        gaps.push_back(segments[i] - segments[i - 1] - 1);
    
    sort(gaps.begin(), gaps.end()); // nlogn

    for (int i = 0; i < n - k; i++)
        minimum_length_of_tape += gaps[i];

    cout << minimum_length_of_tape << endl;
    return 0;
}

// tc - O(nlogn)
// sc - O(n)