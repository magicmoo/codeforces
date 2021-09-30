#include<bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
#define CAS int CASE;  \
=======
#define CAS ll CASE;  \
>>>>>>> cfddb953762c7216ccb8bf29c2fe869489363a85
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
<<<<<<< HEAD
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 5e5+5;
int a[maxn],b[maxn];
int main(){
    IOS;
    int n,m,k;
    cin>>n>>m>>k;
    Rep(i,1,n) cin>>a[i];
    Rep(i,1,m) cin>>b[i];
    
=======
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 5e5+5;
ll a[maxn],b[maxn];
ll exgcd(ll a,ll b,ll &x,ll &y) {
	if(b == 0) {
		x = 1,y = 0;
		return a;
	}
	else {
		ll res = exgcd(b,a%b,x,y);
		ll t = x;
		x = y;
		y = t - a / b * y;
		return res;
	}
}
ll excrt(ll m1,ll m2,ll a1,ll a2) {//解决模数不互质的情况
	ll x,y,c,g;
	c = a2 - a1;
	g = exgcd(m1,m2,x,y);
	x = x * c / g;//把方程右侧化为
	y = m2 / g;
	x = (x % y + y) % y;//求最小正整数解
	a1 = a1 + x * m1;
	m1 = m1 * m2 / g;
	return a1;//解x
}
/****************************/
ll n,m,k,Max;
ll cnt[maxn*2],book1[2*maxn],book2[2*maxn];
ll LCM;
bool check(ll num){
    ll ans = 0;
    Rep(i,1,Max){
        if(!cnt[i]) continue;
        ans += num/LCM;
        if(num%LCM>=cnt[i]) ans++;
    }
    return num-ans>=k;
}
int main(){
    IOS;
    cin>>n>>m>>k;
    Rep(i,1,n){
        cin>>a[i];
        book1[a[i]] = i;
    }
    Rep(i,1,m){
        cin>>b[i];
        book2[b[i]] = i;
    }
    Max = 2*max(n,m);   
    ll g = __gcd(n,m);
    Rep(i,1,Max){
        if(!book1[i] || !book2[i]) continue;
        if(abs(book1[i]-book2[i])%g != 0) continue;
        cnt[i] = excrt(n,m,book1[i],book2[i]);
    }
    LCM = n/g*m;
    ll l = 1,r = Max*k;
    while(r-l > 1){
        ll mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    if(check(l)) cout<<l;
    else cout<<r;
>>>>>>> cfddb953762c7216ccb8bf29c2fe869489363a85
    return 0;
}