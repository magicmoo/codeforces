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
const int maxn = 1e6+5;
int a[maxn];
int dp[maxn];
int n,d;
vector<int> v;
void init(){
    int now = 0;
    while(now != 0){
        now = (now+n-d)%n;
        v.push_back(now);
    }
}
int main(){
    IOS;
    CAS {
        cin>>n>>d;
        rep(i,0,n) cin>>a[i];
        int g = __gcd(n,d);
        v.clear();
        init();
    }
    return 0;
}
