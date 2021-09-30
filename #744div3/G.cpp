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
const int maxn = 1e4+5;
const int maxv = 1e3+5;
int a[maxn];
int dp[2][maxv*2];
pair<int,int> ans[2][maxv*2];
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        memset(dp[0],0,sizeof(dp[0]));
        dp[0][1000] = 1;
        ans[0][1000] = {1000,1000};
        Rep(j,1,n){
            Rep(i,0,2e3){
                if(!dp[0][i]) continue;
                if(i+a[j] <= 2e3){
                    dp[1][i+a[j]] = 1;
                    ans[1][i+a[j]] = {ans[0][i].first,max(ans[0][i].second,i+a[j])};
                }
                if(i-a[j] >= 0){
                    pair<int,int> tmp = {min(ans[0][i].first,i-a[j]),ans[0][i].second};
                    if(!dp[1][i-a[j]] || tmp.second-tmp.first<ans[1][i].second-ans[1][i].first){
                        ans[1][i-a[j]] = tmp;
                    }
                    dp[1][i-a[j]] = 1;
                }
            }
            Rep(i,0,2e3){
                dp[0][i] = dp[1][i];
                dp[1][i] = 0;
                ans[0][i] = ans[1][i];
                ans[1][i] = {0,0};
            }
        }
        int cnt = INF;
        Rep(i,0,2e3){
            if(!dp[0][i]) continue;
            cnt = min(cnt,ans[0][i].second-ans[0][i].first);
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
