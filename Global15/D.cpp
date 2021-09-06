#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
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
const int INF = 0x3f3f3f3f;
const int maxn = 15;
int a[maxn],b[maxn],n;
bool flag = false;
void dfs(int now,int sum){
    if(now == n){
        if(sum == a[n]) flag = true;
        return;
    }
    dfs(now+1,sum);
    dfs(now+1,sum+a[now]);
    dfs(now+1,sum-a[now]);
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS{
        flag = false;
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,n){
            swap(a[i],a[n]);
            dfs(1,0);
            swap(a[i],a[n]);
        }
        YON;
    }
    return 0;
}
