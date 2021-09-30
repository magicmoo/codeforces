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
ll cal(ll x){
    return x*(x+1)/2;
}
ll a[maxn];   //原数组
struct node{
    ll l,r;
    ll numl,numr;
    ll suml,sumr;
    ll s;
    void update(ll k){
        s+=(r-l+1)*k;
    }
}tree[4*maxn];
 
void push_up(ll id)
{
    tree[id].numl = tree[id*2].numl;
    tree[id].suml = tree[id*2].suml;
    tree[id].numr = tree[id*2+1].numr;
    tree[id].sumr = tree[id*2+1].sumr;
    if(tree[id*2].numr <= tree[id*2+1].numl){
        tree[id].s = tree[id*2].s+tree[id*2+1].s+cal(tree[id*2].sumr+tree[id*2+1].suml)-cal(tree[id*2].sumr)-cal(tree[id*2+1].suml);
        if(tree[id*2].sumr == tree[id*2].r-tree[id*2].l+1) tree[id].suml = tree[id*2].suml+tree[id*2+1].suml;
        if(tree[id*2+1].suml == tree[id*2+1].r-tree[id*2+1].l+1) tree[id].sumr = tree[id*2].sumr+tree[id*2+1].sumr;
    }else tree[id].s = tree[id*2].s+tree[id*2+1].s;
}
void build(ll id,ll l,ll r){
    tree[id].l=l;
    tree[id].r=r;
    if(l==r){
        tree[id].s=1;
        tree[id].numl = tree[id].numr = a[l];
        tree[id].suml = tree[id].sumr = 1;
        return;
    }
    ll mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    push_up(id);
}
void update(ll id,ll index,ll k){
    ll L = tree[id].l,R = tree[id].r;
    if(L == R){
        tree[id].numl = tree[id].numr = k;
        return;
    }
    ll mid = (L+R)/2;
    if(mid >= index) update(id*2,index,k);
    else update(id*2+1,index,k);
    push_up(id);
}
ll query(ll id,ll l,ll r){
    ll L=tree[id].l,R=tree[id].r;
    ll res=0;
    if(R<l||L>r)
        return 0;
    if(l<=L&&R<=r)
        return tree[id].s;
    ll m = (L+R)/2;
    if(tree[id*2].r>=l && tree[id*2+1].l<=r){
        ll tmp1 = query(id*2,l,r),tmp2 = query(id*2+1,l,r);
        if(tree[id*2].numr <= tree[id*2+1].numl){
            return tmp1+tmp2+cal(min(m-l+1,tree[id*2].sumr)+min(r-m,tree[id*2+1].suml))-cal(min(m-l+1,tree[id*2].sumr))-cal(min(r-m,tree[id*2+1].suml));
        }else return tmp1+tmp2;
    }else if(tree[id*2].r>=l) res+=query(id*2,l,r);
    else if(tree[id*2+1].l<=r) res+=query(id*2+1,l,r);
    return res;
}
int main(){
    IOS;
    ll n,q,opr,l,r;
    cin>>n>>q;
    Rep(i,1,n) cin>>a[i];
    build(1,1,n);
    while(q--){
        cin>>opr>>l>>r;
        if(opr == 1){
            update(1,l,r);
        }else{
            cout<<query(1,l,r)<<"\n";
        }
    }
    return 0;
}