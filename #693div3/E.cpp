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
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;

struct node{
    int big;
    int small;
    int i;
};
bool cmp(node a,node b){
    if(a.big != b.big) return a.big>b.big;
    else return a.small>b.small;
}   
node a[maxn];
int dp[maxn];
int dp_ans[maxn];
int ans[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n,w,h;
    cin>>T;
    while(T--){
        memset(ans,0,sizeof(ans));
        memset(dp,0,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>w>>h;
            a[i].big = max(w,h);
            a[i].small = min(w,h);
            a[i].i = i;
        }
        sort(a+1,a+n+1,cmp);
        dp[n] = INF;
        for(int i=n-1;i>0;i--){
            if(a[i+1].small < dp[i+1]){
                dp_ans[i] = i+1;
                dp[i] = a[i+1].small;
            }else{
                dp_ans[i] = dp_ans[i+1];
                dp[i] = dp[i+1];
            }
        }
        int now = n;
        for(int i=n-1;i>0;i--){
            if(a[i].big != a[now].big) now = i;
            if(a[i].small>dp[now]) ans[a[i].i] = a[dp_ans[now]].i;
            else ans[a[i].i] = 0;
        }
        for(int i=1;i<=n;i++){
            if(ans[i] == 0) cout<<"-1 ";
            else cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
