#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS ll CASE; \
            cin>>CASE; \
            Rep(__,1,CASE)
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const ll INF = 0x3f3f3f3f;
const ll mod = 998244353;
const ll maxn = 2e5+5;
ll a[maxn],pre[maxn];
ll quick_pow(ll a,ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1) ans=(a*ans)%m;
        a=(a*a)%m;
        b>>=1;
    }  
    return ans;
}
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
int main(){
    IOS;
    ll n;
    pre[0] = 1;
    Rep(i,1,2e5) pre[i] = (pre[i-1]*i)%mod;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        sort(a+1,a+1+n);
        ll ans = 1;
        if(a[n]>a[n-1]+1){
            cout<<"0\n";
        }else if(a[n]>a[n-1]){
            ll num = 1;
            Dep(i,n-2,1){
                if(a[i]==a[n-1]) num++;
                else break;
            }
            cout<<(pre[n]-(pre[num]*((pre[n]*inv(pre[num+1],mod))%mod))%mod+mod)%mod<<"\n";
        }else{
            cout<<pre[n]<<"\n";
        }
    }
    return 0;
}

//                    _ooOoo_
//                   o8888888o
//                   88" . "88
//                   (| -_- |)
//                   O\  =  /O
//                ____/`---'\____
//              .'  \\|     |//  `.
//             /  \\|||  :  |||//  \
//            /  _||||| -:- |||||-  \
//            |   | \\\  -  /// |   |
//            | \_|  ''\---/''  |   |
//            \  .-\__  `-`  ___/-. /
//          ___`. .'  /--.--\  `. . __
//       ."" '<  `.___\_<|>_/___.'  >'"".
//      | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//      \  \ `-.   \_ __\ /__ _/   .-` /  /
// ======`-.____`-.___\_____/___.-`____.-'======
//                    `=---='
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//             佛祖保佑      永无bug