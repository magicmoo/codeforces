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
const ll MAXN = 1e5+5;
ll a[MAXN],pre[MAXN],book[MAXN],dp[MAXN][50];
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
vector<ll> v[MAXN];
void cal(ll now,ll index){
    if(now == 0) return;
    bool flag = true;
    for(ll i=0;i<v[now].size();i++){
        if(book[v[now][i]]) flag = false;
    }
    if(flag){
        for(ll i=0;i<v[now].size();i++) book[v[now][i]]++;
        pre[now] = index;
        cal(now-1,index);
    }else{
        for(ll i=0;i<v[index].size();i++) book[v[index][i]]--;
        cal(now,index-1);
    }
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,q,l,r;
    cin>>n>>q;
    for(ll i=1;i<=n;i++) cin>>a[i];
    liner_shai();
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<tol&&prime[j]*prime[j]<=a[i];j++){
            if(a[i]%prime[j] == 0) v[i].push_back(prime[j]);
            while(a[i]%prime[j] == 0) a[i] /= prime[j];
        }
        if(a[i] != 1) v[i].push_back(a[i]);
    }
    cal(n,n);
    for(int i=1;i<=n;i++) dp[i][0] = pre[i]+1;
    for(int j=1;;j++){
        for(int i=1;i<=n;i++){
            if(dp[i-1][j] > n) dp[i][j] = n+1;
            else dp[i][j] = dp[dp[i][j-1]][j-1];
        }
        if(dp[1][j] > n) break;
    }
    // for(ll i=1;i<=n;i++) cout<<pre[i]<<" ";
    while(q--){
        cin>>l>>r;
        int ans = 0,now = l;
        while(now <= r){
            if(dp[now][0] > r){
                ans++;
                break;
            }
            for(int i=1;;i++){
                if(dp[now][i] > r){
                    ans += (1<<(i-1));
                    now = dp[now][i-1];
                    break;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
