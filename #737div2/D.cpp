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
const int maxn = 6e5+5;
vector<pair<int,int>> v[maxn];
int li[maxn],pre[maxn];
int a[maxn];
pair<int,int> tree[maxn << 2],lz[maxn << 2];
inline int max(int a, int b) { return a > b ? a : b; }

void build(int i, int l, int r) {  //建树操作，初始化时应将i置为1
    if (l == r) {
        tree[i].first = a[l];
        return;
    }
    int mid = (l + r) >> 1, k = i << 1;
    build(k, l, mid);
    build(k | 1, mid + 1, r);
    tree[i] = max(tree[k], tree[k | 1]);
}

void pushdown(int i) {
    if (lz[i].first) {
        int k = i << 1;
        tree[k] = lz[i], tree[k | 1] = lz[i];
        lz[k] = lz[i], lz[k | 1] = lz[i], lz[i] = {0,0};
    }
}

void add(int i, int l, int r, int x, int y, pair<int,int> val) { //区间加,[x,y]内数全部加val,i l r分别初始化为1,1,n
    if (l == x && r == y) {
        tree[i] = val, lz[i] = val;
        return;
    }
    pushdown(i);
    int mid = (l + r) >> 1, k = i << 1;
    if (x > mid) add(k | 1, mid + 1, r, x, y, val);
    else if (y <= mid) add(k, l, mid, x, y, val);
    else add(k, l, mid, x, mid, val), add(k | 1, mid + 1, r, mid + 1, y, val);
    tree[i] = max(tree[k], tree[k | 1]);
}

pair<int,int> query(int i, int l, int r, int x, int y) {  //区间查找[x,y]最值,i l r分别初始化为1,1,n
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
    int n,m,id,l,r;
    cin>>n>>m;
    Rep(i,1,m){
        cin>>id>>l>>r;
        v[id].push_back({l,r});
        li[++li[0]] = l; li[++li[0]] = r;
    }
    sort(li+1,li+1+li[0]);
    int len = unique(li+1,li+1+li[0])-li-1;
    Rep(i,1,n){
        rep(j,0,v[i].size()){
            v[i][j].first = lower_bound(li+1,li+1+len,v[i][j].first)-li;
            v[i][j].second = lower_bound(li+1,li+1+len,v[i][j].second)-li;
        }
    }
    build(1,1,len);
    int last = 0,cnt = 0;
    Rep(i,1,n){
        pair<int,int> Max = {0,0};
        rep(j,0,v[i].size()){
            Max = max(Max,query(1,1,len,v[i][j].first,v[i][j].second));
        }
        pre[i] = Max.second;
        Max.first++;
        Max.second = i;
        if(Max.first > cnt){
            cnt = Max.first; last = Max.second;
        }
        rep(j,0,v[i].size()){
            add(1,1,len,v[i][j].first,v[i][j].second,Max);
        }
    }
    vector<int> ans;
    while(last != 0){
        ans.push_back(last);
        last = pre[last];
    }
    int now = ans.size()-1;
    cout<<(n-ans.size())<<"\n";
    if(ans.size() == n) return 0;
    Rep(i,1,n){
        if(now>=0 && ans[now]==i){
            now--; continue;
        }
        cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}
