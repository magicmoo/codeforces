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
const ll maxn = 2e5+5;
ll u[maxn],s[maxn];
vector<ll> v[maxn];
vector<ll> pre[maxn];
pair<ll,ll> p[maxn];
bool cmp(ll a,ll b){
    return a>b;
}
bool cmp2(pair<ll,ll> a,pair<ll,ll> b){
    return a.first > b.first;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n;
    CAS {
        cin>>n;
        for(ll i=1;i<=n;i++){
            v[i].clear();
            pre[i].clear();
            pre[i].push_back(0);
            p[i] = make_pair(0,i);
        }
        for(ll i=1;i<=n;i++) cin>>u[i];
        for(ll i=1;i<=n;i++) cin>>s[i];
        for(ll i=1;i<=n;i++){
            v[u[i]].push_back(s[i]);
            p[u[i]].first++;
        }
        for(ll i=1;i<=n;i++) sort(v[i].begin(),v[i].end(),cmp);
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<v[i].size();j++){
                pre[i].push_back(pre[i][j]+v[i][j]);
            }
        }
        sort(p+1,p+1+n,cmp2);
        ll last = n,i,ans,num,now,cnt;
        for(i=1;i<=n&&last>0;i++){
            ans = 0;
            for(ll j=1;j<=last;j++){
                now = p[j].second; num = p[j].first;
                if(num < i){
                    last = j-1; break;
                }
                cnt = num/i*i;
                ans += pre[now][cnt];
            }
            cout<<ans;
            if(i != n) cout<<" ";
        }
        for(;i<=n;i++){
            cout<<"0";
            if(i != n) cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
