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
int m,d,w;
const int maxv = 1e5; //注意修改maxv数值
int vis[maxv],prime[maxv],tol;
void liner_shai(){
    memset(vis,0,sizeof(vis));
    for(int i=2;i<maxv;i++){
        if(!vis[i])
            prime[tol++] = i;
        for(int j=0;j<tol&&i*prime[j]<maxv;j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0)
                break;
        }
    }
}
int main(){
    IOS;
    liner_shai();
    CAS {
        cin>>m>>d>>w;
        int Max = min(m,d);
        for(int i=0;i<tol&&prime[i]*prime[i]<=min(d,w);i++){
            while(d%prime[i]==0 && w%prime[i]==0){
                d /= prime[i];
                w /= prime[i];
            }
        }
        if(w == 1){
            cout<<Max*(Max-1)/2<<"\n";
        }else{
            ll ans = 0;
            for(int i=w;i<Max;i+=2){
                ans += (Max-i);
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
