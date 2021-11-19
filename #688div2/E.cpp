#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define PII pair<int,int>
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
vector<int> vec[maxn];
int dp1[maxn],dp2[maxn],ans;
void dfs(int now,int last){
    if(now!=1 && vec[now].size()==1){
        dp1[now] = dp2[now] = 0;
        ans = max(ans,dp1[now]);
        return;
    }
    dp1[now] = 0; dp2[now] = INF;
    for(auto nxt : vec[now]){
        if(nxt == last) continue;
        dfs(nxt,now);
        dp1[now] = max(dp2[nxt]+1,dp1[now]);
        dp2[now] = min(dp2[nxt]+1,dp2[now]);
    }
    if(now!=1) ans = max(ans,dp1[now]+1);
}
int main(){
    IOS;
    int n,l,r;
    CAS {
        ans = 0;
        cin>>n;
        Rep(i,1,n) vec[i].clear();
        Rep(i,1,n-1){
            cin>>l>>r;
            vec[l].push_back(r);
            vec[r].push_back(l);
        }
        dfs(1,-1);
        vector<int> v;
        for(auto nxt : vec[1]){
            v.push_back(dp2[nxt]+1);
        }
        sort(v.begin(),v.end());
        ans = max(ans,v.back());
        if(v.size()>1){
            ans = max(ans,v[v.size()-2]+1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
