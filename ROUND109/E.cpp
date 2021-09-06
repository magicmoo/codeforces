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
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn1 = 22;
const ll maxn2 = 5e4+5;
const ll mod = 998244353;
ll dis[maxn1][maxn2];
ll a[maxn1],val[maxn1];
ll lcm(ll a,ll b){ return a/__gcd(a,b)*b; }

int exgcd(int a,int b,int &x,int &y)
{
    if(b==0) {
        x=1,y=0;
        return a;
    }
    int r = exgcd(b,a%b,x,y);
    int t = x;
        x = y;
        y = t - a/b*y;
    return r;
}
int inv(int n,int m)
{
    int x,y;
    int ans = exgcd(n,m,x,y);
    if(ans == 1)
        return (x%m+m)%m;
    //定义：正整数 a, n，如果有 ax ≡ 1(mod n)，则称 x 的最小整数解为 a 模 n的逆元。
    else
        return -1;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>dis[i][j];
        }
    }
    val[1] = 1;
    for(ll i=2;i<=n;i++) val[i] = val[i-1]*i;
    ll ans = 0;
    for(ll i=1;i<=m;i++){
        ll now = 0,tmp = 1;
        for(ll j=1;j<=n;j++){
            if(dis[j][i] > n) continue;
            a[now++] = dis[j][i] - 1;
        }
        sort(a,a+now);
        for(ll j=0;j<now;j++){
            tmp *= (a[j]-j);
        }
        tmp *= val[n-now];
        ans += (val[n]-tmp);
        ans %= mod;
    }
    cout<<ans*inv(val[n]%mod,mod)%mod<<"\n";
    return 0;
}
