#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 5e5+5;
int a[maxn],b[maxn];
set<int> s;
int dp[maxn],book[maxn];
int main(){
    IOS;
    int n,k;
    cin>>n>>k;
    Rep(i,1,n) cin>>a[i],a[i] -= i;
    Rep(i,1,k) cin>>b[i];
    Rep(i,1,k) s.insert(b[i]);
    bool flag = 1;
    int ans = 0;
    Rep(i,1,n) dp[i] = INF;
    int cnt = 0;
    dp[0] = -INF;
    Rep(i,1,n){
        int index = upper_bound(dp,dp+cnt+1,a[i])-dp;
        if(s.count(i)){
            if(book[index]){
                flag = 0;
                break;
            }
            dp[index] = a[i];
            book[index] = 1;
            cnt = index;
        }else{
            if(book[index]) continue;
            dp[index] = a[i];
            cnt = max(index,cnt);
        }
    }
    Rep(i,1,n){
        if(dp[i] != INF) ans = i;
    }
    if(flag) cout<<n-ans<<"\n";
    else cout<<"-1\n";
    return 0;
}
