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
const int maxn = 1e5+5;
pair<int,int> a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,k;
    CAS {
        cin>>n>>k;
        Rep(i,1,n) cin>>a[i].first,a[i].second = i;
        sort(a+1,a+1+n);
        int tmp = n;
        Rep(i,2,n){
            if(a[i].second == a[i-1].second+1) tmp--;
        }
        if(tmp <= k) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
