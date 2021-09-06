#include<bits/stdc++.h>
using namespace std;
#define CAS long long CASE;  \
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
const long long INF = 0x3f3f3f3f;
const long long maxn = 2e5+5;
const long long MAXN = maxn;
long long a[maxn];
vector<long long> v;
struct Node{
    long long l,r;
    long long lazy,sum;
}Sum[MAXN<<2]; //树
long long num[MAXN]; //原数组(下标从1开始)

void update(long long index){    //区间和计算函数
    Sum[index].sum = __gcd(Sum[index<<1].sum,Sum[index<<1|1].sum);
}

void build(long long l,long long r,long long index){     //建树[l，r]区间，当前下标为index
    Sum[index].l = l; Sum[index].r = r;
    Sum[index].lazy = 0;
    if(l == r){ Sum[index].sum = num[l]; return; }
    long long m = (l+r)>>1;
    build(l,m,index<<1); build(m+1,r,index<<1|1);
    update(index);
}

void build(long long size){    //建树对外接口
    build(1,size,1);
}

long long query2(long long index,long long ll,long long rr){  //区间查找
    long long ans = 0;
    long long l = Sum[index].l, r = Sum[index].r;
    if(l==ll && r==rr) return Sum[index].sum;
    long long m = (l+r)>>1;
    if(rr>m && ll<=m){
        ans = __gcd(query2(index<<1,ll,m),query2(index<<1|1,m+1,rr));
    }else if(rr<=m){
        ans+=query2(index<<1,ll,rr);
    }else{
        ans+=query2(index<<1|1,ll,rr);
    }
    return ans;
}

long long query(long long ll,long long rr){  //区间查找对外接口
    return query2(1,ll,rr);
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    long long n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        if(n == 1){
            cout<<"1\n";
            continue;
        }
        rep(i,1,n) num[i] = abs(a[i+1]-a[i]);
        build(n-1);
        long long ans = 0,l = 1;
        rep(i,1,n){
            while(l<i && query(l,i)==1) l++;
            if(query(l,i) != 1) ans = max(ans,i-l+1);
        }
        cout<<ans+1<<"\n";
    }
    return 0;
}
