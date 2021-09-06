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
const ll maxv = 1e3; //注意修改maxv数值
ll vis[maxv],prime[maxv],tol;
void liner_shai(){
    memset(vis,0,sizeof(vis));
    for(ll i=2;i<maxv;i++){
        if(!vis[i])
            prime[tol++] = i;
        for(ll j=0;j<tol&&i*prime[j]<maxv;j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0)
                break;
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i=1;i<n;i++){
        if(__gcd(i,n) == 1) v.push_back(i);
    }
    ll ans = 1;
    for(ll i=0;i<v.size();i++){
        ans *= v[i];
        ans %= n;
    }
    if(ans==1) cout<<v.size()<<"\n";
    else cout<<v.size()-1<<"\n";
    for(ll i=0;i<v.size();i++){
        if(ans!=1 && v[i]==ans) continue;
        else cout<<v[i]<<" ";
    }
    return 0;
}
