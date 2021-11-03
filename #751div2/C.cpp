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
const int maxn = 2e5+5;
int a[maxn],cnt[40];
vector<int> ans;
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        ans.clear();
        Rep(i,0,30) cnt[i] = 0;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,n){
            Rep(j,0,30){
                if(((a[i]>>j)&1) == 1) cnt[j]++;
            }
        }
        Rep(i,1,n){
            bool flag = 1;
            Rep(j,0,30){
                if(cnt[j]%i != 0) flag = 0;
            }
            if(flag) ans.push_back(i);
        }
        rep(i,0,ans.size()) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
