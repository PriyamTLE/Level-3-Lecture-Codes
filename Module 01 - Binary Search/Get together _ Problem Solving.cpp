#include <bits/stdc++.h>

using namespace std;

bool checker(vector<array<long long,2 >> &persons, long double time) {
    long double minX = -1e18, maxX = 1e18;

    for(auto &[initialPos, velocity] : persons) {
        minX = max(minX, initialPos - (velocity * time));
        maxX = min(maxX, initialPos + (velocity * time));

        if(minX > maxX) return false;
    }

    return true;
}

long double binSearch(vector<array<long long, 2>> &persons) {
    long double low = 0, high = 1e9;

    for(int it = 0; it < 60; it++) {
        long double mid = (low + high) / 2;

        if(checker(persons, mid)) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    return high;
}

int main() {
    int n;
    cin>>n;

    vector<array<long long, 2>> persons(n);

    for(int i = 0; i < n; i++) cin>>persons[i][0]>>persons[i][1];
    
    cout<<setprecision(7)<<fixed<<binSearch(persons)<<"\n";

    return 0;
}