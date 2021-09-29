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
pair<ll,ll> a[maxn];
namespace ST{
ll a[maxn];   //原数组
struct node{
    ll l,r;
    ll s,lazy;
    void update(ll k){
        s+=(r-l+1)*k;
        lazy+=k;
    }
}tree[4*maxn];

void push_down(ll id){
    if(tree[id].lazy){
        tree[id*2].update(tree[id].lazy);
        tree[id*2+1].update(tree[id].lazy);
        tree[id].lazy=0;
    }
}
void push_up(ll id)
{
    tree[id].s=tree[id*2].s+tree[id*2+1].s;
}
void build(ll id,ll l,ll r){
    tree[id].l=l;
    tree[id].r=r;
    tree[id].lazy = 0;
    if(l==r){
        tree[id].s=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    push_up(id);
}
void update(ll id,ll l,ll r,ll k){
    ll L=tree[id].l,R=tree[id].r;
    if(R<l||L>r)
        return;
    if(l<=L&&R<=r){
        tree[id].update(k);
        return;
    }
    push_down(id);
    if(tree[id*2].r>=l)
        update(id*2,l,r,k);
    if(tree[id*2+1].l<=r)
        update(id*2+1,l,r,k);
    push_up(id);
}
ll query(ll id,ll l,ll r){
    ll L=tree[id].l,R=tree[id].r;
    ll res=0;
    if(R<l||L>r)
        return 0;
    if(l<=L&&R<=r)
        return tree[id].s;
    push_down(id);
    if(tree[id*2].r>=l)
        res+=query(id*2,l,r);
    if(tree[id*2+1].l<=r)
        res+=query(id*2+1,l,r);
    return res;
}
}
int main(){
    IOS;
    ll n;
    CAS {
        cin>>n;
        ST::build(1,1,n);
        Rep(i,1,n) cin>>a[i].first,a[i].second = i;
        sort(a+1,a+1+n);
        ll ans = 0;
        ll tmp = 0;
        if(a[1].second+1 <= n) ST::update(1,a[1].second+1,n,1);
        Rep(i,2,n){
            if(a[i].first != a[i-1].first) tmp = 0;
            else tmp++;
            ll now = a[i].second;
            ll last = ST::query(1,now,now);
            ll cnt = now-1;
            if(now+1 <= n) ST::update(1,now+1,n,1);
            if(last-tmp <= cnt-last) ans += last-tmp;
            else ans += cnt-last;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
