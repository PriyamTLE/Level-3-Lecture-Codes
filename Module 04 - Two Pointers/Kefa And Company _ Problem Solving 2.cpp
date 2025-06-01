#include <bits/stdc++.h>
using namespace std;

int main(){
    int t = 1;
    while(t--){
        int n, d; cin>>n>>d;
        vector<pair<int,int>> friends(n);

        for(int i = 0; i<n; i++){
            cin>>friends[i].first>>friends[i].second;
        }

        sort(friends.begin(), friends.end()); //O(nlogn)

        long long curr = friends[0].second;
        long long ans = curr;
        int i = 0, j = 1;

        while(j<n){
            // 1 -> n
            while(friends[j].first - friends[i].first >= d){
                // 0 -> n
                curr -= friends[i].second;
                i++;
            }
            curr += friends[j].second;
            j++;
            ans = max(ans, curr);
        }
        cout<<ans<<endl;
    }
// TC = O(nlogn)
// SC = O(n)
    return 0;
}
