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
char a[maxn],b[maxn];
int main(){
    // IOS;
    int n;
    scanf("%d",&n);
    scanf("%s",a+1);
    scanf("%s",b+1);
    int cnt = 0;
    Rep(i,1,n) cnt += a[i]-'0';
    Rep(i,1,n) cnt -= b[i]-'0';
    if(cnt){
        cout<<"-1\n";
        return 0;
    }
    int ans = 0;
    cnt = 0;
    int cnt1 = 0,cnt2 = 0;
    Rep(i,1,n){
        if(a[i] == b[i]) continue;
        if(a[i]=='1'){
            cnt++;
            cnt1 = max(cnt,cnt1);
        }
        else{
            cnt--;
            cnt2 = min(cnt2,cnt);
        }
    }
    ans = cnt1-cnt2;
    cout<<ans<<"\n";
    return 0;
}
