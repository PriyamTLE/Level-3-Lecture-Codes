#include <bits/stdc++.h>

using namespace std;

bool checker(vector<int> &ropes, long double val, int k) {
   long long count = 0;

   for(auto it : ropes) {
      count += (it / val);
   }

   return count >= k;
}

long double binSearch(vector<int> &ropes, int k) {

   long double low = 0, high = 1e7;

   for(int it = 0; it < 50; it++) {
      long double mid = (low + high) / 2;

      if(checker(ropes, mid, k)) {
         low = mid;
      }
      else {
         high = mid;
      }
   }

   return low;
}

int main() {
   int n, k;
   
   cin>>n>>k;

   vector<int> ropes(n);

   for(int i = 0; i < n; i++) cin>>ropes[i];

   cout<<setprecision(7)<<fixed<<binSearch(ropes, k)<<"\n";
}