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
const int maxn = 3e5+5;
char a[maxn];
int pre[maxn],dp[maxn];
vector<int> v[maxn];
int main(){
    IOS;
    int n,q,l,r;
    CAS {
        cin>>n>>q;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,n){
            pre[i] = pre[i-1];
            if(i%2==1){
                if(a[i] == '+') pre[i]++;
                else pre[i]--;
            }
            if(i%2==0){
                if(a[i] == '-') pre[i]++;
                else pre[i]--;
            }
        }
        Rep(i,1,n) v[i].clear();
        Rep(i,1,n){
            v[pre[i]].push_back(i);
        }
        Rep(i,1,n){
            auto index = upper_bound(v[pre[i-1]].begin(),v[pre[i-1]].end(),i);
        }
        while(q--){
            cin>>l>>r;
            int now = l;
        }
    }
    return 0;
}
