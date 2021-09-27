#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS ll CASE; \
            cin>>CASE; \
            Rep(__,1,CASE)
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const ll INF = 0x3f3f3f3f;
const ll maxn = 3e5+5;
const ll maxv = 1e6+5;
ll x[maxv],y[maxv];
vector<ll> xx,yy;
ll ans;
struct Node{
    ll index;
    ll x,y;
}a[maxn];
map<ll,ll> mp;
vector<pair<ll,ll>> v1,v2;
void solve2(vector<pair<ll,ll>>& v,vector<ll>& arr){
    ll cnt = 1,now = 0;
    mp[v[0].first]++;
    while(now<arr.size() && arr[now]<v[0].second) now++;
    rep(i,1,v.size()){
        if(now<arr.size() && arr[now]<v[i].second){
            ans += cnt*(cnt-1)/2;
            while(now<arr.size() && arr[now]<v[i].second) now++;
            for(auto val : mp){
                ans -= val.second*(val.second-1)/2;
            }
            cnt = 1;
            mp.clear();
            mp[v[i].first]++;
        }else{
            cnt++;
            mp[v[i].first]++;
        }
    }
    ans += cnt*(cnt-1)/2;
    for(auto val : mp){
        ans -= val.second*(val.second-1)/2;
    }
    mp.clear();
}
void solve3(vector<pair<ll,ll>>& v,vector<ll>& arr){
    ll cnt = 1,now = 0;
    mp[v[0].second]++;
    while(now<arr.size() && arr[now]<v[0].first) now++;
    rep(i,1,v.size()){
        if(now<arr.size() && arr[now]<v[i].first){
            ans += cnt*(cnt-1)/2;
            while(now<arr.size() && arr[now]<v[i].first) now++;
            for(auto val : mp){
                ans -= val.second*(val.second-1)/2;
            }
            cnt = 1;
            mp.clear();
            mp[v[i].second]++;
        }else{
            cnt++;
            mp[v[i].second]++;
        }
    }
    ans += cnt*(cnt-1)/2;
    for(auto val : mp){
        ans -= val.second*(val.second-1)/2;
    }
    mp.clear();
}
bool cmp1(pair<ll,ll> p1,pair<ll,ll> p2){
    return p1.first < p2.first;
}
bool cmp2(pair<ll,ll> p1,pair<ll,ll> p2){
    return p1.second<p2.second;
}
int main(){
    IOS;
    ll n,m,k,num;
    CAS {
        v1.clear();
        v2.clear();
        xx.clear();
        yy.clear();
        cin>>n>>m>>k;
        Rep(i,1,n){
            cin>>num;
            xx.push_back(num);
        }
        Rep(i,1,m){
            cin>>num;
            yy.push_back(num);
        }
        sort(xx.begin(),xx.end());
        sort(yy.begin(),yy.end());
        rep(i,0,n) x[xx[i]] = 1;
        rep(i,0,m) y[yy[i]] = 1;
        Rep(i,1,k) cin>>a[i].x>>a[i].y,a[i].index = i;
        Rep(i,1,k){
            if(x[a[i].x]==1 && y[a[i].y]==1) continue;
            if(x[a[i].x]==1) v1.push_back({a[i].x,a[i].y});
            else v2.push_back({a[i].x,a[i].y});
        }
        sort(v1.begin(),v1.end(),cmp2);
        sort(v2.begin(),v2.end(),cmp1);
        ans = 0;
        if(v1.size() > 0)solve2(v1,yy);
        if(v2.size() > 0) solve3(v2,xx);
        cout<<ans<<"\n";
        rep(i,0,n) x[xx[i]] = 0;
        rep(i,0,m) y[yy[i]] = 0;
    }
    return 0;
}

//                    _ooOoo_
//                   o8888888o
//                   88" . "88
//                   (| -_- |)
//                   O\  =  /O
//                ____/`---'\____
//              .'  \\|     |//  `.
//             /  \\|||  :  |||//  \
//            /  _||||| -:- |||||-  \
//            |   | \\\  -  /// |   |
//            | \_|  ''\---/''  |   |
//            \  .-\__  `-`  ___/-. /
//          ___`. .'  /--.--\  `. . __
//       ."" '<  `.___\_<|>_/___.'  >'"".
//      | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//      \  \ `-.   \_ __\ /__ _/   .-` /  /
// ======`-.____`-.___\_____/___.-`____.-'======
//                    `=---='
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//             佛祖保佑      永无bug