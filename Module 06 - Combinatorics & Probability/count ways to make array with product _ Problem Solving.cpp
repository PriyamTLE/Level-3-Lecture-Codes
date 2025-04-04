const int MOD = 1e9 + 7;
template<const int mod>
struct mint {
    int val;
    constexpr mint(long long x = 0) : val((x % mod + mod) % mod) {}
    explicit operator int() const { return val; }
    mint& operator+=(const mint &b) { val += b.val; val -= mod * (val >= mod); return *this; }
    mint& operator-=(const mint &b) { val -= b.val; val += mod * (val < 0); return *this; }
    mint& operator*=(const mint &b) { val = 1ll * val * b.val % mod; return *this; }
    mint& operator/=(const mint &b) { return *this *= b.inv(); }
    mint inv() const { int x = 1, y = 0, t; for(int a=val, b=mod; b; swap(a, b), swap(x, y)) t = a/b, a -= t * b, x -= t * y; return mint(x); }
    mint power(int b) const { mint a = *this, res(1); for(; b; a *= a, b /= 2)  if(b & 1) res *= a; return res; }
    mint operator-() const { return val == 0 ? 0 : mod - val; }
    mint& operator++() { val = val == mod - 1 ? 0 : val + 1; return *this; }
    mint& operator--() { val = val == 0 ? mod - 1 : val - 1; return *this; }
    mint operator++(int32_t) { mint before = *this; ++*this; return before; }
    mint operator--(int32_t) { mint before = *this; --*this; return before; }
    friend mint operator+(const mint &a, const mint &b) {return mint(a) += b;}
    friend mint operator-(const mint &a, const mint &b) {return mint(a) -= b;}
    friend mint operator*(const mint &a, const mint &b) {return mint(a) *= b;}
    friend mint operator/(const mint &a, const mint &b) {return mint(a) /= b;}
    friend bool operator==(const mint &a, const mint &b) {return a.val == b.val;}
    friend bool operator!=(const mint &a, const mint &b) {return a.val != b.val;}
    friend bool operator<(const mint &a, const mint &b) {return a.val < b.val;}
    friend istream& operator>>(istream &in, mint &a) {return in >> a.val;}
    friend ostream& operator<<(ostream &os, const mint &a) {return os << a.val;}
};
using Mint = mint<MOD>;

namespace comb {
    int n(0);
    vector<Mint> _fac{1}, _invfac{1}, _inv{0};
    void init(int m) {
        m = min (m, MOD - 1);
        if (m <= n) return;
        _fac.resize(m + 1); _invfac.resize(m + 1); _inv.resize(m + 1);
        for (int i = n + 1; i <= m; i++) _fac[i] = _fac[i - 1] * i;
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) _invfac[i - 1] = _invfac[i] * i, _inv[i] = _invfac[i] * _fac[i - 1];
        n = m;
    }
    Mint fac(int m) { if (m > n) init(2 * m); return _fac[m]; }
    Mint invfac(int m) { if (m > n) init(2 * m); return _invfac[m]; }
    Mint inv(int m) { if (m > n) init(2 * m); return _inv[m]; }
    Mint ncr(int n, int r) { if (n < r || r < 0) return 0; return fac(n) * invfac(r) * invfac(n - r); }
}
using comb::fac, comb::invfac, comb::inv, comb::ncr;

class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto it : queries) {
            int n = it[0], k = it[1];
            Mint res = 1;
            for (int i = 2; i * i <= k; i++) {
                int ct = 0;
                while (k % i == 0) {
                    k /= i;
                    ct++;
                }
                res *= ncr(n + ct - 1, n - 1);
            }
            if (k > 1) res *= ncr(n, 1);
            ans.push_back(res.val);
        }
        return ans;
    }
};