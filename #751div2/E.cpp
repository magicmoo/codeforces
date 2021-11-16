#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define PII pair<ll,ll>
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e6+5;
ll a[maxn],b[maxn],p[maxn],arr[maxn],tmp[maxn];
void solve(ll l,ll r,ll l1,ll r1){
    ll mid = (l1+r1)/2;
    ll cnt = 0;
    Rep(i,l,r){
        if(a[i]<b[mid]) cnt++;
    }
    ll Min = cnt,Mini = l;
    Rep(i,l,r){
        if(a[i]<b[mid]) cnt--;
        else if(a[i]>b[mid]) cnt++;
        if(Min > cnt){
            Min = cnt;
            Mini = i+1;
        }
    }
    arr[mid] = Mini;
    if(mid-1>=l1) solve(l,Mini-1,l1,mid-1);
    if(r1>=mid+1) solve(Mini,r,mid+1,r1);
}
ll cnt;
void calc(ll l,ll r){
    if(l==r) return;
    ll mid = (l+r)/2;
    calc(l,mid);
    calc(mid+1,r);
    ll L=l,R=mid+1,now=0;
    while(L<=mid && R<=r){
        if(p[L]<=p[R]){
            tmp[++now] = p[L];
            L++;
        }else{
            cnt += mid-L+1;
            tmp[++now] = p[R];
            R++;
        }
    }
    while(L<=mid) tmp[++now] = p[L++];
    while(R<=r) tmp[++now] = p[R++];
    Rep(i,1,now) p[i+l-1] = tmp[i];
}
int main(){
    IOS;
    ll n,m;
    CAS {
        cnt = 0;
        cin>>n>>m;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,m) cin>>b[i];
        sort(b+1,b+1+m);
        solve(1,n,1,m);
        ll now = 0,r = 1;
        Rep(i,1,n){
            while(r<=m && arr[r]==i){
                p[++now] = b[r++];
            }
            p[++now] = a[i];
        }
        while(r<=m) p[++now] = b[r++];
        calc(1,now);
        cout<<cnt<<"\n";
    }
    return 0;
}
