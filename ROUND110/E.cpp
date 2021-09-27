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
const ll maxn = 3e5+5;
ll a[maxn],c[maxn];
ll dp[21][maxn];
void NEXT(ll now,ll p){
    dp[0][now] = p;
    Rep(i,1,20){
        ll nxt = dp[i-1][now];
        dp[i][now] = dp[i-1][nxt];
    }
}
ll find(ll now){
    ll nxt = now,ans = 0,cnt = 20;
    while(cnt>=0){
        ll index = dp[cnt][nxt];
        if(a[index]) nxt = index;
        cnt--;
    }
    return nxt;
}
int main(){ 
    ll q,opr,p,v,w;
    cin>>q>>a[0]>>c[0];
    Rep(i,1,q){
        cin>>opr;
        if(opr==1){
            cin>>p>>a[i]>>c[i];
            dp[0][i] = p;
            NEXT(i,p);
        }else{
            cin>>v>>w;
            ll ans = 0,cnt = 0;
            while(a[v] && w){
                ll nxt = find(v);
                if(a[nxt]>=w){
                    a[nxt] -= w;
                    cnt += w;
                    ans += w*c[nxt];
                    w = 0;
                }else{
                    w -= a[nxt];
                    cnt += a[nxt];
                    ans += c[nxt]*a[nxt];
                    a[nxt] = 0;
                }
            }
            cout<<cnt<<" "<<ans<<"\n";
        }
        fflush(stdout);
    }
    return 0;
}
