
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
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 2e5+5;
ll gcd(ll a,ll b){ return a%b?gcd(b,a%b):b; }

ll a[maxn],b[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<m;i++) cin>>b[i];
    ll num = 0;
    sort(a,a+n);
    for(int i=1;i<n;i++){
        num = __gcd(num,a[i]-a[0]);
    }
    for(ll i=0;i<m;i++){
        cout<<__gcd(num,a[0]+b[i])<<" ";
    }
    return 0;
}
