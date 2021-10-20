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
const int maxn = 1e3+5;
int dp[maxn],pre[maxn];
vector<int> vec;
int main(){
    IOS;
    int n,k;
    dp[0]=dp[1]=pre[0]=pre[1] = 1;
    CAS {
        vec.clear();
        cin>>n>>k;
        Rep(i,2,n){
            dp[i] = pre[i-1]+dp[i-2];
            pre[i] = pre[i-1]+dp[i];
        }
        if(k > pre[n]){
            cout<<"-1\n";
            continue;
        }
        int now = n;
        while(k>1){
            int index = lower_bound(dp+1,dp+now+1,k)-dp;
            k -= dp[index];
            Rep(i,n-now+1,n-index){
                vec.push_back(i);
            }
            vec.push_back(n-index+2);
            vec.push_back(n-index+1);
            now = n-index+3;
        }
        Rep(i,now,n){
            vec.push_back(i);
        }
        rep(i,0,vec.size()) cout<<vec[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
