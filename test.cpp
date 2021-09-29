#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define MP make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define lson rt<<1
#define rson rt<<1|1
typedef long long ll;
typedef double db;
const int INF = 0x3f3f3f3f;
const db eps = 1e-6;
const int MAXN = 5e5 + 7;
ll n,m,k;
int p1[MAXN<<1],p2[MAXN<<1];//2 * max(n,m) 一个序列里面的数都不同保证了每一个数位置的唯一性
//二分 + crt
/************exCRT*************/
ll gcd(ll a,ll b) {
	return b == 0 ? a : gcd(b,a%b);
}
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
ll crt[MAXN<<1],LCM;

bool check(ll x) {
	ll sum = 0,ma = 2 * max(n,m);
	for(int i = 1;i <= ma;i ++) {
		if(!p1[i] || !p2[i]) continue;
		if(!crt[i] || x < crt[i]) continue;//别越界
		//x通解 x = x0 + lcm(m1,m2);
		sum += (x - crt[i]) / LCM + 1;//看看后面还有几个通解
		if(x - sum < k) return false;
	}
	return x - sum >= k;//总为x天，其中sum天相同，则x - sum天不同
}

int main() {
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i = 1,x;i <= n;i ++) {
		scanf("%d",&x);
		p1[x] = i;
	}
	for(int i = 1,x;i <= m;i ++) {
		scanf("%d",&x);
		p2[x] = i;
	}
	ll ma = 2 * max(n,m),g = gcd(n,m);
	for(int i = 1;i <= ma;i ++) {//求解每一个值的最小出现的位置在哪
		if(!p1[i] || !p2[i]) continue;
		if(abs(p1[i]-p2[i]) % g != 0) continue;
		crt[i] = excrt(n,m,p1[i],p2[i]);//存的是相等的值出现的位置
	}
	LCM = n * m / g;
	ll l = 1,r = ma * k,ans;//ma * k就是相等比较多的极端情况
	while(l <= r) {
		ll mid = (l + r) >> 1;
		if(check(mid)) {
			ans =  mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%lld\n",ans);
	return 0;
}