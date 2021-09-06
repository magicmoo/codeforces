#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MAXN = 3e5+5;
int a[MAXN];
vector<int> v[MAXN];
struct Node{
    int l,r;
    int lazy,sum;
    int a=1;
}Sum[MAXN<<2]; //树
int num[MAXN]; //原数组(下标从1开始)
int find(int num,int l,int r){
    int ll = lower_bound(v[num].begin(),v[num].end(),l)-v[num].begin();
    int rr = upper_bound(v[num].begin(),v[num].end(),r)-v[num].begin();
    return rr-ll;
}
void update(int index){    //区间和计算函数
    int ll = find(Sum[index<<1].sum,Sum[index].l,Sum[index].r);
    int rr = find(Sum[index<<1|1].sum,Sum[index].l,Sum[index].r);
    if(ll > rr){
        Sum[index].sum = Sum[index<<1].sum;
        Sum[index].a = ll;
    }else{
        Sum[index].sum = Sum[index<<1|1].sum;
        Sum[index].a = rr;
    }
}

void build(int l,int r,int index){     //建树[l，r]区间，当前下标为index
    Sum[index].l = l; Sum[index].r = r;
    Sum[index].lazy = 0;
    if(l == r){ Sum[index].sum = num[l]; return; }
    int m = (l+r)>>1;
    build(l,m,index<<1);
    build(m+1,r,index<<1|1);
    update(index);
}

void build(int size){    //建树对外接口
    build(1,size,1);
}

void change1(int index,int sign,int n){    //单点修改,index为当前树数组下标
    int l = Sum[index].l, r = Sum[index].r;
    if(l==r && l==sign){ Sum[index].sum = n; return; }
    int m = (l+r)>>1;
    if(sign <= m) change1(index<<1,sign,n);
    else change1(index<<1|1,sign,n);
    update(index);
}

void change(int sign,int n){         //单点修改对外接口，sign为修改下标，n为修改后的数
    change1(1,sign,n);
}

void change2(int index,int ll,int rr,int n){   //区间修改,将[ll,rr]内的数加n
    int l = Sum[index].l, r = Sum[index].r;
    int m = (l+r)>>1;
    if(l==ll && r==rr){
        Sum[index].sum += n*(rr-ll+1);
        Sum[index].lazy += n;
        return;
    }
    if(rr>m && ll<=m){
        change2(index<<1,ll,m,n); change2(index<<1|1,m+1,rr,n);
    }else if(rr<=m){
        change2(index<<1,ll,rr,n);
    }else{
        change2(index<<1|1,ll,rr,n);
    }
    update(index);
}

void pushdown(int index){   //将下标为index的结点的懒惰标记向下传播
    int l = Sum[index<<1].l, r=Sum[index<<1].r;
    Sum[index<<1].sum += (r-l+1)*Sum[index].lazy;
    Sum[index<<1].lazy += Sum[index].lazy;
    l = Sum[index<<1|1].l; r=Sum[index<<1|1].r;
    Sum[index<<1|1].sum += (r-l+1)*Sum[index].lazy;
    Sum[index<<1|1].lazy += Sum[index].lazy;
    Sum[index].lazy = 0;
}

pair<int,int> query2(int index,int ll,int rr){  //区间查找
    int ans = 0;
    int l = Sum[index].l, r = Sum[index].r;
    pushdown(index>>1);
    if(l==ll && r==rr) return {Sum[index].sum,Sum[index].a};
    int m = (l+r)>>1;
    if(rr>m && ll<=m){
        pair<int,int> p1 = query2(index<<1,ll,m),p2 = query2(index<<1|1,m+1,rr);
        if(p1.first == p2.first) return {p1.first,p1.second+p2.second};
        int aa = find(p1.first,ll,rr), bb = find(p2.first,ll,rr);
        if(aa >= bb) return {p1.first,aa};
        else return {p2.first,bb};
    }else if(rr<=m){
        return query2(index<<1,ll,rr);
    }else{
        return query2(index<<1|1,ll,rr);
    }
}

int query(int ll,int rr){  //区间查找对外接口
    return query2(1,ll,rr).first;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,q,l,r;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=n;i++){
        v[num[i]].push_back(i);
    }
    build(n);
    while(q--){
        cin>>l>>r;
        int a = query(l,r);
        int len = r-l+1;
        a = find(a,l,r);
        // cout<<a<<"\n";
        if(a<=(len+1)/2) cout<<"1\n";
        else cout<<(len-(len-a)*2)<<"\n";
    }
    return 0;
}
