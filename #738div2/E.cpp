#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
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
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int maxn = 55;
const int maxv = 1e5+5;
pair<int,int> a[maxn];
int dp[maxn][maxv];
vector<int> v[maxv];
int main(){
    IOS;
    int n,m;
    cin>>n>>m;
    Rep(i,1,n) cin>>a[i].first>>a[i].second;
    Rep(i,1,n){
        Rep(i,a[i].first,a[i].second){
            
        }
    }
    return 0;
}
