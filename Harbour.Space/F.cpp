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
const long long MAXN = 3e5+5;
const long long maxv = 2e5+5;
const int M = 3e5;
namespace A {
    ll t[M * 4];

    void update(int l, int r, ll x, int v = 1, int tl = 1, int tr = M) {
        if (l > r || tl > r || tr < l) {
            return;
        }

        if (l <= tl && tr <= r) {
            t[v] += x;
            return;
        }

        int mid = (tl + tr) >> 1;
        int c1 = (v << 1), c2 = (c1 | 1);

        update(l, r, x, c1, tl, mid);
        update(l, r, x, c2, mid + 1, tr);
    }

    ll get(int p, int v = 1, int tl = 1, int tr = M) {
        if (tl == tr) {
            return t[v];
        }

        int mid = (tl + tr) >> 1;
        int c1 = (v << 1), c2 = (c1 | 1);

        if (p <= mid) {
            return t[v] + get(p, c1, tl, mid);
        }
        else {
            return t[v] + get(p, c2, mid + 1, tr);
        }
    }
}

namespace B {
    ll t[M * 4];

    void update(int p, ll x, int v = 1, int tl = 1, int tr = M) {
        if (tl == tr) {
            t[v] += x;
            return;
        }

        int mid = (tl + tr) >> 1;
        int c1 = (v << 1), c2 = (c1 | 1);

        if (p <= mid) {
            update(p, x, c1, tl, mid);
        }
        else {
            update(p, x, c2, mid + 1, tr);
        }

        t[v] = t[c1] + t[c2];
    }

    ll get(int l, int r, int v = 1, int tl = 1, int tr = M) {
        if (l > r || tl > r || tr < l) {
            return 0ll;
        }

        if (l <= tl && tr <= r) {
            return t[v];
        }

        int mid = (tl + tr) >> 1;
        int c1 = (v << 1), c2 = (c1 | 1);

        return get(l, r, c1, tl, mid) + get(l, r, c2, mid + 1, tr);
    }
}

long long a[maxv],pre[maxv],ans[maxv];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    long long n;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    Rep(i,1,n) pre[i] = pre[i-1]+a[i];
    // A::build(3e5);
    // B::build(3e5);
    const ll M = 3e5;
    Rep(i,1,n){
        long long temp1 = (i-1)*a[i],temp2 = pre[i-1];
        long long cnt = 1;
        temp1 -= A::get(a[i]);
        for(int j=a[i];j<=3e5;j+=a[i]){
            ll r = min(M,j+a[i]-1);
            A::update(j,r,a[i]*cnt);
            temp2 -= B::get(j,r)*cnt*a[i];
            cnt++;
        }
        B::update(a[i],1);
        ans[i] = ans[i-1]+temp1+temp2;
    }
    Rep(i,1,n) cout<<ans[i]<<" ";
    return 0;
}
