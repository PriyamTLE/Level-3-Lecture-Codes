#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
struct MedianContainer {
    int sumLeft, sumRight;
    multiset<int>left, right;
    
    MedianContainer() {
        sumLeft = 0, sumRight = 0;
    }
    
    void adjust() {
        if(left.size() && right.size() && *right.begin() < *left.rbegin()) {
            int leftLast = *left.rbegin(), rightFirst = *right.begin();
            sumLeft -= leftLast, sumRight -= rightFirst;
            sumLeft += rightFirst, sumRight += leftLast;
            left.extract(leftLast), right.extract(rightFirst);
            left.insert(rightFirst), right.insert(leftLast);
        }
 
        if(left.size() > right.size() + 1) {
            sumLeft -= *left.rbegin();
            sumRight += *left.rbegin();
            right.insert(*left.rbegin());
            left.extract(*left.rbegin());
        }
        
        else if(right.size() > left.size()) {
            sumLeft += *right.begin();
            sumRight -= *right.begin();
            left.insert(*right.begin());
            right.extract(*right.begin());
        }
    }
    
    void insert(int x) {
        right.insert(x);
        sumRight += x;
        adjust();
    }
    
    void remove(int x) {
        if(right.count(x)) {
            sumRight -= x;
            right.extract(x);
        }
        else {
            sumLeft -= x;
            left.extract(x);
        }
        adjust();
    }
    
    int cost() {
        return ((1ll * left.size() * (*left.rbegin())) - sumLeft) + (sumRight - (1ll * right.size() * (*left.rbegin())));
    }
};
 
 
signed main() {    
    int n, k; cin >> n >> k;
    
    vector<int>a(n);
    for(auto &i : a) cin >> i;
    
    MedianContainer container;
    
    for(int i = 0; i < k; i++) container.insert(a[i]);
    
    cout << container.cost() << " ";
    
    for(int i = k; i < n; i++) {
        container.remove(a[i - k]);
        container.insert(a[i]);
        cout << container.cost() << " ";
    }
    
    return 0;
}