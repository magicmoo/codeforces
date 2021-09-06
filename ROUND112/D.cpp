#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
#define Rep(i,x,y) for(auto i=(x);i<=(y);i++)
#define rep(i,x,y) for(auto i=(x);i<(y);i++)
#define Dep(i,x,y) for(auto i=(x);i>=(y);i--)
#define dep(i,x,y) for(auto i=(x);i>(y);i--)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 2e5+5;
ll num[5][5][maxn],book[5];
void dfs(ll now,ll sum,ll& ans,ll l,ll r){
    if(now == 3){
        ans = min(ans,r-l+1-sum);
        return;
    }
    rep(i,0,3){
        if(book[i]) continue;
        book[i] = 1;
        dfs(now+1,sum+num[now][i][r]-num[now][i][l-1],ans,l,r);
        book[i] = 0;
    }
}
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,m,l,r;
    char str[maxn];
    cin>>n>>m;
    scanf("%s",str+1);
    Rep(i,1,n){
        rep(k,0,3) rep(j,0,3) num[k][j][i] = num[k][j][i-1];
        num[i%3][str[i]-'a'][i]++;
    }
    while(m--){
        scanf("%d%d",&l,&r);
        ll ans = INF;
        dfs(0,0,ans,l,r);
        cout<<ans<<"\n";
    }
    return 0;
}
