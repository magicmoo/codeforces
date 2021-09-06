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

ll a[maxn];
ll pre[maxn],post[maxn];

bool check(ll a,ll b,ll c,ll d){
    if(a<0 || b<0 || c<0 || d<0) return false;
    if(b<a || c<d) return false;
    if(b-a == c-d) return true;
    return false;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    ll T,n;
    cin>>T;
    while(T--){
        int lazy1 = 0,lazy2 = 0;
        memset(post,0,sizeof(post)); memset(pre,0,sizeof(pre));
        cin>>n;
        for(ll i=1;i<=n;i++) cin>>a[i];
        for(ll i=1;i<=n;i++){
            if(pre[i-1] < 0) pre[i] = -1;
            else pre[i] = a[i]-pre[i-1];
        }
        for(ll i=n;i>0;i--){
            if(post[i+1] < 0) post[i] = -1;
            else post[i] = a[i]-post[i+1];
        }
        if(check(0,a[1],a[2],post[3])){
            cout<<"YES\n"; continue;
        }
        bool flag = false;
        for(ll i=1;i<n;i++){
            if(check(pre[i-1],a[i+1],a[i],post[i+2])){
                cout<<"YES\n"; flag = true; break;
            }
        }
        if(!flag) cout<<"NO\n";
    }
    return 0;
}
