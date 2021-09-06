#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
int n,m;
int a[maxn];   //原数组
struct node{
    int l,r;
    ll s,lazy;
    void update(ll k){
        s+=(r-l+1)*k%m;
        s %= m;
        lazy+=k%m;
    }
}tree[4*maxn];

void push_down(int id){
    if(tree[id].lazy){
        tree[id*2].update(tree[id].lazy);
        tree[id*2+1].update(tree[id].lazy);
        tree[id].lazy=0;
    }
}
void push_up(int id)
{
    tree[id].s=(tree[id*2].s+tree[id*2+1].s)%m;
}
void build(int id,int l,int r){
    tree[id].l=l;
    tree[id].r=r;
    tree[id].lazy = 0;
    if(l==r){
        tree[id].s=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    push_up(id);
}
void update(int id,int l,int r,int k){
    int L=tree[id].l,R=tree[id].r;
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
ll query(int id,int l,int r){
    int L=tree[id].l,R=tree[id].r;
    ll res=0;
    if(R<l||L>r)
        return 0;
    if(l<=L&&R<=r)
        return tree[id].s;
    push_down(id);
    if(tree[id*2].r>=l)
        res+=query(id*2,l,r)%m;
    if(tree[id*2+1].l<=r)
        res+=query(id*2+1,l,r)%m;
    return res%m;
}
int main(){
    IOS;
    cin>>n>>m;
    Rep(i,1,n) a[i] = 1;
    build(1,1,n);
    Rep(i,1,n){
        int last,nex;
        int num = query(1,i,i);
        Rep(j,2,n){
            if(i*j > n) break;
            last = i*j;
            nex = min(n,(i+1)*j-1);
            if(nex >= last) update(1,last,nex,num%m);
        }
        if(i != 1) update(1,i+1,n,num);
    }
    cout<<query(1,n,n)%m<<"\n";
    return 0;
}
