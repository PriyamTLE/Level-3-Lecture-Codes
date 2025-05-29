#include<bits/stdc++.h>
using namespace std;

long long ans;
long long calc_ans(int a, int b ,int c){
    return 1ll*(a-b)*(a-b) + 1ll*(b-c)*(b-c) + 1ll*(c-a)*(c-a);
}

void solve(vector<int>&a , vector<int>&b ,vector<int>&c){
    int p1 =0, p2 =0, p3=0;
    
    while(p1<a.size()){
        while(p2<b.size()-1 && b[p2]<a[p1]) p2++;
        while(p3<c.size()-1){
            if(c[p3+1] > a[p1]) break;
            p3++;

        }
        ans = min(ans,calc_ans(a[p1],b[p2],c[p3]));
        p1++;
    }
}


int main(){
  int t;
  cin >> t;
  while(t--){   
    int nr,ng,nb;
    cin>>nr>>ng>>nb;

    vector<int>red(nr,0);
    vector<int>green(ng,0);
    vector<int>blue(nb,0);

    for(int i=0;i<nr;i++){
        cin>>red[i];
    }
    for(int i=0;i<ng;i++){
        cin>>green[i];
    }
    for(int i=0;i<nb;i++){
        cin>>blue[i];
    }
    sort(red.begin(),red.end());
    sort(green.begin(),green.end());
    sort(blue.begin(),blue.end());


    ans = calc_ans(red[0],blue[0],green[0]);
    solve(red,blue,green);
    solve(red,green,blue);
    solve(blue,red,green);
    solve(blue,green,red);
    solve(green,blue,red);
    solve(green,red,blue);
    cout<<ans<<endl;





    

  }


}
