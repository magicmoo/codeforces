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
struct Node{
    ll data;
    ll index;
}maxsum[maxn][20];
ll a[maxn],sum[maxn];
void RMQ(ll num){
    for(ll i=1;i<=num;i++){
        maxsum[i][0].data = sum[i];
        maxsum[i][0].index = i;
    }
    for(ll j=1;j<20;j++){
        for(ll i=1;i<=num;i++){
            if(i+ (1<<j) - 1 <= num){
                maxsum[i][j].data = max(maxsum[i][j-1].data,maxsum[i+(1<<(j-1))][j-1].data);
                if(maxsum[i][j].data == maxsum[i][j-1].data) maxsum[i][j].index = maxsum[i][j-1].index;
                else maxsum[i][j].index = maxsum[i+(1<<(j-1))][j-1].index;
            }
        }
    }
}
void Query(ll l,ll r,ll& maxl,ll& maxi){
    ll k = (ll)(log(r-l+1)/log(2.0));
    maxl = max(maxsum[l][k].data,maxsum[r-(1<<k)+1][k].data);
    if(maxl == maxsum[l][k].data) maxi = maxsum[l][k].index;
    else maxi = maxsum[r-(1<<k)+1][k].index;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,n,m,b;
    cin>>T; while(T--){
        ll ans = 0;
        cin>>n>>m;
        for(ll i=1;i<=n;i++) cin>>a[i];
        for(ll i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
        RMQ(n);
        while(m--){
            ans = 0;
            cin>>b;
            ll l = 1,r = n,maxl,maxi;
            Query(l,r,maxl,maxi);
            if(maxl<b && sum[n]<=0){
                cout<<"-1 "; continue;
            }else if(maxl < b){
                ans = (b-maxl+sum[n]-1)/sum[n]*n;
                b -= (b-maxl+sum[n]-1)/sum[n]*sum[n];
            }
            r = maxi - 1;
            while(l <= r){
                ll mid = (l+r)>>1;
                ll templ,tempi;
                Query(l,mid,templ,tempi);
                if(templ >= b){
                    r = mid-1;
                    maxi = tempi;
                }
                else l = mid+1;
            }
            cout<<ans+maxi-1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
