#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;
int a[maxn];
int main(){
    IOS;
    int n;
    int cnt = 1;
    int now = 1;
    while(cnt<=1000){
        if(now%3!=0 && now%10!=3) a[cnt++] = now;
        now++;
    }
    CAS {
        cin>>n;
        cout<<a[n]<<"\n";
    }
    return 0;
}
