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