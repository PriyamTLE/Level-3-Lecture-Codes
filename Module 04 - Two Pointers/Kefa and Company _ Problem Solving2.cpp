#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
//   cin >> t;
  t =1;
  while(t--){   
    int n,d;
    cin>>n>>d;

    vector<pair<int,int>>friends(n);
    for(int i=0;i<n;i++){
        cin>>friends[i].first>>friends[i].second;
    }
    sort(friends.begin(),friends.end());

    long long friendship = friends[0].second;
    long long ans = friendship;

    int p1=0;
    int p2 =1;

    while(p2<n){
        while(friends[p2].first - friends[p1].first >=d){
            friendship -= friends[p1].second;
            p1++;
        }
        friendship += friends[p2].second;

        p2++;
        ans = max(ans,friendship);
    }
    cout<<ans<<endl;
  }


}
