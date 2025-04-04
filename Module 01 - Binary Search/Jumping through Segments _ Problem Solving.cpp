#include <bits/stdc++.h>

using namespace std;

bool checker(vector<array<long long, 2>> &segments, int n, long long val) {
    long long posMin = 0, posMax = 0;

    for(int i = 0; i < n; i++) {
        posMin = max(posMin - val, segments[i][0]);
        posMax = min(posMax + val, segments[i][1]);

        if(posMin > posMax) return false;
    }

    return true;
}

long long binSearch(vector<array<long long, 2>> &segments, int n) {
    long long low = 0, high = 1e9;

    long long ans = 0;

    while(low <= high) {
        long long mid = (low + high) / 2;

        if(checker(segments, n, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<array<long long, 2>> segments(n);

        for(int i = 0; i < n; i++) cin>>segments[i][0]>>segments[i][1];

        cout<<binSearch(segments, n)<<"\n";
    }
}
