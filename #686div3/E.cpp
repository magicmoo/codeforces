#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 2e5+5;
vector<ll> vec[maxn];
ll book[maxn],dp[maxn],mp[maxn];
ll ans;
ll dfs(ll now,ll last){
    if(book[now]){
        mp[now] = 1;
        return now;
    }
    book[now] = 1;
    rep(i,0,vec[now].size()){
        ll nxt = vec[now][i];
        if(nxt == last) continue;
        ll num = dfs(nxt,now);
        if(num){
            mp[now] = 1;
            if(now != num) return num;
            else return 0;
        }
    }
    return 0;
}
void dfs2(ll now,ll last,ll& cnt){
    if(mp[now] && last!=-1) return;
    cnt++;
    rep(i,0,vec[now].size()){
        ll nxt = vec[now][i];
        if(nxt==last) continue;
        dfs2(nxt,now,cnt);
    }
}
int main(){
    IOS;
    ll n,l,r,u,v;
    CAS {
        cin>>n;
        u = v = 0;
        ans = 0;
        Rep(i,1,n) vec[i].clear();
        Rep(i,1,n) mp[i] = book[i] = 0;
        Rep(i,1,n){
            cin>>l>>r;
            vec[l].push_back(r);
            vec[r].push_back(l);
        }
        dfs(1,-1);
        ans = n*(n-1);
        Rep(i,1,n){
            if(!mp[i]) continue;
            ll cnt = 0;
            dfs2(i,-1,cnt);
            ans -= cnt*(cnt-1)/2;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
