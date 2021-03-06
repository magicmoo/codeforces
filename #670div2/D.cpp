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
const ll maxn = 1e5+5;
ll a[maxn],b[maxn],c[maxn],n;
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
bool check(ll num){
    b[n] = c[1] = num;
    b[1] = a[1]-num; c[n] = a[n]-num;
    Rep(i,2,n-1){
        b[i] = b[i-1];
        c[i] = a[i]-b[i];
        if(c[i] > c[i-1]){
            ll dis = c[i]-c[i-1];
            c[i] -= dis;
            b[i] += dis;
        }
    }
    if(b[n]<b[n-1] || c[n]>c[n-1]) return 0;
    return 1;
}
int main(){
    IOS;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    ll q,l,r,w,d;
    c[1] = a[1];
    Rep(i,2,n){
        b[i] = b[i-1];
        c[i] = a[i]-b[i];
        if(c[i] > c[i-1]){
            ll dis = c[i]-c[i-1];
            c[i] -= dis;
            b[i] += dis;
        }
    }
    ll ans = (b[n]+c[1])/2;
    if(ans>0 && (b[n]+c[1])%2 != 0) ans++;
    cout<<ans<<"\n";
    cin>>q;
    ll dis = b[n];
    Rep(i,1,n) ST::a[i] = a[i];
    ST::build(1,1,n);
    while(q--){
        cin>>l>>r>>w;   
        if(w>=0){
            if(r+1<=n) dis -= min(w,max(0LL,ST::query(1,r+1,r+1)-ST::query(1,r,r)));
        }else{
            if(l-1>0) dis -= min(-w,max(0LL,ST::query(1,l,l)-ST::query(1,l-1,l-1)));
        }
        ST::update(1,l,r,w);
        if(w>=0){
            if(l-1>0) dis += min(w,max(ST::query(1,l,l)-ST::query(1,l-1,l-1),0LL));
        }else{
            if(r+1<=n) dis += min(-w,max(ST::query(1,r+1,r+1)-ST::query(1,r,r),0LL));
        }
        ll ans = (dis+ST::query(1,1,1))/2;
        if(ans>0 && (dis+ST::query(1,1,1))%2 != 0) ans++;
        cout<<ans<<"\n";
    }
    return 0;
}
