#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 2e18;

int main(){
    IOS;
    ll n,k,l1,l2,r1,r2;
    CAS {
        cin>>n>>k;
        cin>>l1>>r1;
        cin>>l2>>r2;
        ll last=0,cnt=0,dis=0;
        if(r1<r2){
            swap(l1,l2);
            swap(r1,r2);
        }
        if(l1>r2){
            last = l1-r2;
            dis = r1-l2;
        }else if(l1>=l2){
            cnt = r2-l1;
            dis = r1-l2;
        }else{
            cnt = r2-l2;
            dis = r1-l1;
        }
        ll sum = n*cnt,ans = INF,kk = 0;
        if(sum>=k){
            cout<<"0\n";
            continue;
        }
        Rep(i,1,n){
            if(dis-cnt+sum >= k){
                ans = min(ans,kk+last+k-sum);
                break;
            }else{
                kk += last+dis-cnt;
                sum += dis-cnt;
                ans = min(ans,(k-sum)*2+kk);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
