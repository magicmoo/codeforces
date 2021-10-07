#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
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
const ll INF = 0x3f3f3f3f;
const ll mod = 1e9+7;
ll n;
const ll maxn = 2e5+5;
ll a[maxn];
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
    IOS;
    a[1] = 1;
    Rep(i,2,2e5){
        a[i] = (a[i-1]*i)%mod;
    }
    CAS {
        cin>>n;
        cout<<(a[2*n]*inv(2,mod))%mod<<"\n";
    }
    return 0;
}
