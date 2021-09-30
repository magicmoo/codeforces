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
int book[maxn],book2[maxn];
int n,d;
vector<int> v;
int find(int now){
    while(!book2[now]){
        if(a[now] == 0) return now;
        book2[now] = 1;
        now = (now+n-d)%n;
    }
    return -1;
}
int main(){
    IOS;
    CAS {
        cin>>n>>d;
        rep(i,0,n) cin>>a[i];
        rep(i,0,n) book2[i] = book[i] = 0;
        int g = __gcd(n,d);
        v.clear();
        int ans = 0;
        bool flag = 1;
        rep(i,0,n){
            if(book[i]) continue;
            int now = find(i);
            if(now == -1){
                flag = 0;
                break;
            }
            int cnt = 0;
            while(!book[now]){
                book[now] = 1;
                if(a[now]==0) cnt = 0;
                else ans = max(ans,++cnt);
                now = (now+n-d)%n;
            }
        }
        if(flag) cout<<ans<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}
