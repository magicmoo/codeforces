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
const ll INF = 2e18;
const ll maxn = 2e5+5;
char a[maxn],book[maxn];
ll dp[maxn];
namespace ST{
ll a[maxn];   //原数组
struct node{
    ll l,r;
    ll s,lazy;
    void update(ll k){
        s = k;
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
    tree[id].s=min(tree[id*2].s,tree[id*2+1].s);
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
    ll res1=INF,res2=INF;
    if(R<l||L>r)
        return 0;
    if(l<=L&&R<=r)
        return tree[id].s;
    push_down(id);
    if(tree[id*2].r>=l)
        res1=query(id*2,l,r);
    if(tree[id*2+1].l<=r)
        res2=query(id*2+1,l,r);
    return min(res1,res2);
}
}
int main(){
    IOS;
    ll n,k;
    cin>>n>>k;
    Rep(i,1,n) cin>>a[i];
    ll ans = 0,last = n;
    Rep(i,1,n) dp[i] = INF,ST::a[i] = INF;
    ST::build(1,1,n);
    ll Min = INF;
    Rep(i,1,n){
        dp[i] = min(dp[i],dp[i-1]+i);
        ST::update(1,i,i,dp[i]);
        if(a[i] == '1'){
            ST::query(1,i-k-1,n);
            dp[max(0LL,i-k-1)] = min(dp[max(0LL,i-k-1)],ST::query(1,i-k-1,n));
            dp[min(n,i+k)] = min(dp[min(n,i+k)],dp[max(0LL,i-k-1)]+i);
            ST::update(1,min(n,i+k),min(n,i+k),dp[min(n,i+k)]);
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}
