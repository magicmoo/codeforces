#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
#define Rep(i,x,y) for(auto i=(x);i<=(y);i++)
#define rep(i,x,y) for(auto i=(x);i<(y);i++)
#define Dep(i,x,y) for(auto i=(x);i>=(y);i--)
#define dep(i,x,y) for(auto i=(x);i>(y);i--)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxv = 3e5+5;
const int maxn = 1e6+5;
struct Node1{
    int l,r,v;
}nodes[maxv];
bool cmp(Node1 n1,Node1 n2){
    return n1.v<n2.v;
}
int tree[maxn << 2], lz[maxn << 2];
int a[maxn];
inline int max(int a, int b) { return a < b ? a : b; }

void build(int i, int l, int r) {  //建树操作，初始化时应将i置为1
    if (l == r) {
        tree[i] = a[l];
        return;
    }
    int mid = (l + r) >> 1, k = i << 1;
    build(k, l, mid);
    build(k | 1, mid + 1, r);
    tree[i] = max(tree[k], tree[k | 1]);
}

void update(int i, int l, int r, int x, int y) {  //单点修改,将x处值改为y,i l r分别初始化为1,1,n
    if (l == r) {
        tree[i] = y;
        return;
    }
    int mid = (l + r) >> 1, k = i << 1;
    if (x <= mid)
        update(k, l, mid, x, y);
    else
        update(k | 1, mid + 1, r, x, y);
    tree[i] = max(tree[k], tree[k | 1]);
}

void pushdown(int i) {
    if (lz[i]) {
        int k = i << 1;
        tree[k] += lz[i], tree[k | 1] += lz[i];
        lz[k] += lz[i], lz[k | 1] += lz[i], lz[i] = 0;
    }
}

void add(int i, int l, int r, int x, int y, int val) { //区间加,[x,y]内数全部加val,i l r分别初始化为1,1,n
    if (l == x && r == y) {
        tree[i] += val, lz[i] += val;
        return;
    }
    pushdown(i);
    int mid = (l + r) >> 1, k = i << 1;
    if (x > mid) add(k | 1, mid + 1, r, x, y, val);
    else if (y <= mid) add(k, l, mid, x, y, val);
    else add(k, l, mid, x, mid, val), add(k | 1, mid + 1, r, mid + 1, y, val);
    tree[i] = max(tree[k], tree[k | 1]);
}

int query(int i, int l, int r, int x, int y) {  //区间查找[x,y]最值,i l r分别初始化为1,1,n
    if (x <= l && y >= r) return tree[i];
    pushdown(i);
    int mid = (l + r) >> 1, k = i << 1;
    if (y <= mid)
        return query(k, l, mid, x, y);
    else if (x > mid)
        return query(k | 1, mid + 1, r, x, y);
    return max(query(k, l, mid, x, y), query(k | 1, mid + 1, r, x, y));
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    Rep(i,1,n) cin>>nodes[i].l>>nodes[i].r>>nodes[i].v;
    sort(nodes+1,nodes+1+n,cmp);
    int l = 1,r = n;
    build(1,1,m);
    int ans = INF;
    Rep(i,1,n){
        if(nodes[i].r-1>0 && nodes[i].l<=nodes[i].r-1) add(1,1,m,nodes[i].l,nodes[i].r-1,1);
        int tmp = 0;
        bool flag = 0;
        while(l<i && (tmp = query(1,1,m,1,m-1)) > 0){
            flag = 1;
            if(nodes[l].r-1>0 && nodes[l].l<=nodes[l].r-1) add(1,1,m,nodes[l].l,nodes[l].r-1,-1);
            l++;
        }
        if(flag && query(1,1,m,1,m-1)<=0 ){
            l--;
            if(nodes[l].r-1>0 && nodes[l].l<=nodes[l].r-1) add(1,1,m,nodes[l].l,nodes[l].r-1,1);
        }
        if(query(1,1,m,1,m-1) > 0) ans = min(ans,nodes[i].v-nodes[l].v);
    }
    cout<<ans<<"\n";
    return 0;
}
