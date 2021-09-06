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
// #include<map>
#include<queue>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
const int mod = 998244353;
int a[maxn],b[maxn];
int l[maxn],r[maxn],map[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,k;
    CAS {
        cin>>n>>k;
        for(int i=1;i<=n;i++) l[i] = r[i] = map[i] = 0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=k;i++) cin>>b[i];
        for(int i=2;i<=n;i++) l[a[i]] =  a[i-1];
        for(int i=1;i<n;i++) r[a[i]] = a[i+1];
        ll ans = 1;
        for(int i=1;i<=k;i++) map[b[i]] = 1;
        for(int i=1;i<=k;i++){
            int temp = 0;
            if(l[b[i]] && !map[l[b[i]]]) temp++;
            if(r[b[i]] && !map[r[b[i]]]) temp++;
            ans *= temp;
            ans %= mod;
            map[b[i]] = 0;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
