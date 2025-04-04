class Solution {
private:
    static const int N = 2e5;
    int mod = 1e9 + 7;
    int fact[N + 5], inv[N + 5];
    
    int power(int a, int b) {
        int res = 1;
        while(b) {
            if(b & 1) res = (1LL * res * a) % mod;
            b >>= 1; 
            a = (1LL * a * a) % mod;
        }
        return res;
    }
    
    int inverse(int a) {
        int b = mod - 2;
        return power(a, b);
    }
    
    void generate() {
        fact[0] = 1;
        for(int i = 1; i <= N; i++) {
            fact[i] = (1LL * fact[i - 1] * i) % mod;
        }
        inv[N] = inverse(fact[N]);
        for(int i = N - 1; i >= 0; i--) {
            inv[i] = (1LL * inv[i + 1] * (i + 1)) % mod;
        }
    }
    
    int nCr(int n, int r) {
        int res = 1LL * fact[n] * inv[n - r] % mod * inv[r] % mod;
        // cout << n << " " << r << " " << res << " " << fact[n] << " " << inv[n - r] << " " << inv[r] << endl;
        return res;
    }
    
    
public:
    int countKSubsequencesWithMaxBeauty(string str, int k) {
        
        if(k > 26) {
            return 0;
        }
        
        int n = str.length();
        
        vector<int> freq(26, 0);
        
        for(int i = 0; i < n; i++) {
            int idx = str[i] - 'a';
            freq[idx]++;
        }
        
        sort(freq.begin(), freq.end(), greater<int>());
        
        int ans = 1;
        
        vector<pair<int,int>> a;
        
        for(int i = 0; i < 26; i++) {
            int j = i;
            while(j < 26 && freq[j] == freq[i]) j++;
            int cnt = j - i;
            a.push_back({freq[i], cnt});
            i = j - 1;
        }
        
        n = a.size();
        int req = k;
        
        // for(auto it : a) cout << it.first << "->" << it.second << ", "; cout << endl;
        
        generate();
        
        for(int i = 0; i < n && req > 0; i++) {
            int f = a[i].first, v = a[i].second;
            int mx = min(req, v);
            int choices = nCr(v, mx);
            ans = 1LL * ans * power(f, mx) % mod * nCr(v, mx) % mod;
            req -= mx;
            // cout << ans << " ";
        } 
        // cout << endl;
        
        return ans;
        
    }
};