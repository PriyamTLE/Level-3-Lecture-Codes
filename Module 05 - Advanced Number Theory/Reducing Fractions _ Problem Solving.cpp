#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e7 + 1;
ll spf[N]; 

void sieve() {
    for (ll i = 1; i < N; i++)
        spf[i] = i;

    for (ll i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j < N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

int main() {
    sieve();

    ll n, m;
    cin >> n >> m;

    map<ll, ll> p1, p2, p3;
    vector<ll> a(n), b(m);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        ll x = a[i];
        while (x > 1) {
            ll p = spf[x], cnt = 0;
            while (x % p == 0) {
                cnt++;
                x /= p;
            }
            p1[p] += cnt;
        }
    }

    for (ll i = 0; i < m; i++) {
        cin >> b[i];
        ll x = b[i];
        while (x > 1) {
            ll p = spf[x], cnt = 0;
            while (x % p == 0) {
                cnt++;
                x /= p;
            }
            p2[p] += cnt;
        }
    }

    for (auto &i : p1) {
        p3[i.first] = min(p1[i.first], p2[i.first]);
    }

    p1 = p2 = p3;

    for (ll i = 0; i < n; i++) {
        ll x = a[i];
        while (x > 1) {
            ll p = spf[x], cnt = 0;
            while (x % p == 0) {
                cnt++;
                x /= p;
            }
            cnt = min(cnt, p1[p]);
            p1[p] -= cnt;
            while (cnt--) {
                a[i] /= p;
            }
        }
    }

    for (ll i = 0; i < m; i++) {
        ll x = b[i];
        while (x > 1) {
            ll p = spf[x], cnt = 0;
            while (x % p == 0) {
                cnt++;
                x /= p;
            }
            cnt = min(cnt, p2[p]);
            p2[p] -= cnt;
            while (cnt--) {
                b[i] /= p;
            }
        }
    }

    cout << n << " " << m << endl;
    for (auto &x : a) {
        cout << x << " ";
    }
    cout << endl;

    for (auto &x : b) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
