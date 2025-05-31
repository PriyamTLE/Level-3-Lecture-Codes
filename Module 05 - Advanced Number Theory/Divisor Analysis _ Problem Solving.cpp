#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;

// Modular exponentiation
int mod_pow(int base, int exp, int mod = MOD) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// Modular inverse
int mod_inv(int a, int mod = MOD) {
    return mod_pow(a, mod - 2, mod);
}

int32_t main() {
    int n;
    cin >> n;

    vector<pair<int, int>> primes(n);
    int total_divisors = 1;

    for (int i = 0; i < n; ++i) {
        int p, a;
        cin >> p >> a;
        primes[i] = {p, a};
        total_divisors = total_divisors * (a + 1) % MOD;
    }

    // 1. Number of divisors
    int num_divisors = total_divisors;

    // 2. Sum of divisors
    int sum_divisors = 1;
    for (auto [p, a] : primes) {
        int numerator = mod_pow(p, a + 1) - 1 + MOD;
        int denominator = mod_inv(p - 1);
        sum_divisors = sum_divisors * (numerator % MOD) % MOD * denominator % MOD;
    }

    // 3. Product of divisors
    int product_divisors = 1;
    int exponent = 1;

    // We need to calculate the product of all divisors = (p1^e1 * p2^e2 * ... * pk^ek)^(t/2)
    // where t = total number of divisors = (e1+1)*(e2+1)*...*(ek+1)
    // We will build the product iteratively using exponentiation properties

    for (auto [p, a] : primes) {
        int power_sum = a * (a + 1) / 2;
        product_divisors = mod_pow(product_divisors, a + 1);
        int term = mod_pow(p, power_sum);
        product_divisors = product_divisors * mod_pow(term, exponent) % MOD;
        exponent = exponent * (a + 1) % (MOD - 1); // Use MOD-1 because of Fermat's theorem for exponents
    }

    cout << num_divisors << " " << sum_divisors << " " << product_divisors << endl;
    return 0;
}
