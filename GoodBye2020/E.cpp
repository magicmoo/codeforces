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
const ll maxn = 5e5+5;
const ll mod = 1e9+7;
const ll maxv = 60;

ll x[maxn];
// bool num[maxn][maxv];
ll sum[maxv],ans1[maxv],ans2[maxv];
ll cal(ll a[]){
    ll ans = 0;
    ll n = 1;
    for(ll i=0;i<maxv;i++){
        ans += n%mod*a[i]%mod;
        ans %= mod;
        n *= 2;
    }
    return ans;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    ll T,n,num1,num2,i,j,now;
    cin>>T;
    while(T--){
        // memset(num,0,sizeof(num));
        memset(sum,0,sizeof(sum));
        cin>>n;
        ll ans = 0;
        for(i=0;i<n;i++) cin>>x[i];
        // for(i=0;i<n;i++){
        //     now = 0;
        //     while(x[i]){
        //         num[i][now] = x[i]%2;
        //         now++;
        //         x[i] /= 2;
        //     }
        // }
        for(i=0;i<n;i++){
            for(j=0;j<maxv;j++){
                // sum[i] += num[j][i];
                if(1LL << j & x[i]) sum[j]++;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<maxv;j++){
                if(1LL << j & x[i]){
                    ans1[j] = sum[j];
                    ans2[j] = n;
                }else{
                    ans1[j] = 0;
                    ans2[j] = sum[j];
                }
            }
            num1 = cal(ans1)%mod;
            num2 = cal(ans2)%mod;
            ans += num1*num2%mod;
            ans = ans%mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
