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
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll mod = 998244353;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0) {
        x=1,y=0;
        return a;
    }
    ll r = exgcd(b,a%b,x,y);
    ll t = x;
    x = y;
    y = t - a/b*y;
    return r;
}
ll inv(ll n,ll m)
{
    ll x,y;
    ll ans = exgcd(n,m,x,y);
    if(ans == 1)
        return (x%m+m)%m;
    //定义：正整数 a, n，如果有 ax ≡ 1(mod n)，则称 x 的最小整数解为 a 模 n的逆元。
    else
        return -1;
}
ll quick_pow(ll a,ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1) ans=(a*ans)%m;
        a=(a*a)%m;
        b>>=1;
    }  
    return ans;
}
const ll maxn = 3e5+5;
vector<char> v[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,m,w = 0;
    char ch;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        
        v[i].push_back('*');
        for(ll j=1;j<=m;j++){
            cin>>ch;
            v[i].push_back(ch);
        }
        v[i].push_back('*');
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(v[i][j] == 'o') w++;
        }
    }
    ll ans = 0;
    ll num = quick_pow(2,w,mod);
    for(ll i=1;i<=n;i++){
        ll last = 4;
        ll sum = 0;
        ll index = 1;
        for(ll j=1;j<m;j++){
            if(v[i][j] == '*' || v[i][j+1] == '*'){
                last = 4; sum = 0;
                continue;
            }
            sum += index*(num*inv(last,mod)+mod)%mod;
            last *= 2;
            sum = (sum)%mod; last %= mod;
            index = -index;
            ans += sum;
            ans = (ans+mod)%mod; 
        }
    }
    for(ll j=1;j<=m;j++){
        ll last = 4;
        ll sum = 0;
        ll index = 1;
        for(ll i=1;i<n;i++){
            if(v[i][j] == '*' || v[i+1][j] == '*'){
                last = 4; sum = 0;
                continue;
            }
            sum += index*(num*inv(last,mod)+mod)%mod;
            last *= 2;
            index = -index;
            sum = (sum)%mod; last %= mod;
            ans += sum;
            ans = (ans+mod)%mod; 
        }
    }
    // cout<<ans<<"\n";
    // cout<<quick_pow(2,300000,mod)<<"\n"
    cout<<ans<<"\n";
    return 0;
}
