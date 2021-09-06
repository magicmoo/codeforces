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
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 1e13;
const ll maxn = 2e5+5;
ll a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,ans = 0;
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i];
    priority_queue<ll> p;
    ll sum = 0;
    for(ll i=1;i<=n;i++){
        if(a[i]>=0){
            sum += a[i];
            ans++;
        }else if(sum+a[i]>=0){
            sum += a[i];
            ans++;
            p.push(-a[i]);
        }else{
            if(!p.empty() && -a[i] < p.top()){
                sum = sum+p.top()+a[i];
                p.pop();
                p.push(-a[i]);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
