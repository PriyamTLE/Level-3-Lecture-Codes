/*This is a boiler plate template created by Hardik Aswal*/

/* Including all the libraries*/
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
#include<climits>
#include<deque>
#include<unordered_set>
#include<map>


/*<----------------------------------end of libraries-------------------------------------->*/

using namespace std;
/*Defining helper items*/

#define pb push_back
#define ll long long
#define mod 1000000007
//#define mod2 998244353
#define vi vector<int>
#define mii map<int, int> 
#define mci map<char, int>
#define pii pair<int, int>
#define f(i,s,e)   for(int i=s;i<e;i++)

#define rf(i,s,e)     for(int i=s;i>=e;i--)
#define desc(vec) sort(vec.begin(), vec.end(), greater<int>());  
#define asc(vec)  sort(vec.begin(),vec.end());
#define maxo(x) *max_element((x).begin(), (x).end())
#define mino(x) *min_element((x).begin(), (x).end())
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type, vector<type>, greater<type>>
#define sum(x) accumulate((x).begin(), (x).end(), 0LL)
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define print(x) {for(auto v: x) {cout << v<< ' ';} cout << endl;}
#define printmap(x) {for(auto v: x) {cout << v.first << ':' << v.second << ' ';} cout << endl;}
#define printv(x) { for (auto v: x){ print(v) }}
#define print2d(vec,n,m) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++)cout<<vec[i][j]<<" ";cout<<"\n";}









/*<---------------------------end of helper items-------------------------------------->*/
/*Defining Helper Functions*/

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
int power(int a, int b) {
    int result = 1;
    while (b > 0) {
        
        if (b % 2 == 1) {
            result *= a;
        }
        a *= a;
        b /= 2;
    }
    return result;
}













/*<-----------------------------------end of helper functions-------------------------------->*/





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