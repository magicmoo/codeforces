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
const ll maxn = 3e5+5;
ll a[maxn],dp[maxn];
int main(){
    IOS;
    ll n;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    Rep(i,2,n) dp[i] = i-1;
    dp[0] = -1;
    stack<pair<ll,ll>> s1,s2;
    Rep(i,1,n){
        dp[i] = dp[i-1]+1;
        while(!s1.empty() && a[i]<s1.top().first){
            dp[i] = min(dp[i],dp[s1.top().second]+1);
            s1.pop();
        }
        if(!s1.empty()){
            dp[i] = min(dp[i],dp[s1.top().second]+1);
        }
        while(!s1.empty() && a[i]==s1.top().first) s1.pop();
        s1.push({a[i],i});
        while(!s2.empty() && a[i]>s2.top().first){
            dp[i] = min(dp[i],dp[s2.top().second]+1);
            s2.pop();
        }
        if(!s2.empty()) dp[i] = min(dp[i],dp[s2.top().second]+1);
        while(!s2.empty() && a[i]==s2.top().first) s2.pop();
        s2.push({a[i],i});
    }
    
    cout<<dp[n]<<"\n";
    return 0;
}