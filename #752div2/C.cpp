#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
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
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e5+5;
ll a[maxn];
const ll maxv = 1e5+5; //注意修改maxv数值
ll vis[maxv],prime[maxv],tol;
void liner_shai(){
    memset(vis,0,sizeof(vis));
    for(ll i=2;i<maxv;i++){
        if(!vis[i])
            prime[tol++] = i;
        for(ll j=0;j<tol&&i*prime[j]<maxv;j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0)
                break;
        }
    }
}
ll book[maxn];
int main(){
    IOS;
    ll n;
    liner_shai();
    CAS {
        cin>>n;
        Rep(i,0,1000) book[i] = 0;
        Rep(i,1,n) cin>>a[i];
        // Rep(i,1,n) a[i] = i;
        ll last = 1,now = 0;
        bool flag = 1;
        Rep(i,1,n){
            // cout<<i<<" "<<last<<"\n";
            ll cnt = i+1;
            for(ll j=0;j<tol&&prime[j]*prime[j]<=cnt;j++){
                ll num = 0;
                while(cnt%prime[j]==0){
                    num++;
                    cnt /= prime[j]; 
                }
                if(num>book[j]){
                    last *= prime[j];
                    book[j] = num;
                }
                if(last>1e9) break;
            }
            if(cnt!=1 && book[cnt]==0){
                last *= cnt;
                book[cnt] = 1;
            }
            if(last>1e9) break;
            if(a[i]%last == 0){
                flag = 0;
                break;
            }
        }
        YON;
    }
    return 0;
}
